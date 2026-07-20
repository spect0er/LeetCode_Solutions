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
    void helper(TreeNode* root, vector<string>& result, string s){
        if(!root) return;
        s += to_string(root->val);
        if(!root->left and !root->right){
            result.push_back(s);
        }
        s += "->";
        helper(root->left,result,s);
        helper(root->right,result,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(!root) return result;
        string s = "";
        helper(root,result,s);
        return result;
    }
};