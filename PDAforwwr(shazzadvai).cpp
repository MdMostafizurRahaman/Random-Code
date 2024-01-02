//PDA for L = {wwR; w ∈ (a, b)*}

#include<iostream>
#include<stack>

using namespace std;

stack<char> w;
int cs=0;

void q0(char c)
{
    char prevTop=w.top();
    w.push(c);
    cout<<"T(q0, "<<c<<", "<<prevTop<<") -> (q0, "<<c<<prevTop<<")\n";
}

bool q1(char c)
{
    if(c==w.top())
    {
        cout<<"T(q1, "<<c<<", "<<w.top()<<") -> (q1, E)\n";
        w.pop();
    }
    return false;
}

bool PDA(string s, int l)
{
    bool flag=false;
    for(int i=0; i<s.length(); i++)
    {
        if(i==l/2)
        {
            cs=1;
            cout<<"T(q0, "<<s[i]<<", "<<w.top()<<") -> (q1, E)\n";
            if(s[i]==w.top())
                w.pop();
            continue;
        }
        if(cs==0)
            q0(s[i]);
        else if(cs==1)
            flag=q1(s[i]);
    }
    if(l%2!=0)
        return false;
    if(w.top()=='z')
    {
        cout<<"T(q1, E, z) -> (qf, z)\n";
        return true;
    }
    return flag;
}

int main()
{
    w.push('z');
    string s;
    cout<<"Enter string: ";
    cin>>s;
    cout<<"\nTransitions: \n";
    (PDA(s, s.length()))?
        cout<<"\nAccepted\n" : cout<<"\nRejected\n";
}
