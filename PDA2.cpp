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

            case 0: // read '0's
                if (symbol == '0') {
                        cout<<"state"<<0<<"push"<<0<<endl;
                    stk.push(symbol);
                    cout<<"state"<<0<<"to"<<1<<"by epsilon trans"<<endl;
                    state=1;
                } else if (symbol == '1'&&!stk.empty()) {
                     cout<<"state"<<0<<"to"<<2<<"by epsilon trans"<<endl;
                    state = 2;
                 cout<<"state"<<2<<"pop"<<stk.top()<<endl;
                    stk.pop();
                }
                else if (symbol == '1'&&stk.empty()){
                    cout<<state<<0<<"Stack empty"<<1<<"comes first"<<" rejected"<<endl;
                    return 0;
                }

                 else {
                    cout << "unexpected symbol Rejected" << endl;
                    return 0;
                }
                break;

            case 2: // read '1's
                if (symbol == '1') {
                    if (!stk.empty()) {
                    cout<<"state"<<2<<"pop"<<stk.top()<<endl;
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
        if(state==1)
        {
             cout<<"state"<<1<<"push"<<2<<endl;
             stk.push('2');
             cout<<"state"<<1<<"to"<<0<<"by epsilon trans"<<endl;
             state=0;
        }
    }

    if (state == 2 && stk.empty()) {
            cout<<"state"<<2<<"to"<<3<<"by epsilon trans"<<endl;
        cout << "Accepted" << endl;
    } else if(state==2){
        cout << "Rejected stack not empty" << endl;
    }
    else {
        cout<<"Not final state, rejected";
    }

    return 0;
}

