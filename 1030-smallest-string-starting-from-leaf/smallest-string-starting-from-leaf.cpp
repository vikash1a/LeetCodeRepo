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
    void dfs(TreeNode* root, string currentString, string& smallestString){
        if(root == NULL)return;
        currentString += root->val+'a';
        if(root->left == NULL && root->right == NULL){
            reverse(currentString.begin(), currentString.end());
            // cout<<currentString<<endl;
            if(smallestString == "")smallestString = currentString;
            else smallestString = min(smallestString, currentString);
            return;
        }
        dfs(root->left, currentString, smallestString);
        dfs(root->right, currentString, smallestString);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string smallestString = "";
        dfs(root, "", smallestString);
        return smallestString;
    }
};