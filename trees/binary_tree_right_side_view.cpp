/*
https://leetcode.com/problems/binary-tree-right-side-view/


optimized soltion
t(c):o(n)
s(c): o(n) + o(n/2) for queue ,skewed tree and o(logn)+n/2 for queue for average case..

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
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
                // currLevelNodes.push_back(temp->val);
                if (count == 0)
                    result.push_back(temp->val);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            // result.push_back(currLevelNodes);
        }
        return result;
    }
};
