
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

void BloomFilter::add(string str){
    for (vector<HashFunction>::iterator i = hashFunctions.begin(); i != hashFunctions.end(); i++) {
//            cout << str << (*i)(str) << "\n";
//            cout << str << (*i)(str) % numOfCells << "\n";
        filtro[(*i)(str) % numOfCells] = true;
    }
}

bool BloomFilter::search(string str){
    bool inSet = true;
    for (vector<HashFunction>::iterator i = hashFunctions.begin(); i != hashFunctions.end(); i++) {
        if (filtro[(*i)(str) % numOfCells] == false) {
            inSet = false;
            break;
        }
    }
    return inSet;
}
vector<bool> BloomFilter::print(){
    for (vector<bool>::iterator i = filtro.begin(); i != filtro.end(); i++) {
        cout << *i<<" ";
    }
}

BloomFilter::BloomFilter() {}
