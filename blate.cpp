#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;

    while(t--){
        long long int x, a, y, b;
        cin >> x >> a >> y >> b;

        if(b == 0){
            if(a == 0 || x == 1){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else{
            if(x == 1 ){
                if(y == 1){
                cout << "Yes" << endl;
                }
                else{
                    cout <<"No" << endl;
                }
            } 
        
            else{
                if(a / b == log2(y) / log2(x)){
                    cout << "Yes" << endl;
                }
                else{
                    cout << "No" << endl;
                }
            }
        }
    }
}