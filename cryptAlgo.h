
#ifndef INS_PROJECT_CRYPTALGO_H
#define INS_PROJECT_CRYPTALGO_H

#include <bits/stdc++.h>
#include "blowfish.h"
#include "shaHash2.h"
#include "digitalSignature.h"
using namespace std;


typedef long long int ll;

class cryptAlgo{
    ll rsaPrime1;
    ll rsaPrime2;
    string blow_fish_hexKey;
    BLOWFISH obj;
    
public:
    cryptAlgo(string key);
//    double rsa(double message);
    string blowfishEncrypt(string data);
    string shaHash(string input);
    string blowfishDecrypt(string e);
};

cryptAlgo::cryptAlgo(string key){
    rsaPrime1 = 13;
    rsaPrime2 = 11;
    blow_fish_hexKey = key;
    obj = BLOWFISH(blow_fish_hexKey);
}

string cryptAlgo::blowfishEncrypt(string data){
    string e_data = obj.Encrypt_ECB(data);
    return e_data;
}
string cryptAlgo::blowfishDecrypt(string data){
    string d_data = obj.Decrypt_ECB(data);
    return d_data;
}

string cryptAlgo::shaHash(string input){
    string op = sha256(input);
    return op;
}


#endif //INS_PROJECT_CRYPTALGO_H
