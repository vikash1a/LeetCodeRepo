/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int numComponentsValue = 0;
        unordered_set<int> ust;
        for(int k: nums)ust.insert(k);
        bool isLastPresent = false;
        while(head!=NULL){
            if(ust.find(head->val)==ust.end()){
                if(isLastPresent){
                    numComponentsValue+=1;
                    isLastPresent = false;
                }
            }
            else isLastPresent = true;
            head = head->next;
        }
        if(isLastPresent)numComponentsValue+=1;
        return numComponentsValue;
    }
};