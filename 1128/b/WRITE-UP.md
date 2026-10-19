# Write Up 

## Approach 
Convert each number into the maximum number that is possible if there is a greater element to the left or to the right. 

## Solution 
```cpp
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

void solve() {
	int n; cin >> n; 
	vector<int> a(n); 
	for (int i=0; i<n; i++) cin >> a[i]; 
	
	int k, cpy, maxk = INT_MIN; 
	
	for (int i = 0; i < n; i++) {
	    if ((a[i]+1 & a[i]) == 0) continue; 
	    bool hasL = i > 0, hasR = i + 1 < n;
	    if (hasL && hasR) {
		if (a[i-1] > a[i] || a[i+1] > a[i]) a[i] = max(a[i-1], a[i+1]);
	    } else if (hasR) {
		if (a[i+1] > a[i]) a[i] = a[i+1] - 1;
	    } else if (hasL) {
		if (a[i-1] > a[i]) a[i] = a[i-1] - 1;
	    }

	}

	int ans = 0; 
	for (int x: a) ans |= x; 

	cout << ans << '\n';
}

int main() {
	int t; cin >> t; 
	while (t--) solve(); 
	return 0; 
} 
```

**Verdict**: `WA`

## Upsolved Approach
The MSB of result cannot go over the MSB of the maximum number. If the $MSB(max(a))$ is called $b$, then the we check the MSB of the minimum number, i.e. $MSB(min(a))$. 

Key observation is, each bit can set to 1, in the case $MSB(min(a)) < b$. The smallest number can be taken and one can be added repeatedly until one number reaches $2^b - 1$. If we OR this with our max number, we get $2^{(b+1)} - 1$. 

If $MSB(a) = b$, ignore the MSB that match, and look for the first mismatch from the significant side. Hence, answer is $max(a) OR $(2^{(k+1)}-1)$, where $k = MSB(max XOR min)$. 
