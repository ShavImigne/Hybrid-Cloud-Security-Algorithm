#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

class DigitalSignatures{
    string passKey;
    public:
        DigitalSignatures(string key);
        string encryptMessage(string message);
        string decryptMessage(string enc_hash);
        bool VerifySignature(string enc_hash,string dec_hash);
};

DigitalSignatures::DigitalSignatures(string key){
    passKey = key;
}

string DigitalSignatures::encryptMessage(string message){
    ll result=0,enc_hash=0,tens=1;
    int n = message.size();
    for(int i=0;i<n;i++){
        result = result * 31 + message[i];
    }
    int m = passKey.size();
    enc_hash = result;
     for(int i=0;i<n-1;i++)
    {
        enc_hash = enc_hash + passKey[i%m]*tens;
        tens = tens*999999;
    }
    string ret = "0x" + to_string(enc_hash);
    return ret;
}

string DigitalSignatures::decryptMessage(string enc_hash){
    int n = enc_hash.size();
    int m = passKey.size();
    ll tens = 1;
    string enc = enc_hash.substr(2,n-2);
    ll encrypted_hash = stoi(enc);
    ll dec_hash = encrypted_hash;
    for(int i=0; i<n-1; i++){
        dec_hash = dec_hash - passKey[i%m]*tens;
        tens = tens*999999;  
    }
    string ret = "0x" + to_string(dec_hash);
    return ret;
}

bool DigitalSignatures::VerifySignature(string enc_hash,string dec_hash){
    if(enc_hash == dec_hash){
        return 1;
    }
    return 0;
}



