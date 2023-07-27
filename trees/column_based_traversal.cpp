https : // leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

        // Need to correct below solution...

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
    map<int, vector<int>> mp;

    void helper(TreeNode *root, int dist)
    {
        mp[dist].push_back(root->val);

        if (root->left)
            helper(root->left, dist - 1);
        if (root->right)
            helper(root->right, dist + 1);
        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        helper(root, 0);

        map<int, vector<int>>::iterator it = mp.begin();
        while (it != mp.end())
        {
            // sort(it->second.begin(),it->second.end());
            result.push_back(it->second);
            it++;
        }

        return result;
    }
};