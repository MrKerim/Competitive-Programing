Aycan has a house with $N$ adjacent rooms. However, there's a quirky issue in this house — each room has a vastly different temperature! For instance, two rooms right next to each other might have temperatures like $50^\circ$ and $-50^\circ$.

Aycan can do something about it though. Since there are doors between adjacent rooms, she can open these doors to equalize the temperatures. The temperatures then average out among the rooms that have airflow between them. For example, if there are three rooms in a row with temperatures $50^\circ$, $-20^\circ$, and $-30^\circ$, Aycan can open the doors between them and make all three rooms reach a temperature of $0^\circ$, which makes her very happy.

Aycan wonders how many different ways she can select adjacent rooms in a way that, when chosen, the total temperature becomes $0^\circ$. Note that Aycan can choose just one room, and if that room's temperature is already $0^\circ$, it's a valid choice.

Can you help Aycan figure out how many different ways she can make this selection so that the total temperature becomes $0^\circ$?

**Input Format**

The first line contains an integer $n$ — representing the number of rooms.

The second line contains $n$ integers separated by spaces, $t_1, t_2, \ldots, t_n$ — denoting the temperatures of the rooms.

**Output Format**

A single integer representing the number of different ways Aycan can select adjacent rooms in a way that, when chosen, the total temperature becomes $0^\circ$.

**Constraints**

- $1 \leq n \leq 2 \times 10^5$
- $-10^9 \leq t_i \leq 10^9$

**Sample Input 1**
5
2 3 -4 -1 5
**Sample Output 1**
2
**Explanation 1**

Rooms between 1st and 4th ($2^\circ + 3^\circ + (-4)^\circ + (-1)^\circ = 0^\circ$)
Rooms between 3rd and 5th (($-4)^\circ + (-1)^\circ + 5^\circ = 0^\circ$)

**Sample Input 2**
6
2 -4 2 -4 6 -2
**Sample Output 2**
4
**Explanation 2**

Rooms between 1st and 3rd
Rooms between 1st and 6th
Rooms between 2nd and 5th
Rooms between 4th and 6th

