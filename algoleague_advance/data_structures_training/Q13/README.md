Tuna, Dila, and Atakan are on an epic road trip to attend the highly anticipated 'Eras Tour' concert of their favorite pop artist, 'Tailor Quick.' As they travel, they have a playlist of 'Tailor Quick' songs playing on their car's music player on a continuous loop. Each song in their playlist has a unique 'length' value.

Tuna, who is quite analytical, wants to find the next 'Tailor Quick' song with a longer length for each song in their looped playlist, even if they have to loop back to the beginning of the playlist. If there's no such song with greater length, they want to know and mark it with `-1`.

Can you help them solve this musical challenge? Take the circular array of 'length' values, representing their playlist, and print out the next 'Tailor Quick' song with a longer length for each song in the playlist. If there's no such song, print `-1`.

**Input Format**
The first line contains $N$, length of the given array.

The second line contains $N$ space-separated integers representing the array’s elements.

**Output Format**
Print $N$ space separated integers representing the next song with a longer length for every number in the array.

If no such song exists, print `-1`.

**Constraints**
- $1 \leq N \leq 10^5$
- $-10^9 \leq$ array element $\leq 10^9$

**Sample Input 1**
3
1 2 1
**Sample Output 1**
2 -1 2

**Sample Input 2**
5
1 2 3 4 3

**Sample Output 2**
2 3 4 -1 4
