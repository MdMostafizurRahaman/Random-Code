#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cfg1.txt","r",stdin);
    vector<string>V,T,v,save,e_parent;
    map<string,string>production_parent;
    //vector<vector<string>>P;
    int total_var, total_tar,t,tt;
    string S,str;
    cout<<"Number of variables: ";
    cin>>total_var;
    cout<<"\nThe variables: ";
    while(total_var--)
    {
        cin>>str;
        V.push_back(str);
    }
    cout<<"\nNumber of terminals: ";
    cin>>total_tar;
    cout<<"\nThe tarminals: ";
    while(total_tar--)
    {
        cin>>str;
        T.push_back(str);
    }
    cout<<"\nStart Symbol: ";
    cin>>S;
    vector<vector<string>>P,P_by_T,Str_by_P;
    cout<<"\nProductions: ";
    for(int i=0;i<V.size();i++)
    {
        int total_pro;
        cout<<"Number of productions for "<<V[i]<<": ";
        cin>>total_pro;
        cout<<"\nThe productions for "<<V[i]<<": ";
        while(total_pro--)
        {
            cin>>str;
            v.push_back(str);
            if(str!="e")production_parent[str]=V[i];
            else e_parent.push_back(V[i]);
        }
        P.push_back(v);
        v.clear();
    }

    for(string ps: T)
    {
        vector<string>v;
        for(vector<string>v1:P)
        {
            for(string sp:v1)
            {
                for(int i=0;i<sp.length();i++)
                {
                    string ps1="";
                    ps1+=sp[i];
                    if(ps==ps1) {v.push_back(sp);break;}
                }
            }
        }
        P_by_T.push_back(v);
    }

   /* cout<<"\nProductions: "<<endl;
    for(vector<string>v1:P_by_T)
    {
        for(string s:v1)
        {
            if(s!="e")cout<<s<<" "<<production_parent[s]<<" ";
            else
            {
                cout<<s<<" ";
                for(string s1: e_parent)
                    cout<<s1<<" ";
                cout<<endl;
            }
        }
        cout<<endl;
    }*/

    string ss;
    queue<string>Q;
    cout<<"Enter a string: ";
    cin>>ss;


    for(int i=0;i<ss.length();i++)
    {
        string ps="";
        ps+=ss[i];
        for(int j=0;j<T.size();j++)
        {
            if(ps==T[j])
            {
                vector<string>v;
                v=P_by_T[j];
                Str_by_P.push_back(v);
            }
        }
    }

    /*cout<<"\nstring by production: "<<endl;
    for(vector<string>v1:Str_by_P)
    {
        for(string s:v1)
        {
            if(s!="e")cout<<"str: "<<s<<" parent: "<<production_parent[s]<<" ";
            else
            {
                cout<<s<<" ";
                for(string s1: e_parent)
                    cout<<s1<<" ";
                cout<<endl;
            }
        }
        cout<<endl;
    }*/

    vector<int>start1;
    vector<string>start2(200,"");

    for(int i=0; i<Str_by_P.size();i++)
    {
        for(int j=0;j<Str_by_P[i].size();j++)
        {
            if(production_parent[Str_by_P[i][j]]==S) start1.push_back(i);
        }
    }

    for(int i=0; i<Str_by_P.size()-1;i++)
    {
        vector<string>v1=Str_by_P[i];
        vector<string>v2=Str_by_P[i+1];
        for(string s1:v1)
        {
            for(string s2:v2)
            {
                string s3="",s4,s5;
                s4=production_parent[s1];
                s5=production_parent[s1];
                s3+=(s4+s5);
                if(production_parent[s3]==S)
                {
                    start2[i]=s4;
                    start2[i+1]=s5;
                }
            }
        }
    }

    vector<vector<string>>final_;
    bool present=true,present1=true,can_be_derived=false,e_terminal=true;


    for(int k:start1)
    {
        vector<string>v1;
        vector<vector<string>>v2(2,vector<string>(ss.length(),""));
        v1=Str_by_P[k];
        for(string s1:v1)
        {
            //cout<<"k: "<<k<<endl;
            string left="", right="";
            if(production_parent[s1]==S)
            {
                v2[0][k]=S;
                v2[1][k]=s1;
                if(s1.length()==3)
                {
                    left+=s1[0];
                    right+=s1[2];
                }
                else
                {
                    left+=s1[0];
                    right+=s1[1];
                }

                e_terminal=false;
                for(string y:e_parent)
                {
                    if(y==left) e_terminal=true;
                }
                if(e_terminal)
                {
                    e_terminal=false;
                 for(string y:e_parent)
                 {
                    if(y==right) e_terminal=true;
                 }
                }
               //cout<<e_terminal<<endl;
            }

            for(int j=0;j<k;j++)
            {
                vector<string>v3=Str_by_P[j];
                present=false;
                for(string s3:v3)
                {
                    if(production_parent[s3]==left)
                    {
                      if(s3.length()==2){present=true;
                        v2[0][j]=left;

                        if(e_terminal)
                        {
                          e_terminal=false;
                         for(string y:e_parent)
                         {
                             if(y==left) e_terminal=true;
                         }
                        }

                        v2[1][j]=s3;
                        //cout<<"left"<<" "<<left<<" ";
                        left="";
                        left+=s3[1];
                      }
                    }
                }
                //if(j==k-1) {cout<<"ccc";present=true;}
                if(!present) break;
            }
            //cout<<e_terminal<<endl;
            for(int j=k+1;j<ss.length();j++)
            {
                vector<string>v3=Str_by_P[j];
                present1=false;
                for(string s3:v3)
                {
                    if(production_parent[s3]==right)
                    {
                      if(s3.length()==2){present1=true;
                        v2[0][j]=right;
                        if(e_terminal)
                        {
                          e_terminal=false;
                         for(string y:e_parent)
                         {
                             if(y==right) e_terminal=true;
                         }
                        }
                        v2[1][j]=s3;
                        //cout<<"right"<<" "<<right<<" ";
                        right="";
                        right+=s3[1];
                      }
                    }
                }
                //if(j==ss.length()-1) {cout<<"ddd";present1=true;}
                if(!present1) break;
            }
            //cout<<e_terminal<<endl;
           if(present&&present1) break;
        }

        if(present&&present1&&e_terminal) {can_be_derived=true;final_=v2;break;}
        else final_=v2;
    }

    if(can_be_derived) cout<<endl<<"The string "<<ss<<" has derivation : "<<endl;
    else cout<<endl<<"The string "<<ss<<" does not have derivation : "<<endl;

    for(int j=0;j<ss.length();j++)
    {
        if(final_[0][j]==S)
        {
            tt=j;
            //cout<<final_[0][j]<<" "<<j<<"::tt"<<final_[1][j]<<endl;
            cout<<S<<"=>"<<final_[1][j]<<endl;
            break;
        }
    }

    string sp=final_[1][tt];
    for(int j=0;j<ss.length();j++)
    {
       // string sp=final_[1][tt];;
       if((tt==0||tt==ss.length()-1)&&j==tt)
       {
            string st1="",st2;

            string st3=final_[1][tt],st4="";
            char ch;
            if(tt==0)
            {
                ch=st3[0];
                st4+=st3[0];
            }
            else{
                ch=st3[2];
                st4+=st3[2];
            }

            bool e_present=false;
            for(string st6:e_parent)
            {
                if(st4==st6) {e_present=true;break;}
            }
            if(!e_present) break;
            st1=sp;
            for(int p=0;p<sp.length();p++)
            {
                if(sp[p]==ch){st1[p]='e';}
            }

            cout<<sp<<"=>"<<st1<<endl;
            cout<<st1<<"=>";
            st1="";
            for(int p=0;p<sp.length();p++)
            {
                if(sp[p]!=ch){st1+=sp[p];}
            }
            sp=st1;st1="";
            cout<<sp<<endl;
        }
        if(j!=tt)
        {
            //cout<<j<<" "<<tt-1<<endl;
            if(j<tt-1)
            {
                //sp=final_[1][tt];
                string st1="",st2;

                st2=final_[1][j];
                //cout<<":00:"<<sp<<endl;
                if(st2.length()==0) break;
                st1+=st2[0];
                st1+=sp;

                cout<<sp<<"=>"<<st1<<endl;
                sp=st1;st1="";
                //cout<<":::"<<sp<<endl;
            }
            else if(j==tt-1)
            {
                string st1="",st2;
                st2=final_[1][j];
                if(st2.length()==0) break;
                st1+=st2[0];
                st1+=sp;

                cout<<sp<<"=>"<<st1<<endl;
                sp=st1;
                string st3=final_[1][tt],st4="";
                char ch=st3[0];
                st4+=st3[0];
                bool e_present=false;
                for(string st6:e_parent)
                {
                    if(st4==st6) {e_present=true;break;}
                }
                if(!e_present) break;

                for(int p=0;p<sp.length();p++)
                {
                    if(sp[p]==ch){st1[p]='e';}
                }

                cout<<sp<<"=>"<<st1<<endl;
                cout<<st1<<"=>";
                st1="";
                for(int p=0;p<sp.length();p++)
                {
                    if(sp[p]!=ch){st1+=sp[p];}
                }
                sp=st1;st1="";
                cout<<sp<<endl;
            }
            else if(j>tt&&j!=ss.length()-1)
            {
                 string st1="",st2;

                st2=final_[1][j];
                if(st2.length()==0) break;

                for(int p=0;p<sp.length()-1;p++)
                {
                    st1+=sp[p];
                }
                st1+=st2[0];
                st1+=sp[sp.length()-1];


                cout<<sp<<"=>"<<st1<<endl;
                sp=st1;st1="";
            }
            else if(j==ss.length()-1)
            {
                string st1="",st2;
                st2=final_[1][j];
                if(st2.length()==0) break;
                for(int p=0;p<sp.length()-1;p++)
                {
                    st1+=sp[p];
                }
                st1+=st2[0];
                st1+=sp[sp.length()-1];

                cout<<sp<<"=>"<<st1<<endl;
                sp=st1;
                string st3=final_[1][tt],st4="";
                char ch=st3[2];
                st4+=st3[2];
                bool e_present=false;
                for(string st6:e_parent)
                {
                    if(st4==st6) {e_present=true;break;}
                }
                if(!e_present) break;

                for(int p=0;p<sp.length();p++)
                {
                    if(sp[p]==ch){st1[p]='e';}
                }

                cout<<sp<<"=>"<<st1<<endl;
                cout<<st1<<"=>";
                st1="";
                for(int p=0;p<sp.length();p++)
                {
                    if(sp[p]!=ch){st1+=sp[p];}
                }
                sp=st1;st1="";
                cout<<sp<<endl;
            }
        }
    }

    for(int j=0;j<ss.length();j++)
    {
        cout<<ss[j]<<": "<<final_[0][j]<<"  : "<<final_[1][j]<<endl;
    }
    return 0;
}
