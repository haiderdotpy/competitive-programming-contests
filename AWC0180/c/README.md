# C - Homework Submission Order

## Problem Statement
Takahashi-sensei is scheduled to receive homework from $N$ students today.

To check the homework efficiently, Takahashi-sensei decided to call students in a specific order to submit their homework. Each student is assigned an attendance number from $1$ to $N$, and the student with attendance number $i$ submits $A_i$ of homework.

Takahashi-sensei wants to call students in ascending order of the number of pages they submit (students with fewer pages first). If multiple students have the same number of pages, the student with the smaller attendance number is called first.

Determine the order in which Takahashi-sensei calls the students.

## Constraints
- $1 \leq N \leq 2\times10^5$
- $1 \leq A_i \leq 10^9$
- All inputs are integers.

## Input 
```
N 
A1 A2 ... AN
```

- The first line contains an integer $N$ representing the number of students.
- The second line contains $N$ integers $A_1,A_2,\ldots,A_N$ separated by spaces, representing the number of pages of homework each student submits. Here, $A_i$ is the number of pages of homework submitted by the student with attendance number $i$.

## Sample I/O

### Input 1 
```
5
30 10 20 10 40
```

### Output 1 
```
2 4 3 1 5
```

### Input 2 
```
8
100 50 50 75 25 100 25 50
```

### Output 2
```
5 7 2 3 8 4 1 6
```

### Input 3
```
12
1000000000 1 500 500 999999999 1 250 750 500 1000000000 250 1
```

### Output 3
```
2 6 12 7 11 3 4 9 8 5 1 10
```
