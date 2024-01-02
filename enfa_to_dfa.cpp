#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

string unique_symbol(string x, string y);

int main()
{

    int number_of_States, number_of_symbol, number_of_FinishStates;
    string startingState;
    vector<char> states, symbol;
    
    cout << "Enter number of states: \n";

    cin >> number_of_States;
    cout<<"Enter states\n";
    for (int i = 0; i < number_of_States; i++)
    {
        cout << "State " << i+1 << ": ";

        char s;
        cin >> s;
        states.push_back(s);
        cout<<endl;
    }

    cout << "Enter number of alphabets: \n";
    cin >> number_of_symbol;

    symbol.push_back('e');
    cout<<"Enter alphabets\n";
    for (int i = 0; i < number_of_symbol; i++)
    {
        cout << "Alphabet " << i+1 << ": ";

        char a;
        cin >> a;
        symbol.push_back(a);
        cout<<endl;
    }

    number_of_symbol += 2; // for e closure
    vector<pair<string, vector<string>>> enfa_table, FinalAns;
    vector<pair<string, string>> dfa_Table, eClosure;
    set<string> finishingStates, done, DFA;
    stack<string> track;


    cout << "Enter the state Transition Table for E-NFA\n";
    for (int i = 0; i < number_of_States; i++)
    {

        string parent;
        cin >> parent;

        vector<string> child;
        string eChild;
        eChild += parent;

        for (int j = 0; j < number_of_symbol - 1; j++)
        {
            string c;
            cin >> c;
            child.push_back(c);

            if (j == 0 and c != "phi")//make eclosure
                eChild += c; // only for e closure
        }

        enfa_table.push_back({parent, child});
        eClosure.push_back({parent, eChild});
    }

    cout << "Enter the start state:\n ";
    cin >> startingState;

    cout << "How many finishing states do you have:\n ";
    cin >> number_of_FinishStates;
    cout<<"Enter finishing states\n";
    for (int i = 0; i < number_of_FinishStates; i++)
    {
        string b;
        cin >> b;
        finishingStates.insert(b);
    }

    //--------------------------------------OUTPUT 1---------------------------------------

    cout << "\nTransition Table for E-NFA\n";
    // header of the enfa_table
    for (int i = 0; i < number_of_symbol ; i++) 
    {
        cout << "\t\t" << symbol[i];
    }

    
    cout << "e*";
    cout << "\n--------------------------------------------------------------------\n";

    // print enfa_table info
    for (int i = 0; i < number_of_States; i++)
    {
        if (enfa_table[i].first == startingState)
            cout << "->" << enfa_table[i].first << "\t\t";
        else if (finishingStates.count(enfa_table[i].first))
            cout << " *" << enfa_table[i].first << "\t\t";
        else
            cout << "  " << enfa_table[i].first << "\t\t";

        for (int j = 0; j < number_of_symbol; j++)
        {
            if (j == number_of_symbol - 1)
            {
                cout << eClosure[i].second;
            }
            else
            {
                cout << enfa_table[i].second[j] << "\t\t";
            }
        }

        cout << endl;
    }

    cout << "\n\n";

    //--------------------------------------ENFA TO DFA PROCESSING---------------------------------------
    dfa_Table.push_back({enfa_table[0].first, eClosure[0].second});

    track.push(dfa_Table[0].second);

    while (1)
    {
        if (track.empty())
            break;

        string epsilon_closure = track.top();
        track.pop();

        if (done.count(epsilon_closure) or epsilon_closure == "X")
        {
            continue;
        }

        string newDFASubState;
        vector<string> indivStates;
        vector<string> tmp;

        // extract states from the clutter
        for (int k = 0; k < epsilon_closure.size(); k++)
        {
            if (isalpha(epsilon_closure[k]))
            {
                string separate;

                separate = epsilon_closure[k];
                indivStates.push_back(separate);
            }

        }
        for (int i = 1; i < number_of_symbol - 1; i++) // 0
        {
            for (string singleState : indivStates) // first A and then B
            {
                for (int j = 0; j < number_of_States; j++)
                {
                    if (enfa_table[j].first == singleState)
                    {
                        string toFind = enfa_table[j].second[i];
                        for (int c = 0; c < toFind.size(); c++) 
                        {
                            for (int k = 0; k < number_of_States; k++)
                            {
                                string point = "";
                                point = toFind[c];

                                if (enfa_table[k].first == point)
                                {
                                    newDFASubState = unique_symbol(newDFASubState, eClosure[k].second);
                                    newDFASubState += "";
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if(newDFASubState.size() == 0) newDFASubState = "X";
            tmp.push_back(newDFASubState);

            if (!DFA.count(newDFASubState))
            {
                DFA.insert(newDFASubState);
                track.push(newDFASubState);
            }
            newDFASubState.clear();
        }

        done.insert(epsilon_closure);
        FinalAns.push_back({epsilon_closure, tmp});
        for (string u : tmp)
        {
            dfa_Table.push_back({epsilon_closure, u}); // ==>
        }
        tmp.clear();
    }

    // //--------------------------------------FINAL OUTPUT---------------------------------------

    cout << "\nTransition Table for DFA\n";
    // header of the enfa_table
    for (int i = 1; i < number_of_symbol-1; i++)
    {
        cout << "\t\t" << symbol[i];
    }

    cout << "\n-----------------------------------------\n";

    // DFA enfa_table info
    for (int i = 0; i < FinalAns.size(); i++)
    {

        if (i == 0)
            cout << "->" << FinalAns[i].first << "\t\t";
        else
        {
            int flag = 1;
            for (int j = 0; j < FinalAns[i].first.size(); j++)
            {

                char ch = FinalAns[i].first[j];
                string s;
                s += ch;

                if (finishingStates.count(s))
                {
                    cout << " *" << FinalAns[i].first << "\t\t";
                    flag = 0;
                    break;
                }
            }

            if (flag)
                cout << setw(4) << FinalAns[i].first << "\t\t";
        }

        for (int j = 0; j < number_of_symbol - 2; j++)
        {
            cout << FinalAns[i].second[j] << "\t\t";
        }

        cout << endl;
    }
}

string unique_symbol(string x, string y)
{
    set<char> res;

    for (int i = 0; i < x.size(); i++)
    {
        if (!res.count(x[i]))
            res.insert(x[i]);
    }

    for (int i = 0; i < y.size(); i++)
    {
        if (!res.count(y[i]))
            res.insert(y[i]);
    }

    string ans;
    for (char a : res)
    {
        ans+= a;
    }

    return ans;
}

/*

3
A B C
2
a b
A B C phi
B phi A phi
C phi B BC
A
1
C

*/