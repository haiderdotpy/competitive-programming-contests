# Write Up 

## Approach 
For each element, calculate the biggest element that can be built out of the digits, by sorting the digits in non-decreasing order. Now, store the difference of the original element and this newly formed sorted number, and store it in a priority queue. 

After calculating the gain for every element and storing it in a heap, we add the top k gain possible to the sum of the `nums` array as it is. 

## Solution 
```cpp 
class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        const int n = nums.size(); 

        priority_queue<
            long long, 
            vector<long long>,
            less<long long> 
        > pq; 

        vector<int> newDig; 
        int newNum; 
        for (int i=0; i<n; i++) {
            int cpy = nums[i]; 
            newDig.clear(); 
            while (cpy) {
                newDig.push_back(cpy % 10); 
                cpy /= 10; 
            }

            sort(newDig.begin(), newDig.end(), [&](auto a, auto b) {
                return a > b; 
            }); 
            
            newNum = 0; 
            for (int j=0; j<newDig.size(); j++) 
                newNum = newNum*10 + newDig[j]; 

            pq.push(newNum - nums[i]); 
        }

        long long sum = 0; 
        for (int x: nums) 
            sum += (long long) x; 

        while (k-- && !pq.empty()) {
            sum += (long long) pq.top();  
            pq.pop(); 
        }

        return sum; 
    }
};
```

**Verdict**: `AC`
