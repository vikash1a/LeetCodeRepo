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
    bool helper(TreeNode* root, int targetSum, int currentSum){
        if(root==NULL)return false;
        currentSum+=root->val;
        // if(currentSum > targetSum)return false;
        if(root->left==NULL && root->right==NULL && currentSum==targetSum){
            return true;
        }
        if(helper(root->left,targetSum,currentSum))return true;
        if(helper(root->right,targetSum,currentSum))return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum,0);
    }
};