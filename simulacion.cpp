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

public:
    Simulacion( vector<string> vec1, vector<string> vec2, BloomFilter f1, BloomFilter f2){
        data1 =vec1;
        data2 =vec2;
        filter1=f1;
        filter2=f2;

    }

    void checkEquality(){
        string mod = "Son iguales";
        for (int i = 0; i < 1024 ; i++) {
            if (filter1.getFiltro()[i] != filter2.getFiltro()[i]){
                mod = "Hubo cambios";
                addData(i);
            }
        }
        cout<<mod<<endl;

        return;
    }

    void addData(int index){
        if(filter1.getFiltro()[index]==0){
            filter1.changeBit(index);
        }
        else{
            filter2.changeBit(index);
        }
        return;
    }

    void searchTest(){
        cout << "Checando elementos en el filtro 1 " <<endl;
        int count = 0;
        for (vector<string>::iterator i = data2.begin(); i != data2.end(); i++) {
            if (!filter1.search(*i)){
                count++;
                cout<< *i <<" No encontrado"<<endl;
            }
        }
        cout<< "Usuarios no encontrados "<<count<<endl;
        count = 0;
        cout << "Checando elementos en el filtro 2..." <<endl;
        for (vector<string>::iterator i = data1.begin(); i != data1.end(); i++) {
            if (!filter2.search(*i)){
                count++;
                cout<< *i <<" No encontrado "<<endl;
            }else {

            }
        }
        cout<< "Usuarios no encontrados "<<count<<endl;
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
    vector<string> set2({});
    ifstream ip ("/Users/saramarquez/Documents/ICC/6TO/Analisis de algoritmos/BloomFilter/nombres.csv");

    vector<HashFunction> functionsAB;
    vector<HashFunction> functionsBC;


    functionsAB.push_back(hash1);
    functionsAB.push_back(hash2);
    functionsBC.push_back(hash3);
    functionsBC.push_back(hash4);


    BloomFilter filterA (bloomsz,functionsAB);
    BloomFilter filterB (bloomsz,functionsAB);
    BloomFilter filterB2 (bloomsz,functionsBC);
    BloomFilter filterC (bloomsz,functionsBC);

    if(!ip.is_open()){
        cout << "error";
    }
    string name;
    while (ip.good() && cont<=500){
        getline(ip,name,'\n');
        filterA.add(name);
        set.push_back(name);
        if (cont % 2 ==0){
            filterB.add(name);
            set1.push_back(name);
        }
        if (cont%3==0){
            filterC.add(name);
            set2.push_back(name);
        }
        cont+=1;
    }
    ip.close();





    //NODO A Y B
    cout<< "COMENZANDO COMUNICACION ENTRE NODO A Y B"<<endl;
    Simulacion a_b (set,set1,filterA,filterB);
    a_b.checkEquality();
    cout <<"................................................"<<endl;
    cout <<"Checando busqueda..."<<endl;
    a_b.searchTest();

    set1.insert(set1.end(),set.begin(),set.end());

    for (int i = 0; i < set1.size(); ++i) {
        filterB2.add(set1[i]);
    }
    cout <<"................................................"<<endl;


    //NODO B Y C
    cout<< "COMENZANDO COMUNICACION ENTRE NODO B Y C"<<endl;
    Simulacion b_c (set1,set2,filterB2,filterC);
    b_c.checkEquality();
    cout <<"................................................"<<endl;
    cout <<"Checando busqueda..."<<endl;
    b_c.searchTest();

    return 0;
};
