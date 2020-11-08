#include<bits/stdc++.h>
#include "methods.h"
#include "blowfish.h"

using namespace std;

class cryptAlgos;


class cryptAlgos{
    ll rsaPrime1;
    ll rsaPrime2;
    string blow_fish_hexKey;
public: 
    cryptAlgos();
    double rsa(double message);
    string BlowFish(string data);
};

cryptAlgos::cryptAlgos(){
    rsaPrime1 = 13;
    rsaPrime2 = 11;
    blow_fish_hexKey = "aabb09182736ccdd";
}

string cryptAlgos::BlowFish(string data){
    BLOWFISH obj(blow_fish_hexKey); 
    obj.keyGe
    string e = obj.Encrypt_CBC(data);
    return e;
}
double cryptAlgos::rsa(double message){
    double n=rsaPrime1*rsaPrime2;
    double track;
    double phi= (rsaPrime1-1)*(rsaPrime2-1);
    double e = 7;
    
    //satisfying conditions for e
    while(e<phi) {
        track = gcd(e,phi);
        if(track==1)
            break;
        else
            e++;
    }   
    double encryptedMessage = pow(message,e); //encrypt the message
    encryptedMessage = fmod(encryptedMessage,n);
    return encryptedMessage;
}


