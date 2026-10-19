# Write Up

## Incorrect Approach 
Observation: game depends on the count of odd and even numbers. 

1. If number of odds are even, total sum is even and Moggity can remove the entire array. 
2. Otherwise, if the number of odd numbers is 3, 5, ... then we can say Moggity can force the condition that sum is odd and there are more than one elements left; thus no possible move and Moggity wins (This logic was incorrect). Otherwise, if there is exactly one odd number and even number of even numbers, Moggity can leave one odd and one even number, thus leaving no possible move for Larpity. Otherwise, if there are odd number of even numbers, Moggity cannot win (again this was incorrectly inferred). 

## Code 
```cpp 
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

	bool mog = false; 

	if (o % 2 == 0) mog = true; 
	else {
		if (o > 1) mog = true; 
		else { 
			if (e % 2 == 0) mog = true; 
			else mog = false; 
		}
	}

	cout << ((mog) ? "Moggity" : "Larpity") << '\n';
}

int main() {
	int t; cin >> t; 
	while (t--) solve(); 
	return 0; 
}
```

**Verdict**: `WA`

## Correct Approach
Let the game state be represented using $(E, O)$ where $E$ is the number of even numbers and $O$ is the number of odd numbers. 

We need an observation here, that the only cases where Larpity wins is $(1, 1)$ and $(0, 3)$. 
1. $(1, 1)$: here Moggity cannot remove both since sum is odd, and he has to remove one; which leads to Larpity being able to remove the last element and winning. 
2. $(0, 3)$: here if Moggity removes one, then Larpity can remove the other two with even sum; and if Moggity removes two, Larpity can remove one single element. Moggity cannot remove three as it has odd sum. Therefore, Larpity wins. 

Now, for any other case, Moggity can either directly win, or force one of these conditions on Larpity and win.
1. If $O$ is even or 0, sum is even and Moggity wins at once by removing the entire array. 
2. If $O$ is 1, this has 3 cases. If $E$ is 0, Moggity removes single element, if $E$ > 1, Moggity removes $(E-1)$ elements, and force $(1, 1)$ on Larpity. The third $(1, 1)$ condition is where Larpity wins. 
3. If $O$ is 3, if $E$ is zero, this is the condition where Larpity wins. If $E \neq 0$, Moggity can remove $E$ to force $(0, 3)$ on Larpity. 
4. If $O \geq 5$, Moggity can remove $E$ and $O-3$ to force $(0, 3)$ on Larpity. 

Therefore the only cases where Larpity wins are $(0, 3)$ and $(1, 1)$. 

## Upsolved Code
```cpp 
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
```
