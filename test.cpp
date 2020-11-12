#include<bits/stdc++.h>

using namespace std;
#include "digitalSignature.h"

int main(){
    std::string message = "asdfgagasdgdasgd";
    DigitalSignatures obj("xJasaswx0aa7");
    string signature = obj.createSignature(message);
    cout<<signature<<endl;
    return 0;
}