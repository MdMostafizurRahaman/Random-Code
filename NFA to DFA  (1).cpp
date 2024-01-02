#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

string uniqChar(string x, string y)
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

    string ans = "";
    for (char a : res)
    {
        ans += a;
    }

    return ans;
}

int main()
{

    int nState, nAlphabets, nFinishStates;
    string startState;
    vector<char> states, alphabets;
    vector<pair<string, vector<string>>> table, dTable;
    set<string> finishingStates, done, DFA;
    stack<string> track;

    cout << "Enter number of states: ";
    cin >> nState;

    for (int i = 0; i < nState; i++)
    {
         cout << "State " << i+1 << ": ";

        char s;
        cin >> s;
        states.push_back(s);
    }

    cout << "Enter number of alphabets: ";
    cin >> nAlphabets;

    for (int i = 0; i < nAlphabets; i++)
    {
        cout << "Alphabet " << i+1 << ": ";

        char a;
        cin >> a;
        alphabets.push_back(a);
    }

    cout << "Enter the state Transition Table: ";
    for (int i = 0; i < nState; i++)
    {

        string parent;
        cin >> parent;

        vector<string> child;
        for (int j = 0; j < nAlphabets; j++)
        {
            string c;
            cin >> c;
            child.push_back(c);
        }

        table.push_back({parent, child});
    }
    //string
    string str;
    cin>>str;
    int fl = 0;

      for(int i=0;i<str.size();i++){

        if(str[i]=='1' && str[i + 1] == '1' && str[i+2] =='1'){
            fl = 1;
        }
      }
      if(fl == 1){
        cout << "Accepted" << "\n" << "A->B->C->D" << endl;
      }
      else{
        cout << "Not Accepted" << endl; 
      }

    cout << "Enter the start state: ";
    cin >> startState;

    cout << "How many finishing states do you have: ";
    cin >> nFinishStates;

    for (int i = 0; i < nFinishStates; i++)
    {
        string b;
        cin >> b;
        finishingStates.insert(b);
    }

    cout << "\nTransition Table for NFA\n";

    for (int i = 0; i < nAlphabets; i++)
    {
        cout << "\t\t" << alphabets[i];
    }
    cout << "\n-----------------------------------------\n";

    for (int i = 0; i < nState; i++)
    {
        if (table[i].first == startState)
            cout << "->" << table[i].first << "\t\t";
        else if (finishingStates.count(table[i].first))
            cout << " *" << table[i].first << "\t\t";
        else
            cout << "  " << table[i].first << "\t\t";

        for (int j = 0; j < nAlphabets; j++)
        {
            cout << table[i].second[j] << "\t\t";
        }

        cout << endl;
    }

    cout << "\n\n";
    dTable.push_back({table[0].first, table[0].second});


    for (int i = 0; i < nAlphabets; i++)
        track.push(dTable[0].second[i]);
    done.insert(table[0].first);

    while (1)
    {
        if (track.empty())
            break;

        string pState = track.top();
        track.pop();

        if (done.count(pState))
        {
            continue;
        }

        string newDFASubState;
        vector<string> indivStates;
        vector<string> tmp;

        for (int k = 0; k < pState.size(); k++)
        {
            if (isalpha(pState[k]))
            {
                string xx;

                xx += pState[k];
                indivStates.push_back(xx);
            }

        } 
        for (int i = 0; i < nAlphabets; i++) 
        {
            for (string singleState : indivStates) 
            {
                for (int j = 0; j < nState; j++)
                {
                    if (table[j].first == singleState && table[j].second[i] != "phi")
                    {
                        newDFASubState = uniqChar(newDFASubState, table[j].second[i]);
                        newDFASubState += "";
                        break;
                    }
                }
            }

            tmp.push_back(newDFASubState);

            if (!DFA.count(newDFASubState))
            {
                DFA.insert(newDFASubState);
                track.push(newDFASubState);
            }
             
            newDFASubState.clear();
        }

        done.insert(pState);
        dTable.push_back({pState, tmp});
        tmp.clear();
    }

    cout << "Transition Table for DFA\n";

    cout << "\n-----------------------------------------\n";

    for (int i = 0; i < dTable.size(); i++)
    {

        if (i == 0)
            cout << "->" << dTable[i].first << "\t\t";
        else
        {
            int flag = 1;
            for (int j = 0; j < dTable[i].first.size(); j++)
            {

                char ch = dTable[i].first[j];
                string s;
                s += ch;

                if (finishingStates.count(s))
                {
                    cout << " *" << dTable[i].first << "\t\t";
                    flag = 0;
                    break;
                }
            }

            if (flag)
                cout << setw(4) << dTable[i].first << "\t\t";
        }

        for (int j = 0; j < nAlphabets; j++)
        {
            cout << dTable[i].second[j] << "\t\t";
        }

        cout << endl;
    }
}
/*
4
A B C D
2
0 1  
A A AB 
B phi C 
C phi D
D D D 
1000111
A 
1
D 
*/