//
// Created by Alaa on ١٦/٠٥/٢٠٢١.
//

#include "chromosome.h"

void chromosome::generateChrom() {
    for (int i = 0; i < len; ++i) {
        chrom[i] = -10 + 20 * (long double) rand() / (double) RAND_MAX;
    }

}

void chromosome::calcError(vector<pair<long double, long double>> &Points) {
    long double error = 0;
    for (auto p:Points) {
        long double y = 0;
        long double x = 1;
        for (int i = 0; i < len; ++i) {
            y += x * chrom[i];
            x *= p.first;
        }

        error += (y - p.second) * (y - p.second);
    }
    this->Error= Points.size() / error;
}
