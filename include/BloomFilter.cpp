#include "BloomFilter.h"
#include <iostream>

#include <vector>
#include <bitset>

using namespace std;

BloomFilter::BloomFilter(int numCells, vector<HashFunction> funcs){
    numOfCells = numCells;
    hashFunctions = funcs;


}

void BloomFilter::changeBit(int index){
    filter.set(index);
    return;
}

void BloomFilter::add(string str){
    for (vector<HashFunction>::iterator i = hashFunctions.begin(); i != hashFunctions.end(); i++) {
        int index = (*i)(str) %numOfCells;
        filter.set(index);
    }
}

bool BloomFilter::search(string str){
    bool inSet = true;
    for (vector<HashFunction>::iterator i = hashFunctions.begin(); i != hashFunctions.end(); i++) {
        if (filter[(*i)(str) %numOfCells] == false) {
            inSet = false;
            break;
        }
    }
    return inSet;
}
void BloomFilter::print(){
    for (int i = 0; i < filter.size(); i++) {
        cout << filter[i]<<" ";
    }
    return;
}


BloomFilter::BloomFilter() {}
