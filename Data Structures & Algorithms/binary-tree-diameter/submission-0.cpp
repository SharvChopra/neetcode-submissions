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

class Solution {
public:
    int diameter = 0;
    int diameterCalculate(TreeNode* node, int&diameter_max){
        if(!node) return 0;

        int left = diameterCalculate(node->left, diameter_max);
        int right = diameterCalculate(node->right, diameter_max);

        diameter_max = max(diameter_max, left+right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameterCalculate(root, diameter);
        return diameter;
    }
};
