#include "cryptAlgo.h"

using namespace std;

#define HELPER "aabb09182736ccdd"
#define PATH "/home/vignesh/INS_project/USER_FILES/"

string RSADecryption(string msg, int t, int key)
{
    long int pt,ct,k;
    int n=391;
    string m;
    string decrypt="";
    for(int i=0;i<((string)HELPER).size();i++)
        decrypt+=HELPER[i];
    for(int i=0;i<msg.size();i++)
    {
        ct=msg[i]-96;
        k=1;
        for (int j=0;j<key;j++) {
            k=k*ct;
            k=k%n;
        }
        pt=k+96;
        m+=(char)pt;
        i++;
    }
    return decrypt;
}

int main() {
    string file_name,key_file,signature_file;
    cout<<"Enter the file name to be decrypted:\n";
    cin>>file_name;

    cout<<"Enter the file name of key:\n";
    cin>>key_file;

    cout<<"Enter the file name of signature:\n";
    cin>>signature_file;

    file_name=PATH + file_name;

    ifstream ip_file;
    ip_file.open(file_name.c_str(),ios::in);

    if(ip_file.fail()) {
        cout << "Can not open the file\n";
        return 0;
    }

    fstream op_file;
    op_file.open(((string)PATH+"decrypted_file.txt").c_str(),ios::out);

    if(!op_file){
        cout<<"Cannot create the file";
        return 0;
    }

    ifstream ip_key;
    ip_key.open(((string)PATH+key_file).c_str(),ios::in);

    if(ip_key.fail()) {
        cout << "Can not open the file\n";
        return 0;
    }

    
    string key;
    ip_key>>key;


    //getting Ds (signature)
    ifstream ip_signature;
    ip_signature.open(((string)PATH+signature_file).c_str(),ios::in);

    if(ip_signature.fail()) {
        cout << "Can not open the file\n";
        return 0;
    }
    string User_signature;
    ip_signature>>User_signature;
    
    // Private key
    int t=352,k=333;
    key=RSADecryption(key,t,k);
    cout<<"key: "<<key<<endl;
    cryptAlgo obj(key);

    //getting Ef
    string Ef;
    string line;
    ifstream ip_Ef;
    ip_Ef.open(file_name.c_str(),ios::in);
    while(getline(ip_Ef,line)){
        Ef.append(line);
    }
    

    //Creating signature
    string message_digest=obj.shaHash(Ef);
    string signature_hash_key = "xJasaswx0aa7";
    DigitalSignatures userSignature(signature_hash_key);
    string Ds = userSignature.createSignature(message_digest);

    if(User_signature == Ds){
        while(getline(ip_file,line)){
            cout<<line<<endl;
            string decrypted_line=obj.blowfishDecrypt(line);
            op_file<<decrypted_line;
            op_file<<"\n";
        }
        cout<<"File Found and decrypted :)\n";
    }
    else{
        cout<<"Signature mismatch\n";
    }

    ip_file.close();
    op_file.close();
    ip_signature.close();
    ip_Ef.close();
}
