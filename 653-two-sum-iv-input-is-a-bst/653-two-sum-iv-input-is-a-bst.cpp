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
    //this can also be done using storing all element in vector
    TreeNode* mainRoot;
    bool find(TreeNode* root,int k,int count){
        if(root == NULL)return false;
        // cout<<root->val<<"-"<<count<<endl;
        if(k < root->val){
            if(find(root->left,k,count)) return true;
        }
        else if (k == root->val) {
            if(count==2){
                if(find(root->right,k,count-1)) return true;
            }
            else return true;
        }
        else if(k > root->val) {
            if(find(root->right,k,count)) return true;
        }
        return false;
    }
    bool helper(TreeNode* root, int k){
        if(root == NULL)return false;
        int val = root->val;
        // cout<<val<<endl;
        if(val == k-val){
            if(find(mainRoot,k-val,2))return true;
        }
        else{
            if(find(mainRoot,k-val,1))return true;
        }
        if(helper(root->left,k))return true;
        if(helper(root->right,k))return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        mainRoot = root;
        return helper(root,k);
    }
};