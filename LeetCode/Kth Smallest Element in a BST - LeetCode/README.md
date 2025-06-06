# Kth Smallest Element in a BST - LeetCode
[See the question in LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1629543989/?envType=study-plan-v2&envId=top-interview-150)

Can you solve this real interview question? Kth Smallest Element in a BST - Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


<p align="center">
  <img src="https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg" alt="image" >
</p>



Input: root = [3,1,4,null,2], k = 1
Output: 1


Example 2:


<p align="center">
  <img src="https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg" alt="image" >
</p>



Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


 

Constraints:

 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 104
 * 0 <= Node.val <= 104

 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
