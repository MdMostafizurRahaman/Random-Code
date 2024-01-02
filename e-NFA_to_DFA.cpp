#include<bits/stdc++.h>
using namespace std;
int main()
{
    int state_no,alphabet_no,i,final_state_no,total_transition,j,k=0,n,p=1,cnt=0;
    char starting_state,q,q1;
    set<char>s,s1,s2,s3;
    vector<set<char>>v0,v1,vt,vt0,vt1,e_closure,epsilon;
    freopen("eNFA.txt","r",stdin);
    cout<<"Enter the total no of states of the NFA:"<<endl;
    cin>>state_no;
    n=state_no;
    char state[state_no+1];
    cout<<"Enter the states of the NFA:"<<endl;

    for(i=0;i<state_no;i++) {cin>>state[i];}
    cout<<"Enter the total no of alphabets of the NFA: "<<endl;

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
    cout<<"The transition functions of the NFA:"<<endl;

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
        if(total_transition) cout<<"Enter the transition:"<<endl;
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


        cout<<"Enter the number of transitions from del("<<state[i]<<","<<"e"<<"):"<<endl;
        cin>>total_transition;
        char abc;
        abc=state[i];
        //cout<<abc<<endl;
        //cout<<total_transition<<endl;

             //s.insert(abc);
            while(total_transition--)
            {
                cin>>q;
                s.insert(q);
            }
            q=state[i];
            //s.insert(q);
        //if(!total_transition) s.insert(abc);
        epsilon.push_back(s);
        s.clear();
    }

    for(i=0;i<n;i++)
    {
        set<char>sss;
        sss.insert(state[i]);
        queue<set<char>>que;
        que.push(epsilon[i]);
        while(que.size()>0)
        {
            int ii;
            set<char>st,st2;
            st=que.front();
            for(char u:st)
            {
              sss.insert(u);
            }
            que.pop();
            for(char cc: st)
            {
                for(ii=0;ii<state_no;ii++)
                {
                    if(state[ii]==cc)
                    {
                        st2=epsilon[ii];
                        if(st2.size()>1)
                        {
                            que.push(st2);
                        }
                        else {
                            for(char u:st2)
                            {
                                sss.insert(u);
                            }
                        }
                    }
                }
            }
        }
        e_closure.push_back(sss);
        sss.clear();
    }

    cout<<"epsilon transition: "<<endl;
    for(set<char>sss: epsilon)
    {
     for(char cc: sss)
     {
        cout<<cc<<" ";
     }
    cout<<endl;
    }
    cout<<"e-closure for each state: "<<endl;

  for(set<char>sss: e_closure)
  {
     for(char cc: sss)
     {
        cout<<cc<<" ";
     }
    cout<<endl;
  }


    //s=v1[0];
    //for(char r: s) cout<<r<<" "<<endl;
    cout<<endl<<"The details of the DFA of corresponding NFA:"<<endl<<endl;
    cout<<"Starting state of the DFA: ";
    set<char>sp;
    sp=e_closure[0];
    for(char xx: sp)
    {
        cout<<xx<<" ";
        s1.insert(xx);
    }
    cout<<endl<<endl;
    cout<<"The transition function of the DFA: "<<endl<<endl;

    //s1.insert(starting_state);
    vt.push_back(s1);
    int pp=0;

    while(1)
    {

        set<char>s33;
            cout<<"The transition from del({";
            s1=vt[k];
            for(char x: s1)
            {
                cout<<x<<" ";
                for(j=0;j<state_no;j++)
                {
                    if(state[j]==x) {s=v0[j];
                    for(char y: s)
                    {
                        for(int jj=0;jj<n;jj++)
                        {
                            if(state[jj]==y)
                            {
                                s33=e_closure[jj];
                                for(char z: s33) s2.insert(z);
                            }
                        }
                        s33.clear();
                        //s2.insert(y);
                    }
                    }
                }
            }
            s3=s1;
            s1.clear();
            cout<<"},0) is: { ";
            for(char ab: s2)
            {
                if(ab!='a'){
                s1.insert(ab);
                cout<<ab<<" ";}
            }
            p=1;
            for(set<char>ss: vt)
            {
                if(s1==ss){p=0;break;}
            }
            if(p) vt.push_back(s1);
            else cnt++;
            vt0.push_back(s2);
            s2.clear();
            cout<<"}"<<endl;

            cout<<"The transition from del({";
            for(char x: s3)
            {
                cout<<x<<" ";
                for(j=0;j<state_no;j++)
                {
                    if(state[j]==x) {s=v1[j];
                    for(char y: s)
                    {
                        for(int jj=0;jj<n;jj++)
                        {
                            if(state[jj]==y)
                            {
                                s33=e_closure[jj];
                                for(char z: s33) s2.insert(z);
                            }
                        }
                        s33.clear();
                        //s2.insert(y);
                    }
                    }
                }
            }
            s3.clear();
            s1.clear();
            cout<<"},1) is: { ";
            for(char ab: s2)
            {
                if(ab!='a'){
                s1.insert(ab);
                cout<<ab<<" ";}
            }
            p=1;
            for(set<char> ss: vt)
            {
                if(s1==ss){p=0;break;}
            }
            if(p) vt.push_back(s1);
            else cnt++;
            vt1.push_back(s2);
            s2.clear();
            cout<<"}"<<endl;
            //if(cnt==2) break;
            //else cnt=0;
            k++;
            pp++;
            if(pp==vt.size()) break;

    }
    cout<<endl;


    for(set<char>ss:vt){
    for( char ab: ss)
    {
        for(i=0;i<final_state_no;i++)
        {
            if(final_state[i]==ab) {p=1;break;}
        }
        if(p) {cout<<"Accepting state of the DFA: { ";
           for(char xy: ss)
           {
               cout<<xy<<" ";
           }
           cout<<"}"<<endl;
           break;
        };
    }
    }

 return 0;
}


