
#ifndef DIGITAL_SIGNATURE_INCLUDED
#define DIGITAL_SIGNATURE_INCLUDED

#include<string> 

using namespace std;

typedef long long int ll;

class DigitalSignatures{
    std::string passKey;
    public:
        DigitalSignatures(std::string key);
        std::string createSignature(std::string message_digest);
        //std::string decryptMessage(std::string enc_hash);
};

DigitalSignatures::DigitalSignatures(std::string key){
    passKey = key;
}

std::string DigitalSignatures::createSignature(std::string message_digest){
    ll result=0,enc_hash=0,tens=1;
    int n = message_digest.size();
    for(int i=0;i<n;i++){
        result = result * 31 + message_digest[i];
    }
    
    int m = passKey.size();
    enc_hash = result;
     for(int i=0;i<n-1;i++)
    {
        enc_hash = enc_hash + passKey[i%m]*tens;
        tens = tens*2;
    }
    std::string ret = to_string(enc_hash);
    return ret;
}

/* std::string DigitalSignatures::decryptMessage(std::string enc_hash){
    int n = message.size();
    int m = passKey.size();
    ll tens = 1;
    std::string enc = enc_hash;
    ll encrypted_hash = (ll)stoll(enc);
    
    ll dec_hash = encrypted_hash;
    for(int i=0; i<n-1; i++){
        dec_hash = dec_hash - passKey[i%m]*tens;
        tens = tens*2;  
    }
    dec = dec_hash;
    std::string ret = to_string(dec_hash);
    return ret;
}*/
#endif



