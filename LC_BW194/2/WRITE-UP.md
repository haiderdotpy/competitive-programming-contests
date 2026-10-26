# Write Up 

## Approach
Problem statement defines a loose-bound subarray as a subarray where all elements have values between `mink` and `maxK` (inclusive). 

We maintain subarray length as long as the conditions are met. As long as a violation is found, calculate number of subarrays (or sub-subarrays) that can be formed with this subarray by $\frac {s \times (s+1)} {2}$, where $s$ is the length of subarray. 

This relation can be derived as follows: 

Number of subarrays with length $s$ = $1$,
Number of subarrays with length $s-1$ = $2$ (exclude 1, either from front or from end), 
Number of subarrays with length $s-2$ = $3$ (exclude 2, either 1 from front a 1 from back, or 2 from either side) 
and so on... 
until, 
Number of subarrays with length $1$ = $s$. 

Total number of subarrays is $1 + 2 + \ldots + s = \frac {s \times (s+1)} {2}$

## Solution 
```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int n = nums.size(); 

        int s = 0; 
        long long ans = 0LL; 
            
        for (int i=0; i<n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                ans += 1LL * ((long long) s * (s+1) / 2); 
                s = 0; 
            }

            else s++; 
        }

        if (s) {
            ans += 1LL * ((long long) s * (s+1) / 2); 
        }

        return ans; 
    }
};
```
**Verdict**: `AC` (2 penalties) 
