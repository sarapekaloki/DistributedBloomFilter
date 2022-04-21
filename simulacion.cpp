#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "BloomFilter.h"
using namespace std;
typedef int (*HashFunction)(string);
class Simulacion{
    vector<string> data1;
    vector<string> data2;
    BloomFilter filter1;
    BloomFilter filter2;
private:
    void createMap(BloomFilter filter,vector<string> data){
        for (vector<string>::iterator i = data.begin(); i != data.end(); i++) {
            filter.add(*i);
        }
    }

public:
    Simulacion( vector<HashFunction> funcs,vector<string> vec1, vector<string> vec2,int filterSize){
        data1 =vec1;
        data2 =vec2;
        BloomFilter filter1(filterSize,funcs);
        BloomFilter filter2(filterSize,funcs);
        createMap(filter1,data1);
        createMap(filter2,data2);
    }

    void checkEquality(){
        string mod = "Son iguales";
        for (int i = 0; i < filter1.getFiltro().size() ; ++i) {
            if (filter1.getFiltro()[i] != filter2.getFiltro()[i]){
                string mod = "Hubo cambios";
                addData(i);
            }
        cout<<mod<<endl;
        };

        return;
    }

    void addData(int index){
        if(filter1.getFiltro()[index]==0){
            filter1.getFiltro()[index]=1;
        }
        else{
            filter2.getFiltro()[index]=1;
        }
        return;
    }

    void searchTest(){
            cout << "Checando elementos en el filtro 1... " <<endl;
            for (vector<string>::iterator i = data2.begin(); i != data2.end(); i++) {
                cout << *i + ": " << filter1.search(*i) << endl;
            };
            cout << "Checando elementos en el filtro 2..." <<endl;
        for (vector<string>::iterator i = data1.begin(); i != data1.end(); i++) {
            cout << *i + ": " << filter2.search(*i) << endl;
        };


        return;
    }

};
//FUNCIONES HASH
int bloomsz =1024;
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
int hash2(string s)
{
    int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        //Se multiplica ahora una potencia de 13
        hash = hash + pow(19, i) * int(s[i]);
        hash = hash % bloomsz;
    }
    //Se hace mod de nuevo
    return hash % bloomsz;
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
// hash 4
int hash4(string s)
{
    int hash = 3;
    for (int i = 0; i < s.size(); i++) {
        hash += hash * 7 + s[0] * pow(7, i);
        hash = hash % bloomsz;
    }
    return hash;
}


int main(){
    int cont =0;
    vector<string> set({});
    vector<string> set1({});
    ifstream ip ("/Users/saramarquez/Documents/ICC/6TO/Analisis de algoritmos/BloomFilter/nombres.csv");
    if(!ip.is_open()){
        cout << "error";
    }
    string name;
    while (ip.good() && cont<=500){
        getline(ip,name,'\n');
        set.push_back(name);
        cont+=1;
        if (cont % 2 ==0){
            set1.push_back(name);
        }
    }
    ip.close();


    return 0;
 };
