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
    void preorder(TreeNode* root, TreeNode* &prev){
        if(!root) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(prev == NULL){
            prev = root;
        }else{
            prev->right = root;
            prev = prev->right;
        }
        prev->left = NULL;
        preorder(left,prev);
        preorder(right,prev);


    }
    void flatten(TreeNode* root){
        TreeNode* prev = NULL;
        preorder(root,prev);
    }
};