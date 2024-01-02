#include<bits/stdc++.h>
#define p 1
#define q 2
#define r 3
#define final 3
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    ll state[4][2];

    state[p][0]=p;
    state[p][1]=q;

    state[q][0]=p;
    state[q][1]=r;

    state[r][0]=p;
    state[r][1]=r;

    string str;
    cout<<"Enter a string consisting of 0's and 1's only: ";
    cin>>str;

    ll curr=p;
    for(ll i=0;str[i]!='\0';i++){
        (curr==p)?cout<<"p":(curr==q)?cout<<"q":cout<<"r";
        cout<<"->";

        if(str[i]=='0')curr=state[curr][0];
        else if(str[i]=='1')curr=state[curr][1];
        
        else{
            cout<<"\nInvalid string: should contain only zero and one."<<endl;
            exit(0);
        }
        (curr==p)?cout<<"p":(curr==q)?cout<<"q":cout<<"r";
        cout<<" on input "<<str[i]<<endl;
    }
    cout<<endl;
    if(curr==final)cout<<"Accepted"<<endl;
    else cout<<"Rejected"<<endl;
    return 0;
}