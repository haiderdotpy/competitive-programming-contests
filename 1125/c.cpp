#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int, int> pi; 

void solve() {
	int n; cin >> n; 
	vector<int> a(n); 
	for (int i=0; i<n; i++) cin >> a[i]; 
	
	int psum; 	
	ll ans = 0LL; 
			    //
	unordered_map<ll, int> m; 
        ll esum = 0, osum = 0; 	


	unordered_map<ll, vector<int>> e, o; 
	for (int i=0; i<n-4; i+=2) {
		esum = a[i] + a[i+2] - a[i+4]; 
		e[esum].push_back(i/2); 
	}

	for (int i=1; i<n-4; i+=2) {	
		osum = a[i] + a[i+2] - a[i+4]; 
		o[osum].push_back(i/2); 		
	} 
	
	for (auto& it: e) {
		if (o.find(it.first) != o.end())
			ans += o[it.first].size() * it.second.size(); 

		if (it.second.size() >= 2) {
			for (int i=1; i<it.second.size(); i++) {
				if (it.second[i] - it.second[i-1] > 2) {
					ans += i;  
				} else {
					if (it.second.size() >= 3) {
						if (it.second[i] - it.second[i-2] > 2) 
							ans += i-1; 
					}	 
				}
			}
		}
	}

	for (auto& it: o) {
		if (it.second.size() >= 2) {
			for (int i=1; i<it.second.size(); i++) {
				if (it.second[i] - it.second[i-1] > 2) {
					ans += i;  
				} else {
					if (it.second.size() >= 3) {
						if (it.second[i] - it.second[i-2]) 
							ans += i-1; 
					}	 
				}
			}
		}
	} 

	cout << ans << '\n';
}		

int main() {
	int t; cin >> t; 
	while (t--) solve(); 
	return 0; 
}
