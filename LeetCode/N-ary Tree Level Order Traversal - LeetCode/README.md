# N-ary Tree Level Order Traversal - LeetCode
[See the question in LeetCode](https://leetcode.com/problems/n-ary-tree-level-order-traversal/submissions/1486316441/)

Can you solve this real interview question? N-ary Tree Level Order Traversal - Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:


<p align="center">
  <img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" alt="image" >
</p>



Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]


Example 2:


<p align="center">
  <img src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" alt="image" >
</p>



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]


 

Constraints:

 * The height of the n-ary tree is less than or equal to 1000
 * The total number of nodes is between [0, 104]
