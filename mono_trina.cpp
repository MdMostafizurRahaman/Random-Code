#include<bits/stdc++.h>
using namespace std;

string monoCipher;

void monoalphaCipher(string msg,string key){

map<char,char>m;

for(int i=0;i<26;i++){
    m['A'+i] = key[i];
    m['a'+i] = tolower(key[i]);
}

string monoEncrypt;

for(int i=0;i<msg.size();i++){
    if(isalpha(msg[i])){
       monoEncrypt+=m[msg[i]];
    }
    else{
        monoEncrypt+=msg[i];
    }
}
monoCipher=monoEncrypt;
cout<<monoEncrypt<<"\n";

}

string decryptMono(string msg,string key){

string decrypt;

map<char,char>m;

for(int i=0;i<monoCipher.size();i++){
    m[tolower(key[i])] = 'a' + i;
    m[key[i]] = 'A' + i;
}

for(int i=0;i<msg.size();i++){
    if(isalpha(msg[i])){
       decrypt+=m[msg[i]];
    }
    else{
        decrypt+=msg[i];
    }
}



return decrypt;
}



int main() {

    cout<<"What is your Secret Message?\n";
    string msg;
    getline(cin, msg);

    cout<<"Plain text to Monoalphabetic cipher : ";
    string key = "TASDFGHJKLMNBVCXZPOIUYQWER";
    monoalphaCipher(msg,key);
    cout<<"Monoalphabetic cipher to Plain text\n";

    cout<<"Secret message is: ";
    cout<<decryptMono(monoCipher,key)<<"\n";



}