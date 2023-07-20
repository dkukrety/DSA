// So diameter is left tree hight + right tree hight + 1 -1(for edges);
int hieght(BinaryTreeNode *root, int &result)
{
    if (root == NULL)
        return 0;

    int lh = hieght(root->left, result);
    int rh = hieght(root->right, result);

    int dia = lh + rh;

    result = max(result, dia);
    return max(lh, rh) + 1;
}
int binary_tree_diameter(BinaryTreeNode *root)
{
    int result = 0;
    hieght(root, result);
    return result;
}