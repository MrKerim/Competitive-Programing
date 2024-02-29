# LeaderBord

Meet Berke, an art enthusiast with a peculiar sense of humor and an unquenchable love for visual arts — especially for anime. Berke has amassed a fortune large enough to fund his wildest ventures. So, Berke decides to host the most whimsical anime girl picture competition the world has ever seen.

In this offbeat contest, rules are as unconventional as the host himself. Every time a contestant submits a drawing, Berke, with his enigmatic taste in art, awards a score to the picture. But here's the quirky twist: at any random moment during the ongoing competition, Berke chooses to surprise the artists. He decides to hand out prizes not just based on the whims of traditional judgment but on the highest scores earned at that point. Whenever Berke yells `Top K!`, the owners of the top K scored pictures at that moment win a prize, where $K$ is an integer. As the competition progresses with more submissions and spontaneous prize distributions, keeping track of the top scores becomes a delightful chaos only Berke could orchestrate.

There are two types of operations:

- `add X`: indicating a new picture is submitted with score X (an integer).
- `top K`: Berke decides to find out the top K scores at that point in time.

You need to find the most K scores for each top K operation, the scores of the top $K$ pictures in descending order at that time. It is guaranteed that for each top $K$ operation, there are at least K pictures submitted.

**Input Format:**  
The first line contains two integers $N$ and $O$ — the number of pictures expected in the competition and the number of operations Berke will perform, respectively.

The next $O$ lines describe the operations.

**Output Format:**  
For each top $K$ operation, print a line containing $K$ integers, the scores of the top $K$ pictures in descending order at that time.

**Constraints:**  
$1 ≤ N ≤ O ≤ 2 × 10^5$  
$1 ≤ K ≤ 100$  
$1 ≤ X ≤ 10^6$

**Sample Input 1**

5 6  
add 3  
add 5  
add 1  
add 7  
add 9  
top 5  

**Sample Output 1**  
9 7 5 3 1
