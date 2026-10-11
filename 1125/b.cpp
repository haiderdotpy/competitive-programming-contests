#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

void solve() {
	int n; cin >> n; 
	string s; cin >> s; 

	int k = 0; 
	vector<int> ans; 

	stack<int> stk; 

	char c; 
	for (int i=0; i<n; i++) {
		c = s[i]; 
		if (c == '1') stk.push(i+1); 
		else if (c == '2') {
			if (!stk.empty()) { 
				k++; 
				ans.push_back(i+1); 
			       	stk.pop(); 
			} 
		} 
	} 

	while (!stk.empty()) {
		k++; 
		ans.push_back(stk.top()); 
		stk.pop(); 
	}

	sort(ans.begin(), ans.end()); 

	cout << k << '\n'; 
	for (int i=0; i<ans.size(); i++) 
		cout << ans[i] << " "; 
	cout << '\n'; 	
}

int main() {
	int t; cin >> t; 
	while (t--) solve(); 
	return 0; 
} 
