#include<bits/stdc++.h>
using namespace std;
int main()
{
    int state_no,alphabet_no,i,final_state_no,total_transition,j,k,n,p=0;
    char starting_state,q,q1;
    set<char>s,s1,s2;
    vector<set<char>>v0,v1;
    freopen("NFA.txt","r",stdin);
    cout<<"Enter the total no of states of the NFA:"<<endl;
    cin>>state_no;
    n=state_no;
    char state[state_no+1];
    cout<<"Enter the states of the NFA:"<<endl;

    for(i=0;i<state_no;i++) {cin>>state[i];}
    cout<<"Enter the total no of alphabets of the NFA:"<<endl;

    cin>>alphabet_no;
    int alphabet[alphabet_no];
    cout<<"Enter the alphabets of the NFA:"<<endl;


    for(i=0;i<alphabet_no;i++) cin>>alphabet[i];
    cout<<"Enter the starting state of the NFA:"<<endl;
    cin>>starting_state;
    cout<<"Enter the total no of final states of the NFA:"<<endl;

    cin>>final_state_no;
    char final_state[final_state_no+1];
    cout<<"Enter the final states of the NFA:"<<endl;
    for(i=0;i<final_state_no;i++) {cin>>final_state[i];}

    //for(char r: s) cout<<r<<" "<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"Enter the number of transitions from del("<<state[i]<<","<<alphabet[0]<<"):"<<endl;
        cin>>total_transition;
        if(total_transition) cout<<"Enter the transitions:"<<endl;
        if(!total_transition) s.insert('a');
        else{
            while(total_transition--)
            {
                cin>>q;
                s.insert(q);
            }
        }
        v0.push_back(s);
        s.clear();
        cout<<"Enter the number of transitions from del("<<state[i]<<","<<alphabet[1]<<"):"<<endl;
        cin>>total_transition;
        if(total_transition)cout<<"Enter the transitions:"<<endl;
        if(!total_transition) s.insert('a');
        else{
            while(total_transition--)
            {
                cin>>q;
                s.insert(q);
            }
        }
        v1.push_back(s);
        s.clear();
    }
    //s=v1[0];
    //for(char r: s) cout<<r<<" "<<endl;
    char str[200];
    cin>>str;
    s1.insert(starting_state);
    //for(char r: s1) cout<<r<<" "<<endl;
    cout<<endl<<"The transition function of the NFA:"<<endl;
    for(i=0;i<strlen(str);i++)
    {
        k=str[i]-'0';
        if(k==0)
        {
            cout<<"The transition from del( {";
            for(char x: s1)
            {
                cout<<x<<" ";
                for(j=0;j<state_no;j++)
                {
                    if(state[j]==x) {s=v0[j];
                    for(char y: s)
                    {
                        s2.insert(y);
                    }
                    }
                }
            }
            s1.clear();
            cout<<"},0) is: { ";
            for(char ab: s2)
            {
                if(ab!='a'){
                s1.insert(ab);
                cout<<ab<<" ";}
            }
            s2.clear();
            cout<<"}"<<endl;
        }
     if(k==1)
        {
            cout<<"The transition from del( {";
            for(char x: s1)
            {
                cout<<x<<" ";
                for(j=0;j<state_no;j++)
                {
                    if(state[j]==x) {s=v1[j];
                    for(char y: s)
                    {
                        s2.insert(y);
                    }
                    }
                }
            }
            s1.clear();
            cout<<"},1) is: { ";
            for(char ab: s2)
            {
                if(ab!='a'){
                s1.insert(ab);
                cout<<ab<<" ";}
            }
            s2.clear();
            cout<<"}"<<endl;
        }
    }
    for( char ab: s1)
    {
        for(i=0;i<final_state_no;i++)
        {
            if(final_state[i]==ab) {p=1;break;}
        }
        if(p) break;
    }
    if(p) cout<<str<<" is accepted by the NFA"<<endl;
    else cout<<str<<" is not accepted by the NFA"<<endl;
 return 0;
}
