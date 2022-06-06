//
// Created by Sara Marquez on 04/06/22.
//


#include "universalHash.h"
#define ll long long
using namespace std;
typedef int (*HashFunction)(string,int);
int h1(string s, int bloomsz)
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
int h2(string s, int bloomsz)
{
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 11 + s[i]) % bloomsz;
    }
    return hash % bloomsz;
}

// hash 3
int h3(string s, int bloomsz)
{
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 7 + s[i]) % bloomsz;
    }
    return hash % bloomsz;
}
// hash 4
int h4(string s, int bloomsz) {
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 17 + s[i]) % bloomsz;
    }
    return hash % bloomsz;
}
