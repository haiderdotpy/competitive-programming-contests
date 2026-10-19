# 2261B - What's the Capital of France?

Time limit: 1.5 seconds | Memory limit: 256 megabytes

## Statement

Obesity might not know the capital of France, but he does know that France has lots of restaurants.

There are $n$ restaurants in a line. The $i$-th restaurant has rating $a_i$.

Obesity can alter the ratings of the restaurants with his special power. In one operation, Obesity chooses two adjacent restaurants. If they have the same rating, nothing happens. Otherwise, the rating of the lower side is increased by $1$.

Formally, in one operation, he does the following:

- Choose an index $i$ ($1 \le i \lt n$).
- If $a_i \lt a_{i+1}$, increase $a_i$ by $1$.
- If $a_i = a_{i+1}$, do nothing.
- If $a_i \gt a_{i+1}$, increase $a_{i+1}$ by $1$.

The delicacy of the restaurants is the value of the bitwise OR of the ratings of all restaurants.

What is the maximum delicacy Obesity can achieve after performing zero or more operations?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The description of the test cases follows. The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print one integer — the maximum delicacy of all restaurants.

## Examples

### Input 1
```
4
1
0
2
1 2
2
4 6
3
8 8 8
```

### Output 1
```
0
3
7
8
```

## Note

In the first test case, Obesity cannot perform any operations.

In the second test case, it is optimal for Obesity to perform no operations: $1\, |\, 2 = 3$.

In the third test case, Obesity can choose $i=1$. Since $4 \le 6$, he increases the rating of the first restaurant by $1$. The ratings are now $[5,6]$, which gives a delicacy of $7$. It can be shown that $7$ is the maximum delicacy no matter how many operations are performed.

URL: https://codeforces.com/contest/2261/problem/B
