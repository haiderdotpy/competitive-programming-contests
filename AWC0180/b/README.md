# B - Substring Rewriting 

## Problem Statement 
Takahashi has a string $S$ of length $N$ and a string $T$ of length $M$, both consisting of lowercase English letters.

Takahashi wants to choose characters at some positions in $S$ (possibly $0$) and rewrite each of them to an arbitrary lowercase English letter so that the modified $S$ contains $T$ as a contiguous substring.

Find the minimum number of characters he needs to rewrite to achieve this goal.

Here, a string $S$ containing $T$ as a contiguous substring means that there exists an integer $i$ ($1 \leq i \leq N−M+1$) such that the substring of $S$ from the $i$-th character through the $(i+M−1)$-th character equals $T$.

## Constraints
- $1 \leq M \leq N \leq 5000
- $N$ and $M$ are integers.
- $S$ is a string of length $N$ consisting of lowercase English letters.
- $T$ is a string of length $M$ consisting of lowercase English letters. 

## Input 
The input is given from Standard Input in the following format:
```
N M
S
T
```

## Output 
Print the minimum number of characters that need to be rewritten in a single line.

## Sample I/O 

### Input 1 
```
6 3
cabacc
abc
```

### Output 1
```
1
```

### Input 2
```
5 3
coder
ode
```

### Output 2 
```
0
```

### Input 3 
```
35 13
thequickbrownfoxjumpsoverthelazydog
brownboxjumps
```

### Output 3
```
1
```

### Input 4 
```
80 25
abcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcde
edcbaedcbaedcbaedcbaedcba
```

### Outp1 1 
```
20
```

### Input 5 
``` 
1 1
a
z
```

### Output 5
```
1
```
