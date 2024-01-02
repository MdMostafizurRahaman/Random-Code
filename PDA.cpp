#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> stk;
    string input;
    cin >> input;
    int state = 0;

    for (int i = 0; i < input.length(); i++) {
        char symbol = input[i];

        switch (state) {
            /*case 0: // initial state
                if (symbol == '0') {
                    stk.push(symbol);
                    state = 1;
                } else {
                    cout << "Rejected" << endl;
                    return 0;
                }
                break;*/

            case 0: // read '0's
                if (symbol == '0') {
                        cout<<"state"<<0<<"push"<<0<<endl;
                    stk.push(symbol);
                } else if (symbol == '1'&&!stk.empty()) {
                     cout<<"state"<<0<<"to"<<1<<"by epsilon trans"<<endl;
                    state = 1;
                 cout<<"state"<<1<<"pop"<<0<<endl;
                    stk.pop();
                }
                else if (symbol == '1'&&stk.empty()){
                    cout<<state<<0<<"Stack empty"<<1<<"comes first"<<" rejected"<<endl;
                    return 0;
                }

                 else {
                    cout << "Rejected" << endl;
                    return 0;
                }
                break;

            case 1: // read '1's
                if (symbol == '1') {
                    if (!stk.empty()) {
                    cout<<"state"<<1<<"pop"<<0<<endl;
                        stk.pop();
                    } else {
                        cout << "symbol but stk empty Rejected" << endl;
                        return 0;
                    }
                } else {
                    cout << "unaccepted symbol Rejected" << endl;
                    return 0;
                }
                break;
        }
    }

    if (state == 1 && stk.empty()) {
            cout<<"state"<<1<<"to"<<2<<"by epsilon trans"<<endl;
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }

    return 0;
}
