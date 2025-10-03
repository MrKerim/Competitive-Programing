# Convert Sorted Array to Binary Search Tree - LeetCode
[See the question in LeetCode](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1790577722/?envType=problem-list-v2&envId=binary-tree)

Can you solve this real interview question? Convert Sorted Array to Binary Search Tree - Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


<p align="center">
  <img src="https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg" alt="image" >
</p>



Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

<p align="center">
  <img src="https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg" alt="image" >
</p>



Example 2:


<p align="center">
  <img src="https://assets.leetcode.com/uploads/2021/02/18/btree.jpg" alt="image" >
</p>



Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


 

Constraints:

 * 1 <= nums.length <= 104
 * -104 <= nums[i] <= 104
 * nums is sorted in a strictly increasing order.
