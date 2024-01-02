#include<bits/stdc++.h>
using namespace std;

void PolyAlphabatic_Decryption(string cyperText,string key)
{

    string plainText=cyperText;

     for(int i=0;i<cyperText.size();i++)
    {
        if(cyperText[i]>='a' and cyperText[i]<='z')
        {
           plainText[i]='a'+(((cyperText[i]-'a')-(key[i%key.size()]-'a')+26)%26);

        }
        else
        {
            plainText[i]=cyperText[i];
        }
    }
    printf("Decrypted Message is :\n");
    cout<<plainText;
    printf("\n");


}

void PolyAlphabatic_Encryption(string plainText)
{
    printf("Enter key as a String\n");
    string key;
    string cyperText=plainText;
     cin>>key;
    //getline(cin,key);
    for(int i=0;i<plainText.size();i++)
    {
        if(plainText[i]>='a' and plainText[i]<='z')
        {
           cyperText[i]='a'+(((plainText[i]-'a')+(key[i%key.size()]-'a')+26)%26);

        }
        else
        {
            cyperText[i]=plainText[i];
        }
    }

    printf("Encrypted Message :\n");
    cout<<cyperText;
    printf("\n");
    printf("Are you want to Decrypt this Message?\n1)Yes\n2)No\n");
    int option;
    cin>>option;
    if(option==1)
    {
        PolyAlphabatic_Decryption(cyperText,key);

    }
}

void MonoAlphabatic_Decryption(string cyperText)
{
    string alphabet="abcdefghijklmnopqrstuvwxyz";
     string key="efghijklmnopqrstuvwxyzabcd";
     map<char,char>mp;
     for(int i=0;i<alphabet.size();i++)
     {
         //cout<<"i am in map conversion\n";
         mp[key[i]]=alphabet[i];
     }
     string plainText=cyperText;
     for(int i=0;i<plainText.size();i++)
     {
         if(cyperText[i]>='a' and cyperText[i]<='z'){
             plainText[i]=mp[cyperText[i]];
             //cout<<"i am in convesion";
         }
         else
            plainText[i]=cyperText[i];
     }
     printf("Decrypted Message is : \n");
    // cout<<"size="<<cyperText.size();
     //  cout<<cyperText;
     cout<<plainText;
     printf("\n");
}

 void MonoAlphabatic_Encryption(string plainText)
 {
     string alphabet="abcdefghijklmnopqrstuvwxyz";
     string key="efghijklmnopqrstuvwxyzabcd";
     map<char,char>mp;
     for(int i=0;i<alphabet.size();i++)
     {
         //cout<<"i am in map conversion\n";
         mp[alphabet[i]]=key[i];
     }
     string cyperText=plainText;
     for(int i=0;i<plainText.size();i++)
     {
         if(plainText[i]>='a' and plainText[i]<='z'){
             cyperText[i]=mp[plainText[i]];
             //cout<<"i am in convesion";
         }
         else
            cyperText[i]=plainText[i];
     }
     printf("Encrypted Message is : \n");
    // cout<<"size="<<cyperText.size();
     //  cout<<cyperText;
    cout<<cyperText;

     printf("\n");
     printf("Are you want to Decrypt This Message?\n1)Yes\n2)No\n");
     int option;
     cin>>option;
     if(option==1)
     {
         MonoAlphabatic_Decryption(cyperText);
     }
     printf("\n");


 }
int main()
{
    printf("Enter a message\n");
    string plainText;
    getline(cin, plainText);
    printf("Choice an option\n1)MonoAlphabatic_Encrypiton\n2)PolyAlphabatic_Encryption\n");
    int choice;
    cin>>choice;
    if(choice==1)
    {
        MonoAlphabatic_Encryption(plainText);
    }
    else
    {
        //bygenery cyper algo.
        PolyAlphabatic_Encryption(plainText);
    }


}
