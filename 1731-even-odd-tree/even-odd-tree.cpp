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
    bool check(queue<TreeNode*> qu, bool isOdd){
        int last;
        if(isOdd)last = INT_MAX;
        else last = INT_MIN;
        while(!qu.empty()){
            int front = qu.front()->val;
            qu.pop();
            if(isOdd){
                if(front%2!=0 || front>=last)return false;
            }
            else {
                if(front%2==0 || front<=last)return false;
            }
            last = front;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        bool isOdd = false;
        while(!qu.empty()){
            if(!check(qu, isOdd))return false;
            queue<TreeNode*> temp;
            while(!qu.empty()){
                if(qu.front()->left!=NULL)temp.push(qu.front()->left);
                if(qu.front()->right!=NULL)temp.push(qu.front()->right);
                qu.pop();
            }
            qu = temp;
            isOdd = !isOdd;
        }
        return true;
    }
};