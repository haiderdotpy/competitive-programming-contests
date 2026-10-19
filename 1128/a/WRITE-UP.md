# Write Up

## Approach 
Observation: Number of ones will not change at the end, since the number of moves is even. 

If the number of ones is greater than 2, then Souvlakity can always give a middle element to Kalamakity so as to not move the current range that he has. Kalamakity has to give one of his integers, and to minimize the range, he cannot give Souvlakity an element beyond the range. And hence, if the number of ones is greater than 2, the range remains fixed and doesn't change. So score is simply, last one's index - first one's index. 

If the number of ones is 2, Souvlakity has to give one of his boundary elements to Kalamakity, and Kalamakity can minimize the range by giving back the element as close to Souvlakity's lone one that he has at this point. Therefore, in this case, range is always going to be one. 

If the number of ones is 1, then range is always going to be zero. 

## Code
```cpp
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
```

**Verdict**: `AC`
