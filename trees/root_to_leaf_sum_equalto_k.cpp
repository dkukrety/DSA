/*
Given a binary tree and an integer k, check
whether the tree has a root to leaf path with a sum of values equal to k.
*/

// optimized recursive solution.

bool path_sum_helper(BinaryTreeNode *root, long long k)
{
    bool path_found = false;

    if (root->left == NULL && root->right == NULL)
    {
        if ((long long)root->value == k)
        {
            path_found = true;
            return path_found;
        }
    }

    if (root->left)
    {
        path_found = path_sum_helper(root->left, (k - root->value));
    }
    if (!path_found)
    {
        if (root->right)
        {
            path_found = path_sum_helper(root->right, (k - root->value));
        }
    }

    return path_found;
}

// Non optimized solution

bool path_sum(BinaryTreeNode *root, long long k)
{
    // Write your code here.
    if (root == NULL && k == 0)
        return 1;
    if (root == NULL && k != 0)
        return 0;
    if (k == (long long)root->value && root->left == NULL && root->right == NULL)
    {
        cout << root->value;
        return 1;
    }
    // cout<<k<<endl;
    int left = 0;
    int right = 0;

    if (root->left)
    {
        // cout<<root->left->value;

        left = path_sum(root->left, k - root->value);
    }
    if (!left && root->right)
    {
        // cout<<root->value<<endl;
        right = path_sum(root->right, k - root->value);
    }
    return left || right;
}

/*
Iterative solution.
* Asymptotic complexity in terms of number of nodes in the given tree `n`:
* Time: O(n).
* Auxiliary space: O(n).
* Total space: O(n).
*/

bool path_sum(BinaryTreeNode *root, int k)
{
    queue<BinaryTreeNode *> q;
    q.push(root);
    unordered_map<BinaryTreeNode *, long long int> sum_till_node;
    sum_till_node[root] = root->value;

    while (!q.empty())
    {
        BinaryTreeNode *current = q.front();
        q.pop();

        // If the current node is a leaf node and has the path sum equal to k,
        // if means we have found a root to leaf path with the given sum.
        if (current->left == NULL and current->right == NULL)
        {
            if (sum_till_node[current] == k)
            {
                return true;
            }
        }

        if (current->left != NULL)
        {
            sum_till_node[current->left] = sum_till_node[current] + current->left->value;
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            sum_till_node[current->right] = sum_till_node[current] + current->right->value;
            q.push(current->right);
        }
    }

    return false;
}

// https://leetcode.com/problems/path-sum-ii/submissions/

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
    void helper(TreeNode *root, int targetSum, vector<int> slate, vector<vector<int>> &result)
    {
        if (root->val == targetSum && root->left == NULL && root->right == NULL)
        {
            slate.push_back(root->val);
            result.push_back(slate);
        }

        slate.push_back(root->val);
        if (root->left)
            helper(root->left, targetSum - root->val, slate, result);
        // slate.pop_back();
        // slate.push_back(root->val);
        if (root->right)
            helper(root->right, targetSum - root->val, slate, result);
        slate.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        vector<int> slate;
        if (root == NULL)
            return result;

        helper(root, targetSum, slate, result);
        return result;
    }
};

// https://leetcode.com/problems/path-sum-iii/description/
