#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

void solve() {
	int n; cin >> n; 
	string s; cin >> s; 
	
	int o = 0; 
	for (char c: s) if (c == '1') o++; 
	
	if (o == 1) { cout << 0 << '\n'; return; } 
	if (o == 2) { cout << 1 << '\n'; return; }

	int f=0, l=n-1; 

	for (int i=0; i<n; i++) { if (s[i] == '1') { f = i; break; } } 
	for (int i=n-1; i>=0; i--) { if (s[i] == '1') { l = i; break; } } 

	cout<< l -f<<'\n';
}

int main() {
	int t; cin >> t; 
	while (t--) solve(); 
	return 0; 
} 
