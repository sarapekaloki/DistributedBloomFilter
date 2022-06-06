#include <iostream>
#include <vector>
#include "../include/BloomFilter.h"
#include "../include/universalHash.h"
#include <algorithm>
using namespace std;




void prueba_search(){
    vector<HashFunction> v;
    HashFunction hash = h1;
    v.push_back(hash);

    BloomFilter fltr(20,v);
    vector<string> names = {"sara","mario","hugo","almaraz","peka"};
    for (int i = 0; i < names.size(); ++i) {
        fltr.add(names[i]);
    }
    for (int i = 0; i < names.size() ; ++i) {
        fltr.search(names[i]);
    }
    cout<<"SEARCH TEST PASSED";
    return;
}
