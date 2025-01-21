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
    void util(TreeNode* root, int& sum){
        if(root==NULL)return;
        if(root->left == NULL && root->right == NULL){
            sum+=root->val;
            root->val = sum;
            return;
        }
        util(root->right,sum);
        sum+=root->val;
        root->val = sum;
        util(root->left,sum);

    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        util(root,sum);
        return root;
    }
};
/*
postorder - 
8,7,5,21

inoder - 
8,7,6,5,4,3,2,1,36

*/