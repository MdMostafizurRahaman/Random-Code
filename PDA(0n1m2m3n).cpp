#include<iostream>
#include<stack>
using namespace std;
stack<char> w;
int i,track=-1;
void convert_char(char c)
{
    w.push(c);
}
void pda(string s,int n)
{


 for(i=0;i<n;i++)
 {
   if(s[i]=='0'&&s[i-1]!='3')
        {track=0;
        convert_char(s[i]);}

 else if(s[i]=='1'&&track==0)
 {  convert_char(s[i]);}
 else if(s[i]=='2'){
     if(w.top()=='1')
        w.pop();
        else
            break;
        }
else if(s[i]=='3')
{
   if(w.top()!='0')
        break;
  else
    w.pop();
 }}
 if(w.top()=='z'&&i==n)
    cout<<"accepted"<<endl;
else
    cout<<"not accepted";


}

int main()
{
    w.push('z');
    string s;
    cout<<"enter the input string"<<endl;
    cin>>s;
    pda(s,s.size());

}

