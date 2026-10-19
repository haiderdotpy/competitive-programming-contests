#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

void solve() {
	int n; cin >> n; 
	vector<int> a(n); 
	for (int i=0; i<n; i++) cin >> a[i]; 

	vector<pair<int, int>> p(n); 
	for (int i=0; i<n; i++) p[i] = { i+1, a[i] }; 

	sort(p.begin(), p.end(), [&](auto a, auto b) {
			if (a.second == b.second) 
				return a.first < b.first; 
			return a.second < b.second; 
		}); 

	for (auto& it: p) 
		cout << it.first << " "; 
	cout << '\n';
}

int main() {
	int t=1;// cin >> t; 
	while (t--) solve(); 
	return 0; 
} 
