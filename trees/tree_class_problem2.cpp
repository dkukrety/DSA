/*
For your reference:
class BinaryTreeNode {
    public:
        int value;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};
*/

// pre-order
void helper(BinaryTreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;
    result.push_back(root->value);

    if (root->left)
        helper(root->left, result);

    if (root->right)
        helper(root->right, result);
}

vector<int> preorder(BinaryTreeNode *root)
{
    vector<int> result;
    helper(root, result);
    return result;
}

// in-order

void helper(BinaryTreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;

    if (root->left)
        helper(root->left, result);

    result.push_back(root->value);

    if (root->right)
        helper(root->right, result);
}

// post-order

void helper(BinaryTreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;

    if (root->left)
        helper(root->left, result);

    if (root->right)
        helper(root->right, result);

    result.push_back(root->value);
}