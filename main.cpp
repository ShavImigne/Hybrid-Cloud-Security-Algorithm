#include<bits/stdc++.h>
#include "cryptAlgo.h"

using namespace std;

int main(){
    cryptAlgos bfVar;
    string text = "grape";
    //string ret = bfVar.BlowFish(text);
    //cout<<ret<<"\n";
    string ans = bfVar.shaHash(text);
    cout<<ans<<" ";
    return 0;
}