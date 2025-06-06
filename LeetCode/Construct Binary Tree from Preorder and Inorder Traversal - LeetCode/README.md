# Construct Binary Tree from Preorder and Inorder Traversal - LeetCode
[See the question in LeetCode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/1623881739/?envType=study-plan-v2&envId=top-interview-150)

Can you solve this real interview question? Construct Binary Tree from Preorder and Inorder Traversal - Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


<p align="center">
  <img src="https://assets.leetcode.com/uploads/2021/02/19/tree.jpg" alt="image" >
</p>



Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]


Example 2:


Input: preorder = [-1], inorder = [-1]
Output: [-1]


 

Constraints:

 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
