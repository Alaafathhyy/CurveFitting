#include <bits/stdc++.h>

using namespace std;
//
// Created by Alaa on ١٦/٠٥/٢٠٢١.
//

#ifndef ASSIGNMNT2_CHROMOSOME_H
#define ASSIGNMNT2_CHROMOSOME_H


class chromosome {
    int len;


    void generateChrom();


public:
    explicit chromosome(vector<pair<long double, long double>> &Points, int sz) {
        len = sz;
        chrom.resize(len);
        this->generateChrom();
      calcError(Points);
    }

    long double Error = 0;

   void calcError(vector<pair<long double, long double>> &Points);

    vector<long double> chrom;
};


#endif //ASSIGNMNT2_CHROMOSOME_H
