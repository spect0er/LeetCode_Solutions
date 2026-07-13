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
    void dfs(TreeNode* root,TreeNode* parent, int depth, int x, int y, int& depthX, int& depthY, TreeNode* &parentX, TreeNode* &parentY){
        if(!root) return;
        if(root->val == x){
            depthX = depth;
            parentX = parent;
        }
        if(root->val == y){
            depthY = depth;
            parentY = parent;
        }
        dfs(root->left,root,depth+1, x,y,depthX,depthY,parentX,parentY);
        dfs(root->right,root,depth+1, x,y,depthX,depthY,parentX,parentY);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        int depthX = 0, depthY = 0;
        TreeNode* parentX = NULL;
        TreeNode* parentY = NULL;
        dfs(root,NULL,0,x,y,depthX,depthY,parentX,parentY);
        return (depthX == depthY) && (parentX != parentY);
    }
};