/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


use same template...
but reverse the resultant array, before adding to final result...

for(int i = 0; i< results.size();i++)
{
    if(i%2==1) // reverse for odd levels
    reverse(results[i].begin,results[i].end)
}

t(n) is o(n)
s(n) is o(n)

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
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
        for (int i = 0; i < result.size(); i++)
        {
            if (i % 2 == 1) // reverse for odd levels
                reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};
