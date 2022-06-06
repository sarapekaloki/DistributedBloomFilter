//
// Created by Sara Marquez on 22/04/22.
//
#include <iostream>
#include <vector>
#include "../include/BloomFilter.h"
#include "../include/Simulation.h"
#include "../include/universalHash.h"
#include <algorithm>
using namespace std;




void prueba_CheckEquality(){
    vector<HashFunction> v;
    HashFunction hash = h1;
    v.push_back(hash);

    BloomFilter fltr(20,v);
    BloomFilter fltr2(20,v);

    vector<string> names = {"sara","mario","hugo","almaraz","peka"};
    for (int i = 0; i < names.size(); ++i) {
        fltr.add(names[i]);
    }
    vector<string> names2 = {"sara","mario","hugo","almaraz","peka"};
    for (int i = 0; i < names2.size(); ++i) {
        fltr2.add(names2[i]);
    }
    Simulation sim(names,names2,fltr,fltr2);
    sim.searchTest();

    cout<<"SEARCH TEST PASSED";
    return;
}
