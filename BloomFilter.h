#ifndef BLOOMFILTER_BLOOMFILTER_H
#define BLOOMFILTER_BLOOMFILTER_H


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>


using namespace std;
typedef int (*HashFunction)(string);
class BloomFilter{
    unsigned int numOfCells;
    vector<bool> filtro;
    vector<HashFunction> hashFunctions;


public:
    BloomFilter(int numCells, vector<HashFunction> funcs);

    BloomFilter();

    void add(string str);
    bool search(string str);
    void print();
    void changeBit(int index);
    vector<bool> getFiltro();
};


#endif //BLOOMFILTER_BLOOMFILTER_H
