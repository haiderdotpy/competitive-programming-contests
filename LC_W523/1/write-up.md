# Write Up

## Approach
For each triplet, we check the condition; if it's found to be true, we return true. Otherwise, if we exhaust all triplets, we return false. 

## Solution

```cpp
class Solution {
public:
    bool threeFibonacciSum(int n) {
        typedef long long ll; 
        vector<ll> fib; 

        fib.push_back(0LL); 
        fib.push_back(1LL); 

        for (int i=2; fib[fib.size()-1] < n; i++) {
            fib.push_back((ll) fib[fib.size()-1] + fib[fib.size()-2]); 
            if ((ll) fib[fib.size()-1] + fib[fib.size()-2] + fib[fib.size()-3] == (ll) n) return true; 
        }

        return false; 
    }
};
```

Verdict: Accepted 
