#include <iostream>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode()
    {
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    bool inorder(TreeNode *p, TreeNode *q)
    {
        if (p == NULL and q == NULL)
            return true;

        if (p == NULL || q == NULL)
            return false;

        bool left = inorder(p->left, q->left);
        bool data = p->val == q->val;
        bool right = inorder(p->right, q->right);
        return left and data and right;
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return inorder(p, q);
    }
};
int main()
{
    return 0;
}