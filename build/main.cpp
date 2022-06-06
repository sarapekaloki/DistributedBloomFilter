
#include <iostream>
#include <vector>

#include "../include/BloomFilter.h"
#include "../include/Simulation.h"
#include "../include/universalHash.h"


#define ll long long




int main(){
    int bloomsz =2500000;
    int cont =0;

    vector<string> names1;
    vector<string> names2;
    vector<string> names3;

    vector<HashFunction> functionsAB;
    vector<HashFunction> functionsBC;
    HashFunction hash1 = h1;
    HashFunction hash2 = h2;
    HashFunction hash3 = h3;
    HashFunction hash4 = h4;


    functionsAB.push_back(hash1);
    functionsAB.push_back(hash2);
    functionsBC.push_back(hash3);
    functionsBC.push_back(hash4);

    BloomFilter filterA (bloomsz,functionsAB);
    BloomFilter filterB (bloomsz,functionsAB);
    BloomFilter filterB2 (bloomsz,functionsBC);
    BloomFilter filterC (bloomsz,functionsBC);
    ifstream ip ("//Users/saramarquez/Documents/ICC/6TO/Analisis de algoritmos/BloomFilter/dataset/modNames.csv");

    if(!ip.is_open()){
        cout << "error";
    }
    string name;
    while (ip.good() && cont<= bloomsz/3){
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
    a_b.searchTest();
    cout <<"................................................"<<endl;
    a_b.checkEquality();
    cout <<"................................................"<<endl;
    cout <<"Checando busqueda..."<<endl;
    a_b.searchTest();

    cout <<"................................................"<<endl;

    //NODO B Y C
    cout<< "COMENZANDO COMUNICACION ENTRE NODO B Y C"<<endl;
    Simulation b_c (names1,names3,filterB2,filterC);
    b_c.searchTest();
    cout <<"................................................"<<endl;
    b_c.checkEquality();
    cout <<"................................................"<<endl;
    cout <<"Checando busqueda..."<<endl;
    b_c.searchTest();

    return 0;
};
