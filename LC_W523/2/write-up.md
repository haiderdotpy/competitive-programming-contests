# Write Up 

## Approach 
1. Find all the primes upto n. 
2. Since we have to maximize the number of terms, we choose the first k primes whose sum <= s. 

## Solution 
```cpp 
class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> primes(n+1, true); 
        primes[0] = primes[1] = false; 
        for (int i=2; i*i<=n; i++) {
            if (primes[i]) {
                for (int j=i*i; j<=n; j+=i) 
                    primes[j] = false; 
            }
        }

        /*for (int i=0; i<=n; i++) 
            cout << i << " -> " << primes[i] << endl ; */

        long long sum = 0; 
        int lastidx = 0; 
        vector<int> ans; 
        // since the ith index stores if i is a prime or not, we can use this to find the sum
        for (int i=2; i<=n; i++) {
            if (!primes[i]) continue; 
            sum += i * (sum <= s);
            ans.push_back(i); 

            if (sum > s) break; 
        }

        if (sum > s) ans.pop_back(); 

        return ans; 
    }
};
```

Verdict: Accepted 
