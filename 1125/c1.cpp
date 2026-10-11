#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int, int> pi; 

void solve() {
	int n; cin >> n; 
	vector<int> a(n); 
	for (int i=0; i<n; i++) cin >> a[i]; 
	
	ll ans = 0LL; 
	int esum = 0, osum = 0; 

	map<int, vector<int>> e, o;
	for (int i=0; i<n-4; i+=2) {
		esum = a[i] + a[i+2] - a[i+4]; 
		e[esum].push_back(i/2); 
	}

	for (int i=1; i<n-4; i+=2) {	
		osum = a[i] + a[i+2] - a[i+4]; 
		o[osum].push_back(i/2); 		
	} 
	
	for (auto& it: e) {
		auto& v = it.second;
		if (o.find(it.first) != o.end())
			ans += (ll)o[it.first].size() * v.size(); 

		int j = 0;
		for (int i=0; i<(int)v.size(); i++) {
			while (v[i] - v[j] >= 3) j++;  
			ans += j;
		}
	}

	for (auto& it: o) {
		auto& v = it.second;
		int j = 0;
		for (int i=0; i<(int)v.size(); i++) {
			while (v[i] - v[j] >= 3) j++;
			ans += j;
		}
	} 

	cout << ans << '\n';
}		

int main() {
	int t; cin >> t; 
	while (t--) solve(); 
	return 0; 
}
