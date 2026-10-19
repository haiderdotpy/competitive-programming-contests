#include <bits/stdc++.h>
using namespace std; 

void solve() {
	int n; string s; 
	cin >> n; 
	cin >> s; 

	int ans = 0; 

	for (char c: s) 
		if ('A' <= c && c <= 'Z') 
			ans++; 
	
	cout << ans << '\n'; 
} 

int main() {
	solve();

	return 0; 
}
