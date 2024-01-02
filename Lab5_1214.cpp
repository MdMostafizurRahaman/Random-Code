#include<bits/stdc++.h>
#define StackSize 100000
using namespace std;
typedef long long ll;
char stack1[StackSize];
string state="q0";
ll ind=0;
void push(char value){
	if(ind>=StackSize){
		cout<<"Stack is full!"<<endl;
		return;
	}
	stack1[ind++]=value;
}
void pop(){
	if(ind<0){
		cout<<"Stack is empty!"<<endl;
		return;
	}
	ind--;
}
void changeState(ll i, ll strLen){
    //cout<<i<<" "<<strLen<<" "<<ind<<endl;
	if(ind==1&&i==strLen){
		state="q2";
	}
	else{
		state="q1";
	}
}
void printState(ll i,string str){
    //cout<<i<<" "<<ind<<endl;
	ll len=str.length();
	cout<<state;
	cout<<"-------";
	for(ll k=i+1;k<len;k++)cout<<str[k];
	if(i+1==str.length())cout<<"epsilon";
	cout<<"-------";
	for(ll k=ind-1;k>=0;k--)cout<<stack1[k];
	cout<<endl;

}
int main()
{
	ios::sync_with_stdio(false);
	string sampleString;
	cin>>sampleString;
	ll centerIndex=sampleString.length()/2;
	push('Z');

	printState(-1,sampleString);
	ll i;
	for(i=0;sampleString[i]!='\0';i++){
		if(sampleString[i]==stack1[ind-1]&&i>=centerIndex){
		    //cout<<i<<" "<<centerIndex<<endl;
			pop();
			changeState(i, sampleString.length());
		}
		else{
			push(sampleString[i]);
		}
		printState(i, sampleString);
	}
	if(ind==1)
	    changeState(i,sampleString.length());
	printState(i, sampleString);
	if(state=="q2")cout<<"Accepted"<<endl;
	else cout<<"Rejected"<<endl;

	return 0;
}