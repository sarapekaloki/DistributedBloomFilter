#ifndef BLOOMFILTER_BLOOMFILTER_H
#define BLOOMFILTER_BLOOMFILTER_H


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <bitset>



using namespace std;
typedef int (*HashFunction)(string);

class BloomFilter{
    int numOfCells;
    vector<HashFunction> hashFunctions;




public:
    BloomFilter(int numCells, vector<HashFunction> funcs);

    bitset<8000000> filter;

    BloomFilter();

    void add(string str);
    bool search(string str);
    void print();
    void changeBit(int index);

};


#endif //BLOOMFILTER_BLOOMFILTER_H
