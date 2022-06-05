//
// Created by Sara Marquez on 22/04/22.
//

#include "Simulation.h"
#include <iostream>
#include <vector>
#include "BloomFilter.h"
#include <algorithm>
using namespace std;

Simulation::Simulation( vector<string> vec1, vector<string> vec2, BloomFilter f1, BloomFilter f2){
    data1 =vec1;
    data2 =vec2;
    filter1=f1;
    filter2=f2;

}

void Simulation::checkEquality(){
    string mod = "Son iguales";
    for (int i = 0; i < filter1.filter.size(); i++) {
        if (filter1.filter[i] != filter2.filter[i]){
            mod = "Hubo cambios";
            addData(i);
        }
    }
    cout<<mod<<endl;

    return;
}

void Simulation::addData(int index){
    if(filter1.filter[index]==0){
        filter1.changeBit(index);
    }
    else{
        filter2.changeBit(index);
    }
    return;
}

void Simulation::searchTest(){
    cout << "Checando elementos en el filtro 1 " <<endl;
    int count = 0;
    for (vector<string>::iterator i = data2.begin(); i != data2.end(); i++) {
        if (!filter1.search(*i)){
            count++;
        }
    }
    cout<< "Usuarios no encontrados "<<count<<endl;
    count = 0;
    cout << "Checando elementos en el filtro 2..." <<endl;
    for (vector<string>::iterator i = data1.begin(); i != data1.end(); i++) {
        if (!filter2.search(*i)) {
            count++;
        }
    }
    cout<< "Usuarios no encontrados "<<count<<endl;

    return;
}

