//
// Created by Sara Marquez on 22/04/22.
//
#include <iostream>
#include <vector>
#include "../include/BloomFilter.h"
#include "../include/read_Data.h"
using namespace std;
typedef int (*HashFunction)(string);
int sz=150;

// hash 3
int hash2(string s)
{
    int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + ((int)s[i]));
        hash = hash % sz;
    }
    return hash;
}
// hash 4
int hash4(string s) {
    int hash = 5;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 3 + s[i]) % sz;
    }
    return hash % sz;
}

void blockTest(int blocks){
    vector<HashFunction> v;
    v.push_back(hash2);
    v.push_back(hash4);
    vector<string> v1;

    string name;
    int cantData =sz/3;
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
}//
// Created by SARAMARQUEZ on 5/21/2022.
//

