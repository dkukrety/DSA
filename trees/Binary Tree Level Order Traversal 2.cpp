/*
Given the root of a binary tree, return the bottom-up level
order traversal of its nodes' values. (i.e., from left to right,
 level by level from leaf to root).

 Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

solution -->  reverse the vector<vector<int>> result ??
reverse(result.begin(),result.end())

also can we do...instead of result.push_back() result.push_at_the_front?? if that is possible...

does it will change Time and space complexity...
reverse will take o(n) for time and space..
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
*/

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
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
        reverse(result.begin(), result.end());
        return result;
    }
};