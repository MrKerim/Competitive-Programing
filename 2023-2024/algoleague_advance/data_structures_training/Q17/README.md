# İtirazı olan var mı?

There are `n` cats in a row awaiting attention from the algorithm team, each with their own beauty rating represented as `b0`, `b1`, …, `bn−1`. For every cat at position `i`, determine the leftmost `li` and rightmost `ri` positions where the cats are at least as beautiful as the cat at position `i`, satisfying $0 ≤ li ≤ i ≤ ri < n$.

### Input Format
The first line contains an integer `n` — the number of cats.

The second line contains `n` integers `b0`, `b1`, …, `bn−1` — the beauties of cats.

### Output Format
Print `n` lines. The `ith` line should contain `li` and `ri`. Note that the positions are `0`-indexed.

### Constraints
- $1 ≤ n ≤ 2 ⋅ 10^5$
- $1 ≤ bi ≤ 10^9$

#### Sample Input 1 
1  
1  
### Sample Output 1
00
#### Explanation 1
There's only one element, and it is greater than or equal to itself.

#### Sample Input 2 
3  
2 3 1  

### Sample Output 2
01  
11  
02  

#### Explanation 2
- The first cat, with a beauty rating of `2` (position `0`), has the second cat to the right, which has higher beauty (position `1`), and there is only one cat to consider, which is itself, with a beauty rating equal to or greater than itself on the left side.
- The second cat, with a beauty rating of `3` (position `1`), has no other cats to the left or right with higher beauty, so the answer is the cat itself.
- The third cat, with a beauty rating of `1` (position `2`), has the leftmost cat (position `0`) with beauty equal to or greater than itself, and there is only one cat to consider, which is itself, with a beauty rating equal to or greater than itself on the right side.

