# A - Travel Records 

## Problem Statement
Takahashi records the places he has visited as a sequence of symbols, each a single English letter. The record is represented by a string S of length N.

Each character of S represents a foreign country if it is an uppercase English letter, or a prefecture in his home country if it is a lowercase English letter. Find the number of times Takahashi visited a foreign country, that is, the number of uppercase English letters contained in S.

## Constraints 
- 1 ≤ N ≤ 100
- S is a string of length N consisting only of uppercase and lowercase English letters.

## Input 
The first line contains N, the length of the record.
The second line contains the string S representing the record.

## Output 
Print the number of uppercase English letters contained in S on a single line.

## Sample I/O

### Input 1 
```
6
JaPanU
```

### Output 1
```
3
```

### Input 2 
```
3
xyz
```

### Output 2 
```
0
```

### Input 3 
```
5
ABCDE
```

### Output 3
```
5
```

### Input 4
```
40
UduTbqMePdFQdTTpXjjSbDweYpPhrPGFKfuPCEwv
```

### Output 4
```
20
```

### Input 5
```
7
bgRvCmh
```

### Output 5
```
2
```
