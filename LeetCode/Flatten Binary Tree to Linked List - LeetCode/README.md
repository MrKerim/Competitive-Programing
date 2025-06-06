# Flatten Binary Tree to Linked List - LeetCode
[See the question in LeetCode](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/1623917771/?envType=study-plan-v2&envId=top-interview-150)

Can you solve this real interview question? Flatten Binary Tree to Linked List - Given the root of a binary tree, flatten the tree into a "linked list":

 * The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
 * The "linked list" should be in the same order as a pre-order traversal 
<p align="center">
  <img src="https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR" alt="image" >
</p>
 of the binary tree.

 

Example 1:


<p align="center">
  <img src="https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg" alt="image" >
</p>



Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]


Example 2:


Input: root = []
Output: []


Example 3:


Input: root = [0]
Output: [0]


 

Constraints:

 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100

 

Follow up: Can you flatten the tree in-place (with O(1) extra space)?
