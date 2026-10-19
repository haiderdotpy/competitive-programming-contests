#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

void solve() {
	int n, m; cin >> n >> m; 
	string s, t; cin >> s >> t; 

	int ans = INT_MAX; 
	int r; 
	for (int i=0; i<n && i<m; i++) {
		r = 0; 
		for (int j=0; j<n && j<m; j++) 
			if (s[i+j] != t[j]) r++;
	        ans = min(ans, r); 	
	}	
	
	cout << ans << endl; 
}

int main() {
	int t=1; // cin >> t; 
	while (t--) solve(); 
	return 0; 
} 
