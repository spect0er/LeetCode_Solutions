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
    void helper(TreeNode* root, int targetSum, vector<int>path, vector<vector<int>>& result){
        if(!root) return;
        targetSum -= root->val;
        path.push_back(root->val);
        if(!root->left and !root->right and targetSum == 0){
            result.push_back(path);
            return;
        }
        if(!root->left and !root->right and targetSum != 0) return;
        helper(root->left,targetSum,path,result);
        helper(root->right,targetSum,path,result);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        if(!root) return result;
        vector<int>path;
        helper(root,targetSum,path,result);
        return result;
    }
};