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
    TreeNode* helper(int ps, int pe, vector<int>& preorder, int is, int ie, vector<int>& inorder){
        if(ps > pe || is > ie) return NULL;
        TreeNode* node = new TreeNode(preorder[ps]);
        int count = is;
        while(inorder[count] != preorder[ps]){
            count++;
        }
        int leftSize = count - is;
        node->left = helper(ps+1,ps + leftSize,preorder,is,count-1,inorder);
        node->right = helper(ps + leftSize + 1,pe,preorder,count + 1, ie, inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,preorder.size() - 1, preorder, 0, inorder.size() - 1, inorder);
    }
};