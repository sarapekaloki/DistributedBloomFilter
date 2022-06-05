//
// Created by SARAMARQUEZ on 5/24/2022.
//

#include "read_Data.h"
#include "../include/BloomFilter.h"
vector<string> getData(int dataQuantity){
    vector<string> data;
    ifstream ip ("/Users/SARAMARQUEZ/Desktop/Ing Ciencias Computacionales/6to Semestre/Algoritmos/dataset/modNames.csv");
    int i =0;
    if(!ip.is_open()){
        cout << "error";
    }
    string name;
    while (ip.good() && i<= dataQuantity){
        getline(ip,name,'\n');
        data.push_back(name);
        i+=1;
    }
    ip.close();
    return data;
}



