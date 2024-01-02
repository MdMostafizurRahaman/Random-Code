#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "00*1(0+1)*" << endl;
    cout << "S-->0A1B" << endl;
    cout << "A-->0A|e" << endl;
    cout << "B-->0B|1B|e" << endl;
    cout << "Enter String:";
    cin >> s;
    bool flag = false;
    int number_of_zero = 0;
    // acceptation check
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            number_of_zero++;
        }
    }
    if (number_of_zero == s.size())
    {
        cout << "Not Accepted" << endl;
        flag = false;
    }
    else
    {
        cout << "Accepted" << endl;
        flag = true;
    }
    // concatanation
    if (flag)
    {
        string sA, sB;
        int i, j;

        for (i = 0; i < s.size(); i++)
        {
            if (s[0] == '1')
            {
                sA = '\0';
                sB = s.substr(1, s.size() - 1);
                break;
            }
            else if (s[i] == '1' && i != 0)
            {
                sA = s.substr(0, i);
                sB = s.substr(i + 1, (s.size() - 1));
                break;
            }
        }
        cout << "Left Most Derivation" << endl;
        cout << "S-->0A1B\n -->";
        string temp, temp2;
        temp.push_back('A');
        for (int i = 1; i < sA.size(); i++)
        {
            if (sA[i] == '\0')
                break;
            temp = "0" + temp;
            cout << "0" << temp << "1B\n"
                 << " -->";
        }
        temp.pop_back();
        cout <<"0" << temp << "1B\n"
             << " -->";

        temp2.push_back('B');
        for (int i = 0; i < sB.size(); i++)
        {

            if (sB[i] == '0')
            {
                temp2.pop_back();
                temp2 += "0B";
                cout <<"0" << temp << "1" << temp2 << "\n -->";
            }
            else
            {
                temp2.pop_back();
                temp2 += "1B";
                cout << "0" << temp << "1" << temp2 << "\n -->";
            }
        }
        temp2.pop_back();
        cout << "0" << temp << "1" << temp2;
    }
}