#include<bits/stdc++.h>
using namespace std;

void polyalpha(string msg,string key);
string decryptPoly(string msg, string key);

string polyCipher;

int main() {

    cout<<"What is your Secret Message?\n";
    string msg;
    getline(cin, msg);

    string key2 = "RAKIB";
    cout<<"Plain text to Polyalphabetic cipher : ";
    polyalpha(msg,key2);

    cout<<"Polyalphabetic cipher to Plain text\n";

    cout<<"Secret message is: ";
    cout<<decryptPoly(polyCipher,key2)<<"\n";


}

void polyalpha(string msg,string key){

string encrypt;

for(int i=0;i<msg.size();i++){
    if(isalpha(msg[i])){
        int k_value= (key[i%key.size()]) - 'A';

        if(isupper(msg[i])){
            encrypt+= 'A' + (msg[i] - 'A' + k_value)%26 ;
        }
        else{
            encrypt+= 'a' + (msg[i] - 'a' + k_value)%26 ;
        }
    }
    else{
        encrypt+=msg[i];
    }
}

polyCipher=encrypt;

cout<<encrypt<<"\n";


}

string decryptPoly(string msg, string key) {
    string polyde;
    for (int i = 0; i < msg.size(); i++) {
        if (isalpha(msg[i])) {
            char k_value = key[i % key.size()];
            k_value = k_value - 'A';

            if (isupper(msg[i])) {
                polyde += 'A' + (msg[i] - 'A' - k_value + 26) % 26;
            } else {
                polyde += 'a' + (msg[i] - 'a' - k_value + 26) % 26;
            }
        } else {
            polyde += msg[i];
        }
    }
    return polyde;
}

