//
// Created by Sara Marquez on 22/04/22.
//
#include <iostream>
#include <vector>
#include "../include/BloomFilter.h"
#include <algorithm>
using namespace std;
typedef int (*HashFunction)(string);

int hashfunc2(string s)
{
    int hash = 0;
    //Se itera a traves del string insertado
    for (int i = 0; i < s.size(); i++)
    {
        //Se suma el valor de hash, a el valor decimal de una letra del string
        hash = (hash + ((int)s[i]));
        //Despues a ese valor se le hace mod el tamaño del filtro
        hash = hash % 20;
    }
    return hash;
}

void prueba_search(){
    vector<HashFunction> v;
    v.push_back(hashfunc2);

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
