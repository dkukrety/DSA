/*
n-ary-tree-level-order-traversal
https://leetcode.com/problems/n-ary-tree-level-order-traversal/

Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]

t(n) and space will be o(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {

        vector<vector<int>> result;
        if (root == NULL)
            return result;

        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            vector<int> currLevelNodes;

            while (count-- > 0)
            {
                Node *temp = q.front();
                q.pop();
                currLevelNodes.push_back(temp->val);

                for (auto child : temp->children)
                {
                    q.push(child);
                }
            }

            result.push_back(currLevelNodes);
        }

        return result;
    }
};