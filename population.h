#include <bits/stdc++.h>
#include "chromosome.cpp"

using namespace std;
//
// Created by Alaa on ١٦/٠٥/٢٠٢١.
//

#ifndef ASSIGNMNT2_GENERATION_H
#define ASSIGNMNT2_GENERATION_H


class population {
    int popSize, len;
    vector<chromosome> pop;
    vector<long double> fit;
    int numberIterations;

    void generatePop(vector<pair<long double, long double>> &Points);

    void calcFit();

    int selection();

    bool mutation(vector<pair<long double, long double>> &Points, chromosome &child1, int curIteration);

    bool
    crossOver(vector<pair<long double, long double>> &Points, chromosome &child1, chromosome &child2, int curIteration);

    void getNew(vector<pair<long double, long double>> &Points, vector<chromosome> &newPop, int curIteration);

    static bool cmp(chromosome &c1, chromosome &c2) {
        return c1.Error > c2.Error;
    }

public:
    void process(vector<pair<long double, long double>> &Points);

    population(vector<pair<long double, long double>> &Points, int popSize, int len, int numberIterations);
};


#endif //ASSIGNMNT2_GENERATION_H
