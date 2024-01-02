#include<bits/stdc++.h>
using namespace std;
typedef long double ll;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll x,a,y,b;
        cin >> x >> a >> y >> b;

        if(b==0){
            if(a==0||x==1){
                cout << "Yes"<<"\n";
            }
            else cout << "No\n";
        }
        else{
            if(x==1){
                if(y==1) cout << "Yes\n";
                else cout <<"No\n";
            }
            else{
                if(a/b==(log2(y)/log2(x)))cout << "Yes"<<"\n";
                else cout << "No\n";
                //cout <<log2(y)/log2(x)<<"\n";
            }
        }

    }
}