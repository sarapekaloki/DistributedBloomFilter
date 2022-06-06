
#include <iostream>
#include <vector>
#include "../include/BloomFilter.h"
#include "../include/read_Data.h"
#include "../include/universalHash.h"
using namespace std;

int sz=157;
void blockTest(int blocks){
    vector<HashFunction> v;
    HashFunction hash1 = h1;
    HashFunction hash2 = h3;
    v.push_back(hash1);
    v.push_back(hash2);
    vector<string> v1;

    string name;
    int cantData =50;
    int blockSize = (cantData)/blocks;
    vector<string> lookFor;
    BloomFilter fltr(sz,v);

    vector<string> data = getData(cantData);

    for (int i = 0; i < blocks; ++i) {
        int cont =0;
        lookFor.clear();
        fltr.filter.reset();
        while (cont< cantData){
            if(cont>=blockSize-((cantData)/blocks)  && cont<= blockSize){
                lookFor.push_back(data[cont]);
            }
            else{
                fltr.add(data[cont]);
            }
            cont+=1;
        }

        blockSize += (cantData)/blocks;
        int countFalsePos = 0;

        for (int j = 0; j < lookFor.size(); ++j) {
            bool falsePositive = fltr.search(lookFor[j]);
            if(falsePositive){
                countFalsePos++;
            }
        }
        cout<< "FALSE POSITIVES BLOCK ";
        cout<< i<<": "<<countFalsePos <<endl;
    }



    return;
}
//int main(){
//    blockTest(5);
//    return 0;
//}
