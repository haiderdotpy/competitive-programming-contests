# CodeForces Contest #1125 (Division 3) 

## A. In Search of Convenience

[Problem Link](https://codeforces.com/contest/2275/problem/A)

### Approach
Since we have to return any point at a distance R from the given point (x0, y0), we can simply return (x0 + R, y0). 

### Solution

```cpp
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

void solve() {
	int x, y, r; cin >> x >> y >> r; 
	cout << (x + r) << " " << y << '\n'; 
}

int main() {
	int t; cin >> t; 
	while (t--) solve(); 
	return 0; 
} 
```

Verdict: Accepted

## B. Did Not Go to Print

[Problem Link](https://codeforces.com/contest/2275/problem/B)

### Approach
Maintain a stack to keep track of what documents have been printed. 

1. If document is scanned, it's added onto the stack. 
2. If document is printed from memory, and the stack is empty we do nothing. 
3. If document is printed from memory, and the stack is not empty, we pop the stack and add the index to `ans` at the current position which is not printed. 
4. If the document is immediately printed, we do nothing. 
5. After scanning the commands, we check if our stack is empty or not. The stack stores all the unprinted documents at this stage. We pop one by one and add it to the `ans` array. 
6. `ans` is sorted, as the problem expects the output in ascending order. 

### Solution

```cpp
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
```

Verdict: Accepted

## C. Unrequited Love

[Problem Link](https://codeforces.com/contest/2275/problem/C)

### Approach
1. We store all occurences of even-positioned triad sums and odd-positioned triad sums, and store them in a map. 
2. We take any one map and find pairs from the different maps. Since they can be paired freely, we simply add the product of their sizes to the answer. For example, if there is are three triads in even positions and two triads in odd positions with some sum S, then we can make total of 2 * 3 = 6 combinations using those. 
3. In both of the map, we also find pairs of equal triad sums in themselves. If such pairs are found, we add them to the ans.

### Solution

```cpp
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
```

Verdict: Accepted
