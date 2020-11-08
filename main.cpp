#include<bits/stdc++.h>
#include "cryptAlgo.h"

using namespace std;

int main(){
    cryptAlgos bfVar;
    string text = "123456abcd132536";
    string ret = bfVar.BlowFish(text);
    cout<<ret<<"\n";
    return 0;
}