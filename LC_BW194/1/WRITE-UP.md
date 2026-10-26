# Write-Up 

## Approach 
Add all peaks and add all valleys; return difference. 

## Solution 
```cpp
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        const int n = nums.size(); 

        int peaks, valleys;
        peaks = valleys = 0; 

        for (int i=1; i<n-1; i++) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) 
                peaks += nums[i];  
            if (nums[i] < nums[i-1] && nums[i] < nums[i+1])
                valleys += nums[i]; 
        }

        return peaks - valleys;
    }
};
```

**Verdict**: `AC`
