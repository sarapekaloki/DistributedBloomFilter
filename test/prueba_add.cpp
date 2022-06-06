#include <iostream>
#include <vector>
#include "../include/BloomFilter.h"
#include "../include/universalHash.h"
#include <algorithm>
using namespace std;


void prueba_add(){
    vector<HashFunction> v;
    HashFunction hash = h1;
    v.push_back(h1);
    BloomFilter fltr(20,v);
    vector<string> names = {"sara","mario","hugo","almaraz","peka"};
    for (int i = 0; i < names.size(); ++i) {
        fltr.add(names[i]);
    }
    cout<<"ADD TEST PASSED";
    return;
}
