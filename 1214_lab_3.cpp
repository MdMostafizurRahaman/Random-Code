#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll stateNum;
    cout<<"Enter the number of states: "<<endl;
    cin>>stateNum;

    ll startState;
    cout<<"Enter the start state: "<<endl;
    cin>>startState;
    ll finalStateNum;
    cout<<"How many final states: "<<endl;
    cin>>finalStateNum;
    map<ll,bool>finalState;
    cout<<"Enter the final state(s): "<<endl;
    for(ll i=0;i<finalStateNum;i++){
        ll f;
        cin>>f;
        finalState[f]=true;
    }
    
    ll symbolNum;
    cout<<"Enter the number of symbols: "<<endl;
    cin>>symbolNum;
    vector<char>symbols;
    cout<<"Enter symbols: "<<endl;
    for(ll i=0;i<symbolNum;i++){
        char symbol;
        cin>>symbol;
        symbols.push_back(symbol);
    }
    map<pair<ll,char>,vector<ll>>transition_table;
    for(ll i=1;i<=stateNum;i++){
        cout<<"Enter transition function for state "<<i<<endl;
        for(auto x: symbols){
            cout<<"For input "<<x<<": "<<endl;
            while(1){
                ll state;
                cin>>state;
                if(state==-1)break;
                transition_table[{i,x}].push_back(state);
            }
        }
    }
    queue<set<ll>>q;
    set<ll>cur;
    map<set<ll>,bool>check;
    cur.insert(startState);
    q.push(cur);
    check[cur]=true;
    do{
        cur=q.front();
        q.pop();
        for(auto x:symbols){
            set<ll>dState;
            cout<<"{";
            for(auto y:cur){
                cout<<y<<",";
                for(auto z:transition_table[{y,x}]){
                    dState.insert(z);
                }
            }
            if(dState.size()==0){
                dState.insert(stateNum+1);
            }
            if(check[dState]==false){
                q.push(dState);
                check[dState]=true;
            }
            cout<<"}----"<<x<<"---->{";
            for(auto y:dState){
                cout<<y<<",";
            }
            cout<<"}"<<endl;
        }
    }while(!q.empty());
}