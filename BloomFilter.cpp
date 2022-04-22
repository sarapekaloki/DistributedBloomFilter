#include "BloomFilter.h"
#include <iostream>

#include <vector>


using namespace std;

BloomFilter::BloomFilter(int numCells, vector<HashFunction> funcs){
    numOfCells = numCells;
    hashFunctions = funcs;
    filtro.resize(numCells,false);

}

vector<bool>BloomFilter::getFiltro(){
    return filtro;
}
void BloomFilter::changeBit(int index){
    filtro[index]=1;
    return;
}

void BloomFilter::add(string str){
    for (vector<HashFunction>::iterator i = hashFunctions.begin(); i != hashFunctions.end(); i++) {
        filtro[(*i)(str)] = true;
    }
}

bool BloomFilter::search(string str){
    bool inSet = true;
    for (vector<HashFunction>::iterator i = hashFunctions.begin(); i != hashFunctions.end(); i++) {
        if (filtro[(*i)(str)] == false) {
            inSet = false;
            break;
        }
    }
    return inSet;
}
void BloomFilter::print(){
    for (int i = 0; i < filtro.size(); i++) {
        cout << filtro[i]<<" ";
    }
    return;
}

BloomFilter::BloomFilter() {}
