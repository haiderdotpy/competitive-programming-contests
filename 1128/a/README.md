# 2261A - Hey, It's Me, Souvlakity

Time limit: 1 second | Memory limit: 256 megabytes

## Statement

Souvlakity and Kalamakity are playing yet another game.

All the integers from $1$ to $n$ have been distributed between the players. The distribution can be represented as a binary string $s$ of size $n$, where $s_i = 1$ if integer $i$ has been given to Souvlakity, and $s_i = 0$ if it has been given to Kalamakity. It is guaranteed that Souvlakity owns at least one integer initially (there exists a $1$ in $s$).

The game will go on for $10^{100}$ turns. The two players play in alternating turns, with Souvlakity playing first.

When it is a player's turn, they must choose exactly one of their integers and give it to the other player. It can be shown that this is always possible under this game's constraints.

After all $10^{100}$ turns are finished, Souvlakity calculates his score as the range of the integers he owns (that is, his score is $\max(S) - \min(S)$, where $S$ is the set of integers he owns). It can be shown that Souvlakity will own at least one integer at the end of the game.

Souvlakity wants to maximize his score, and Kalamakity wants to minimize Souvlakity's score. What is Souvlakity's final score if both players act optimally?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 100$).

The second line of each test case contains a binary string $s$ of length $n$. It is guaranteed that there exists at least one $\mathtt{1}$ in $s$.

## Output

For each test case, on a separate line, output a single integer: Souvlakity's final score after the game ends, if both players act optimally.

## Examples

### Input 1
```
6
2
01
3
111
4
1100
5
11111
6
101010
7
1101001
```

### Output 1
```
0
2
1
4
4
6
```

## Note

In the first test case, Souvlakity initially owns only the integer $2$. During each pair of consecutive turns (Souvlakity's turn and then Kalamakity's turn), Souvlakity gives away one integer and receives one integer, so after each of Kalamakity's turns he owns exactly as many integers as he owned initially. Since the number of turns is even, the last turn is Kalamakity's, so Souvlakity owns exactly one integer at the end of the game, and his score is $0$.

In the second test case, Souvlakity initially owns all three integers. By the same argument, he owns three integers at the end of the game, that is, all of them, so his score is $3 - 1 = 2$.

URL: https://codeforces.com/contest/2261/problem/A

