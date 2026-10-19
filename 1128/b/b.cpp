#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        int mx=INT_MIN,mn=INT_MAX;
        for (int i = 0; i < n; i++) {
            int a;cin >> a;
            mx = max(mx,a);
            mn = min(mn,a);
        }
        if (mx == mn) cout << mx << '\n';
        else {
            cout << (((1<<(32-__builtin_clz(mx^mn)))-1)|mx) << '\n';
        }
    }
}
