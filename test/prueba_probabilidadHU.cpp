
#include <iostream>
#include <vector>
#include <algorithm>

#include "../include/read_Data.h"
#include "../include/universalHash.h"

using namespace std;


void colisiones(){
    vector<HashFunction> hashFunctions;
    HashFunction hash1 = h1;
    HashFunction hash2 = h2;
    HashFunction hash3 = h3;
    HashFunction hash4 = h4;
    hashFunctions.push_back(hash1);
    hashFunctions.push_back(hash2);
    hashFunctions.push_back(hash3);
    hashFunctions.push_back(hash4);

    int sz=59;
    vector<string> nombres = getData(20);
    int count2 = 0;
    vector<int> keys;
    for (vector<HashFunction>::iterator i = hashFunctions.begin(); i != hashFunctions.end(); i++) {
        int count = 0;
        for (int j = 0; j <nombres.size() ; ++j) {
            int key = (*i)(nombres[j], sz);
            if (std::count(keys.begin(), keys.end(), key)) {
                count++;
            } else {
                keys.push_back(key);
            }
        }
        count2++;
        keys.clear();
        cout<<"COLISSIONS IN FUNCTION "<< count2 <<": "<< count<<endl;
        }
    return;
}



