# 4089. Count Subarrays With Loose Bounds

## Statement

You are given an integer array `nums` and two integers `minK` and `maxK`.

A loose-bound subarray is a subarray in which every element is greater than or equal to `minK` and less than or equal to `maxK`.

Return the number of loose-bound subarrays in `nums`.

A subarray is a contiguous non-empty sequence of elements within an array.

## Constraints

- `2 <= nums.length <= 10^5`
- `1 <= nums[i], minK, maxK <= 10^6`

## Examples

### Input 1
```
nums = [1,4,7,3], minK = 1, maxK = 5
```

### Output 1
```
4
```

### Input 2
```
nums = [1,1], minK = 1, maxK = 1
```

### Output 2
```
3
```

## Note

The loose-bound subarrays are [1], [4], [3], and [1, 4]. The minimum value in these subarrays is at least minK = 1 and the maximum value is at most maxK = 5.

The loose-bound subarrays are [1], [1], and [1, 1]. The minimum value in these subarrays is at least minK = 1 and the maximum value is at most maxK = 1.

URL: https://leetcode.com/problems/count-subarrays-with-loose-bounds/
