#include <iostream>
#include <vector>
#include "../include/BloomFilter.h"
#include "../include/universalHash.h"
#include <algorithm>
using namespace std;




void intensiveAdd(){
    vector<HashFunction> v;
    HashFunction hash1 = h1;
    HashFunction  hash2 = h2;
    v.push_back(hash1);
    v.push_back(hash2);
    int size = 8000009;
    int dataToInsert = 5000000;
    BloomFilter fltr(size,v);
    int cont =0;
    ifstream ip ("/Users/saramarquez/Documents/ICC/6TO/Analisis de algoritmos/BloomFilter/dataset/modNames.csv");
    string name;
    while (ip.good() && cont<=dataToInsert){
        getline(ip,name,'\n');
        fltr.add(name);
        cont+=1;
    }
    ip.close();
    cout<<"INTENSIVE ADD TEST PASSED "<< dataToInsert << " NAMES ADDED";
    return;
}
//int main (){
//    intensiveAdd();
//}
