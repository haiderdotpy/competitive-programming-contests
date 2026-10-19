#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

void solve() {
	int n; cin >> n; 
	vector<int> a(n); 
	for (int i=0; i<n; i++) cin >> a[i]; 
	
	ll e = 0, o = 0; 
	for (int x: a) { 
		if (x % 2) o++; 
		else e++; 
	}

	bool larp = (o == 1 && e == 1) || (o == 3 && e == 0); 
	cout << ((larp) ? "Larpity":"Moggity")<<'\n';	
}

int main() {
	int t; cin >> t; 
	while (t--) solve(); 
	return 0; 
} 
