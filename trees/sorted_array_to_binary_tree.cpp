
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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
// since we need to make height balanced BST....we need to pick median from sorted array
// then we need to create root from mid. After that call helper to return left and right
// node
//

class Solution
{
public:
    /*
    time and space will be o(n)
    */
    TreeNode *helper(int l, int r, vector<int> nums)
    {
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = helper(l, mid - 1, nums);
        node->right = helper(mid + 1, r, nums);

        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(0, nums.size() - 1, nums);
    }
};

// https: // leetcode.com/problems/convert-sorted-list-to-binary-search-tree/solutions/3282150/daily-leetcode-solution-easy-c-solution/
