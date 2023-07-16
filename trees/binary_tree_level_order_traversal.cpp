/*
Binary Tree Level Order Traversal
Medium
13.6K
267
Companies
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


T(c) : o(n)
s(c) : result + queue for each currentlevel nodes.. o(n) + o(n/2) ..number of nodes in last level is n/2

https : // leetcode.com/problems/binary-tree-level-order-traversal/

*/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            vector<int> currLevelNodes;

            while (count-- > 0)
            {
                TreeNode *temp = q.front();
                q.pop();
                currLevelNodes.push_back(temp->val);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            result.push_back(currLevelNodes);
        }

        return result;
    }
};