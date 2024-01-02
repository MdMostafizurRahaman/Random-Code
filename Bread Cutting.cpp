#include<bits/stdc++.h>
using namespace std;

int const MAX = 1005;
int l, n;
int a[MAX];
int track[MAX][MAX];

int dp(int start, int finish){
    if(track[start][finish] != -1) return track[start][finish];

    bool f=false;
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        if(a[i] <= start or a[i] >= finish) continue;

        f=true;

        ans = min(ans, finish - start + dp(start, a[i]) + dp(a[i], finish));
    }

    if(!f) track[start][finish] = 0;
    else track[start][finish] = ans;
    return track[start][finish];
}

int main(){
    int l; cin >> l;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    memset(track, -1, sizeof track);

    cout << "Minimum cutting cost is: " << dp(0, l) << endl;

    return 0;
}
