# Write Up

## Approach
Count set bits by shifting right and comparing with $1$. Calculate score as given in problem statement. 

## Solution
```cpp
class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = 0, s2 = 0; 

        while (a) {
            s1 += a & 1; 
            a >>= 1; 
        }

        while (b) {
            s2 += b & 1; 
            b >>= 1; 
        }

        return (s1 >= s2) ? s1 * s2 : s2 / s1; 
    }
};
```

**Verdict**: `AC`
