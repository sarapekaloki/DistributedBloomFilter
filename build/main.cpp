//
// Created by Sara Marquez on 22/04/22.
//

#include <iostream>
#include <vector>

#include "../include/BloomFilter.h"
#include "../include/Simulation.h"
#include <bitset>

#define ll long long

//FUNCIONES HASH
int bloomsz =100;
int h1(string s)
{
    ll int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + ((int)s[i]));
        hash = hash % bloomsz;
    }
    return hash;
}



// hash 2
int h2(string s)
{
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + ((int)s[i]));
    }
    return hash % bloomsz;
}

// hash 3
int h3(string s)
{
    ll int hash = 7;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 31 + s[i]) % bloomsz;
    }
    return hash % bloomsz;
}
// hash 4
int h4(string s) {
    ll int hash = 5;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 3 + s[i]) % bloomsz;
    }
    return hash % bloomsz;
}

int main(){

    int cont =0;

    vector<string> names1;
    vector<string> names2;
    vector<string> names3;

    vector<HashFunction> functionsAB;
    vector<HashFunction> functionsBC;

    functionsAB.push_back(h1);
    functionsAB.push_back(h2);
    functionsBC.push_back(h3);
    functionsBC.push_back(h4);

    BloomFilter filterA (bloomsz,functionsAB);
    BloomFilter filterB (bloomsz,functionsAB);
    BloomFilter filterB2 (bloomsz,functionsBC);
    BloomFilter filterC (bloomsz,functionsBC);
    ifstream ip ("/Users/SARAMARQUEZ/Desktop/Ing Ciencias Computacionales/6to Semestre/Algoritmos/dataset/modNames.csv");

    if(!ip.is_open()){
        cout << "error";
    }
    string name;
    while (ip.good() && cont<= bloomsz/2){
        getline(ip,name,'\n');
        filterA.add(name);
        filterB2.add(name);
        names1.push_back(name);
        if (cont % 2 ==0){
            filterB.add(name);
            names2.push_back(name);
        }
        if (cont % 3 ==0){
            filterC.add(name);
            names3.push_back(name);
        }
        cont+=1;
    }
    ip.close();

    //NODO A Y B
    cout<< "COMENZANDO COMUNICACION ENTRE NODO A Y B"<<endl;
    Simulation a_b (names1,names2,filterA,filterB);
    cout <<"................................................"<<endl;
    a_b.checkEquality();
    cout <<"................................................"<<endl;
    cout <<"Checando busqueda..."<<endl;
    a_b.searchTest();

    cout <<"................................................"<<endl;

    //NODO B Y C
    cout<< "COMENZANDO COMUNICACION ENTRE NODO B Y C"<<endl;
    Simulation b_c (names1,names3,filterB2,filterC);
    cout <<"................................................"<<endl;
    b_c.checkEquality();
    cout <<"................................................"<<endl;
    cout <<"Checando busqueda..."<<endl;
    b_c.searchTest();

    return 0;
};
