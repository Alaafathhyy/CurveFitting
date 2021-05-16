//
// Created by Alaa on ١٦/٠٥/٢٠٢١.
//

#include "population.h"

void population::generatePop(vector<pair<long double, long double>> &Points) {
    for (int i = 0; i < popSize; ++i) {
        pop.emplace_back(Points,len);
    }
}

void population::calcFit() {
    fit.resize(popSize);
    for (int i = 0; i < popSize; ++i) {
        fit[i] = pop[i].Error;
        if (i)
            fit[i] += fit[i - 1];
    }
}

int population::selection() {
    long double val = (long double) rand() / RAND_MAX * fit[popSize - 1];
    int id = lower_bound(fit.begin(), fit.end(), val) - fit.begin();
    return (popSize <= id ? popSize - 1 : id);
}

bool population::mutation(vector<pair<long double, long double>> &Points, chromosome &child1, int curIteration) {
    if (rand() % 100 >= 20)
        return 1;
    for (int i = 0; i < len; i++) {
        int r = rand() % 101;
        long double y = child1.chrom[i];
        if (r <= 50)
            y = y + 10;
        else y = 10 - y;
        int nr = rand() % 2;
        y *= (1 - pow(nr, pow(1 - (double) numberIterations / curIteration, 2)));
        child1.chrom[i] += (r == 0 ? -1 : 1) * y;
    }

    return 1;
}

bool population::crossOver(vector<pair<long double, long double>> &Points, chromosome &child1, chromosome &child2,
                           int curIteration) {
    int p = rand() % 101;
    if (p <= 20)return 0;
    int id1 = selection(), id2 = selection();
    int r = rand() % len;
    chromosome parent1 = pop[id1], parent2 = pop[id2];
    for (int i = 0; i < len; ++i) {
        if (i <= r)
            child1.chrom[i] = parent1.chrom[i], child2.chrom[i] = parent2.chrom[i];
        else
            child1.chrom[i] = parent2.chrom[i], child2.chrom[i] = parent1.chrom[i];
    }
    mutation(Points, child1, curIteration), mutation(Points, child2, curIteration);
    return 1;
}

void population::getNew(vector<pair<long double, long double>> &Points, vector<chromosome> &newPop, int curIteration) {
    chromosome child1(Points,len), child2(Points,len);
    for (int i = 0; i < 200; ++i) {
        if (crossOver(Points, child1, child2, curIteration))
            child1.calcError(Points),child2.calcError(Points),newPop.push_back(child1), newPop.push_back(child2);
    }

}

void population::process(vector<pair<long double, long double>> &Points) {
    chromosome mnChrom(Points,len);
    vector<chromosome> curPop;
    for (int i = 0; i < numberIterations; ++i) {
        calcFit();
        for (auto &cur:pop) {
            if (cur.Error > mnChrom.Error)
                mnChrom = cur;
        }

        getNew(Points, curPop, i);

        pop.insert(pop.end(), curPop.begin(), curPop.end());


        sort(pop.begin(), pop.end(), cmp);

        while (pop.size() > popSize) {
            pop.pop_back();
        }
    }

    cout << "Error = " << 1 / mnChrom.Error << endl;
    for (int i = 0; i < len; i++) {
        cout << mnChrom.chrom[i] << " , ";
    }
    cout << endl << endl;

}

population::population(vector<pair<long double, long double>> &Points, int popSize, int len, int numberIterations) {
    this->len = len;
    this->popSize = popSize;
    generatePop(Points);
    this->numberIterations = numberIterations;
}
