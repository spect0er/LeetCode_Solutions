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
    int helper(TreeNode* root, int& maxDia){
        if(!root) return 0;
        int leftH = helper(root->left,maxDia);
        int rightH = helper(root->right,maxDia);
        maxDia = max(maxDia,leftH + rightH);
        return 1 + max(leftH,rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }
};