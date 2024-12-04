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
    void util(TreeNode* root, int& minDepthValue, int width){
        if(root==NULL)return;
        if(root->left ==NULL && root->right==NULL){
            minDepthValue = min(minDepthValue, width);
            return;
        }
        util(root->left, minDepthValue, width+1);
        util(root->right, minDepthValue, width+1);
        return;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int minDepthValue = INT_MAX;
        util(root, minDepthValue, 1);
        return minDepthValue;
    }
};