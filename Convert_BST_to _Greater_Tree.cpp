#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// recursive inorder BST traversal
// 1st right then current node then left
void transformBST(TreeNode* node,int& sum) {
    if (node == nullptr) return;
    transformBST(node->right,sum);
    sum += node->val;
    node->val = sum ;
    transformBST(node->left,sum);
}
TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    transformBST(root,sum);
    return root;
}
