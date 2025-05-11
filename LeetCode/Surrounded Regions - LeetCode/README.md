# Surrounded Regions - LeetCode
[See the question in LeetCode](https://leetcode.com/problems/surrounded-regions/submissions/1631432343/?envType=study-plan-v2&envId=top-interview-150)

Can you solve this real interview question? Surrounded Regions - You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

 * Connect: A cell is connected to adjacent cells horizontally or vertically.
 * Region: To form a region connect every 'O' cell.
 * Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


<p align="center">
  <img src="https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg" alt="image" >
</p>


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

 

Constraints:

 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
