#include <bits/stdc++.h>
using namespace std;
#define N 100

int nfa_numberOfStates;
char nfa_states[N];
char nfa_starting_state;
int nfa_numberOfFinalStates;
char nfa_final_states[N];
string nfa_transitions[N][N]; // indexing(states) according to the order of nfa_states

char dfa_starting_state;
string dfa_states[N];
string dfa_transitions[N][N];
int number_of_dfa_states = 0;

set <string> done;
queue <string> to_be_done; 

int findIndex(char c){
    for(int i=0; i<nfa_numberOfStates; i++){
        if(c==nfa_states[i])
            return i;
    }
    return -1;
}

void generateDFA(){
    dfa_starting_state = nfa_starting_state;
    dfa_states[0] = dfa_starting_state;
    number_of_dfa_states++;
    done.insert(dfa_states[0]);
    int index = findIndex(dfa_starting_state);
    dfa_transitions[0][0] = nfa_transitions[index][0];
    dfa_transitions[0][1] = nfa_transitions[index][1];
    to_be_done.push(nfa_transitions[index][0]);
    to_be_done.push(nfa_transitions[index][1]);

    int dfa_state_index = 1;
    bool flag = true;
    while(!to_be_done.empty()){
        string temp = to_be_done.front();
        to_be_done.pop();
        if(done.count(temp))
            flag = false;
        else 
            flag = true;
        
        if(flag){
            done.insert(temp);
            dfa_states[dfa_state_index] = temp;
            number_of_dfa_states++;

            string zero_temp, one_temp;
            for(int i=0; i<temp.size(); i++){
                char c = temp[i];
                if(c != ' '){
                    int index = findIndex(c);
                    zero_temp += nfa_transitions[index][0];
                    one_temp += nfa_transitions[index][1];
                }
            }
            // geting unique elements
            set<char> temp;
            for(int i=0; i<zero_temp.size(); i++){
                if(zero_temp[i]!= ' ')
                    temp.insert(zero_temp[i]);
            }
            zero_temp.clear();
            set<char>:: iterator it;
            for( it = temp.begin(); it!=temp.end(); ++it){
                zero_temp += *it;
                zero_temp += ' ';
            }

            temp.clear();
            for(int i=0; i<one_temp.size(); i++){
                if(one_temp[i]!= ' ')
                    temp.insert(one_temp[i]);
            }
            one_temp.clear();
            set<char>:: iterator it1;
            for( it1 = temp.begin(); it1!=temp.end(); ++it1){
                one_temp += *it1;
                one_temp += ' ';
            }

            zero_temp = zero_temp.substr(0, zero_temp.size()-1);
            one_temp = one_temp.substr(0, one_temp.size()-1);
            dfa_transitions[dfa_state_index][0] = zero_temp;
            dfa_transitions[dfa_state_index][1] = one_temp;
            dfa_state_index++;
            to_be_done.push(zero_temp);
            to_be_done.push(one_temp);
        }
    }
}

void printDFA(){
    for(int i=0; i<number_of_dfa_states; i++){
        string t = dfa_states[i];
        if(t.length()==0)
            dfa_states[i] = "phi";
    }

    cout<<endl<<"--------DFA-------"<<endl;
    cout<<"DFA statring state: "<<dfa_starting_state<<endl;
    cout<<"DFA final states: ";
    
    for(int i=0; i<number_of_dfa_states; i++){
        string temp = dfa_states[i];
        bool flag = false;
        for(int j=0; j<temp.size(); j++){
            for(int k=0; k<nfa_numberOfFinalStates; k++){
                if(nfa_final_states[k]==temp[j]){
                    flag = true;
                }
            }
        }
        if(flag){
            if(temp.size()==0)
                cout<<"phi"<<"  ";
            else cout<<temp<<"   ";
        }
    }
    cout<<endl<<"-----------DFA Transitions----------"<<endl;
    cout<<"states\t\tusing 0\t\tusing 1"<<endl;
    for(int i=0; i<number_of_dfa_states; i++){
        cout<<dfa_states[i]<<"\t\t";
        string s = dfa_transitions[i][0];
        if(s.length()==0)
            cout<<"phi\t\t";
        else
            cout<<s<<"\t\t";

        string str = dfa_transitions[i][1];
        if(str.length()==0)
            cout<<"phi\t\t"<<endl;
        else
            cout<<str<<"\t\t"<<endl;
    }
}

int main(void){
    freopen("nfaToDfa.txt", "r", stdin);
    //freopen("nfa.txt", "r", stdin);
    cout<<"Enter number of states of NFA: ";
    cin>>nfa_numberOfStates;
    cout<<endl;

    // taking states
    cout<<"Enter the states of NFA: ";
    for(int i=0; i<nfa_numberOfStates; i++){
        cin>>nfa_states[i];
    }
    cout<<endl;

    // taking starting state
    cout<<"Enter the starting state of NFA: ";
    cin>>nfa_starting_state;
    cout<<endl;

    // taking number of final state
    cout<<"Enter the number of final states of NFA: ";
    cin>>nfa_numberOfFinalStates;
    cout<<endl;

    // taking final states
    cout<<"Enter the final states of NFA: ";
    for(int i=0; i<nfa_numberOfFinalStates; i++){
        cin>>nfa_final_states[i];
    }
    cout<<endl;

    // transitions of nfa
    cout<<"Enter the transitions: "<<endl;
    for(int i=0; i<nfa_numberOfStates; i++){
        cout<<nfa_states[i]<<" using 0 goes to: ";
        cout<<"(enter the states (enter 'x' to stop))";
        char c;
        string s;
        cin>>c;
        while(c!='x'){
            s += c;
            s += ' ';
            cin>>c;
        }
        s = s.substr(0, s.size()-1); // to remove the last whitespace
        nfa_transitions[i][0] = s;
        cout<<endl;

        cout<<nfa_states[i]<<" using 1 goes to: ";
        cout<<"(enter the states (enter 'x' to stop))";
        char ch;
        string t;
        cin>>ch;
        while(ch!='x'){
            t += ch;
            t += ' ';
            cin>>ch;
        }
        t = t.substr(0, t.size()-1); // to remove the last whitespace
        nfa_transitions[i][1] = t;
        cout<<endl;
    }

    // cout<<"-----------NFA----------"<<endl;
    // for(int i=0; i<nfa_numberOfStates; i++){
    //     cout<<nfa_states[i]<<" using 0 goes to: "<<nfa_transitions[i][0]<<endl;
    //     cout<<nfa_states[i]<<" using 1 goes to: "<<nfa_transitions[i][1]<<endl;
    // }

    generateDFA();
    printDFA();

    return 0;
}