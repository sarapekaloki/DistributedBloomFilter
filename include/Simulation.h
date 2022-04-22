//
// Created by Sara Marquez on 22/04/22.
//

#ifndef BLOOMFILTER_SIMULATION_H
#define BLOOMFILTER_SIMULATION_H


#include <iostream>

#include <vector>
#include <cmath>
#include "BloomFilter.h"
#include <algorithm>
using namespace std;
typedef int (*HashFunction)(string);


class Simulation{
    vector<string> data1;
    vector<string> data2;
    BloomFilter filter1;
    BloomFilter filter2;
public:
    Simulation( vector<string> vec1, vector<string> vec2, BloomFilter f1, BloomFilter f2);
    Simulation();
    void checkEquality();
    void addData(int index);
    void searchTest();


};

#endif //BLOOMFILTER_SIMULATION_H
