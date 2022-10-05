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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }
        queue<TreeNode*> qu;
        int currentDepth = 1;
        qu.push(root);
        // TreeNode* node = root;
        while(true){
            if(currentDepth == depth-1){
                break;
            }
            queue<TreeNode*> quTemp;
            while(!qu.empty()){
                TreeNode* front = qu.front();
                qu.pop();
                if(front->left!=NULL)quTemp.push(front->left);
                if(front->right!=NULL)quTemp.push(front->right);
            }
            qu = quTemp;
            currentDepth+=1;
        }
        while(!qu.empty()){
            TreeNode* front = qu.front();
            qu.pop();
            TreeNode* left = front->left;
            TreeNode* right = front->right;
            front->left = new TreeNode(val);
            front->left->left = left;
            front->right = new TreeNode(val);
            front->right->right = right;
        }
        return root;
    }
};