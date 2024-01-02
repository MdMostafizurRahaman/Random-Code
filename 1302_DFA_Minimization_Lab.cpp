#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("DFA_min.txt","r",stdin);
    int no_of_states, no_of_alphabets, no_of_final_states;
    string starting_state,str;
    vector<string>states,final_states,alphabets;

    cout<<"Enter the number of states: ";
    cin>>no_of_states;
    cout<<"\nEnter states: ";
    for(int i=0;i<no_of_states;i++)
    {
        string str;
        cin>>str;
        states.push_back(str);
    }
    cout<<"\nEnter the starting state: ";
    cin>>starting_state;

    cout<<"\nEnter the number of alphabets: ";
    cin>>no_of_alphabets;
    cout<<"\nEnter alphabets: ";
    for(int i=0;i<no_of_alphabets;i++)
    {
        string str;
        cin>>str;
        alphabets.push_back(str);
    }

    cout<<"\nEnter the number of final states: ";
    cin>>no_of_final_states;
    cout<<"\nEnter the final states: ";
    for(int i=0;i<no_of_final_states;i++)
    {
        string str;
        cin>>str;
        final_states.push_back(str);
    }

    vector<vector<string>>del(no_of_states,vector<string>(no_of_alphabets)),Equivalent_states(no_of_states);
    cout<<"\nEnter the transitions: ";

    for(int i=0;i<no_of_states;i++)
    {
        for(int j=0;j<no_of_alphabets;j++)
        {
            cout<<"\nEnter the transition for del("<<states[i]<<","<<alphabets[j]<<")-> ";
            cin>>str;
            del[i][j]=str;
        }
    }

    for(int i=0;i<no_of_states;i++)
    {
        Equivalent_states[i].push_back(states[i]);
        for(int j=0;j<no_of_alphabets;j++)
        {
            cout<<"\nThe transition for del("<<states[i]<<","<<alphabets[j]<<")-> "<<del[i][j];

        }
    }

   for(int i=0;i<no_of_states-1;i++)
   {
       for(int j=i+1;j<no_of_states;j++)
       {
          bool visited[no_of_alphabets] ={false},eqv=true;;
          int m=i,n=j,cnt=0,a1=0,b1=0;
          queue<int>q1;
          q1.push(i);q1.push(j);

          //if(states[i]==starting_state) a1=1;
          //if(states[j]==starting_state) b1=1;
          for(int p=0;p<no_of_final_states;p++)
          {
               if(states[i]==final_states[p]) a1=2;
               if(states[j]==final_states[p]) b1=2;
          }
          if(a1!=b1) {eqv=false;}
          while(eqv&&cnt<20)
          {
              m=q1.front();
              q1.pop();
              n=q1.front();
              q1.pop();

              for(int k=0;k<no_of_alphabets;k++)
              {
                  string str1=del[m][k];
                  string str2=del[n][k];
                  int a=0,b=0;
                  //if(str1==starting_state) a=1;
                  //if(str2==starting_state) b=1;
                  for(int p=0;p<no_of_final_states;p++)
                  {
                      if(str1==final_states[p]) a=2;
                      if(str2==final_states[p]) b=2;
                  }
                  for(int p=0;p<no_of_states;p++)
                  {
                      if(states[p]==str1) {q1.push(p);}
                      if(states[p]==str2) {q1.push(p);}
                  }
                  if(a!=b) {eqv=false;break;}
              }
              if(!eqv) break;
              cnt++;
          }
          if(eqv)
          {
              bool present=false;
              for(int p=0;p<i;p++)
              {
                  for(string s:Equivalent_states[p])
                  {
                      if(s==states[j]) present=true;
                  }
              }
              if(!present)
              {
                  Equivalent_states[i].push_back(states[j]);
                  Equivalent_states[j].erase(Equivalent_states[j].begin(),Equivalent_states[j].end());
              }
          }
       }
   }

    cout<<endl<<endl<<"Equivalent states: "<<endl;
    for(vector<string>v:Equivalent_states)
    {
        if(v.size()>1){
        for(string s: v)
        {
            cout<<s<<" ";
        }
        cout<<endl;}
    }

    map<string,string>eqv_state;
    vector<vector<string>>min_DFA_table;
    vector<string>min_final,min_states;
    string min_start;

    for(vector<string>v:Equivalent_states)
    {
        if(v.size()>1)
        {
            string eqi="#";
            for(string s: v)
            {
               if(s==starting_state)
               {
                   eqi=s;min_start=s;break;
               }
            }
            if(eqi=="#")
            {
                eqi=v[0];
                for(string s4: final_states)
                {
                    //cout<<s4<<" ee "<<eqi<<endl;
                    if(eqi==s4) {min_final.push_back(eqi);break;}
                }
            }
            for(string s: v)
            {
                if(s!=eqi)
                {
                    eqv_state[s]=eqi;
                }
            }
            eqv_state[eqi]="*";
        }
        else if(v.size()==1)
        {
            eqv_state[v[0]]="*";
            for(string s4: final_states)
            {
                if(v[0]==s4) {min_final.push_back(v[0]);break;}
            }
        }
    }

    for(int i=0;i<del.size();i++)
    {
        vector<string>v1;
        for(int j=0;j<alphabets.size();j++)
        {
            string s1=states[i],s2;
            if(eqv_state[s1]!="*") break;
            s2=del[i][j];
            if(eqv_state[s2]!="*") v1.push_back(eqv_state[s2]);
            else v1.push_back(s2);
        }
        if(v1.size()>0) {min_states.push_back(states[i]);min_DFA_table.push_back(v1);}
        v1.clear();
    }

    cout<<endl<<"Starting state of minimized DFA: "<<min_start<<endl<<endl;

    for(int i=0;i<min_DFA_table.size();i++)
    {
        for(int j=0;j<min_DFA_table[i].size();j++)
        {
            cout<<"Transition for del("<<min_states[i]<<","<<alphabets[j]<<") -> "<<min_DFA_table[i][j]<<endl;
        }
    }

    cout<<endl<<"Final states of minimized DFA: ";
    for(string s: min_final)
    {
        cout<<s<<" ";
    }
    cout<<endl;

 return 0;
}

