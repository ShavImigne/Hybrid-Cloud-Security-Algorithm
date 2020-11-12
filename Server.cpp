#include "cryptAlgo.h"

using namespace std;
#define PATH "/home/vignesh/INS_project/USER_FILES/"

string RSAEncryption(string msg, int n, int key)
{
    long int pt,ct,k;
    string temp(msg.size(),'a'),en;
    for(int i=0;i<msg.size();i++)
    {
        pt=msg[i];
        pt=pt-96;
        k=1;
        for (int j=0;j<key;j++)
        {
            k=k*pt;
            k=k%n;
        }
        temp[i]=k;
        ct=k+96;
        en+=(char)ct;
        i++;
    }
    return en;
}

int main() {
    string file_name;
    cout<<"Enter the file name to be sent:\n";
    cin>>file_name;

    file_name=PATH + file_name;

    ifstream ip_file;
    ip_file.open(file_name.c_str(),ios::in);

    if(ip_file.fail()) {
        cout << "Can not open the file\n";
        return 0;
    }

    fstream op_file;
    op_file.open(((string)PATH+"encrypted_file.txt").c_str(),ios::out);

    if(!op_file){
        cout<<"Cannot create the file";
        return 0;
    }

    // Can add random key generation
    string key;
    key="aabb09182736ccdd";
    cryptAlgo obj(key);

    string line;
    string Ef;
    while(getline(ip_file,line)){
        cout<<line<<endl;
        string encrypted_line=obj.blowfishEncrypt(line);
        op_file<<encrypted_line;
        Ef.append(encrypted_line);
        op_file<<"\n";
    }
    // Public key:
    int n=391,e=37;
    string encrypted_key=RSAEncryption(key,n,e);

    fstream op_key;
    op_key.open(((string)PATH+"encrypted_key.txt").c_str(),ios::out);

    if(!op_key){
        cout<<"Cannot open file";
        return 0;
    } else {
        op_key<<encrypted_key;
    }

    string message_digest=obj.shaHash(Ef);

    //Signature pass key (random)
    string signature_hash_key = "xJasaswx0aa7";
    DigitalSignatures userSignature(signature_hash_key);
    string Ds = userSignature.createSignature(message_digest);


    fstream op_SignatureFile;
    op_SignatureFile.open(((string)PATH+"User_Signature.txt").c_str(),ios::out);

    if(!op_SignatureFile){
        cout<<"Cannot create the file";
        return 0;
    }
    else{
        op_SignatureFile<<Ds;
    }

    ip_file.close();
    op_file.close();
    op_key.close();
    op_SignatureFile.close();
}
