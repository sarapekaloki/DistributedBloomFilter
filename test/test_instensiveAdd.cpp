//
// Created by Sara Marquez on 22/04/22.
//
#include <iostream>
#include <vector>
#include "../include/BloomFilter.h"
#include <algorithm>
using namespace std;
typedef int (*HashFunction)(string);
int bloomsz=4000000;
int hash1(string s)
{
    int hash = 0;
    //Se itera a traves del string insertado
    for (int i = 0; i < s.size(); i++)
    {
        //Se suma el valor de hash, a el valor decimal de una letra del string
        hash = (hash + ((int)s[i]));
        //Despues a ese valor se le hace mod el tamaño del filtro
        hash = hash % bloomsz;
    }
    return hash;
}

// hash 3
int hash3(string s)
{
    int hash = 7;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 31 + s[i]) % bloomsz;
    }
    return hash % bloomsz;
}

void intensiveAdd(){
    vector<HashFunction> v;
    v.push_back(hash1);
    v.push_back(hash3);

    BloomFilter fltr(8000000,v);
    int cont =0;
    ifstream ip ("/Users/SARAMARQUEZ/Desktop/Ing Ciencias Computacionales/6to Semestre/Algoritmos/dataset/modNames.csv");

    string name;
    while (ip.good() && cont<=5000000){
        getline(ip,name,'\n');
        fltr.add(name);
        cont+=1;
    }
    ip.close();
    cout<<"INTENSIVE ADD TEST PASSED";
    return;
}

