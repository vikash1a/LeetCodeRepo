/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        ListNode temp1 = new ListNode(-1);
        ListNode temp = temp1;
        temp.next = head;
        HashSet<Integer> hs = new HashSet<Integer>();
        for(Integer k: nums){
            hs.add(k);
        }
        while(temp!= null){
            ListNode current = temp.next;
            if(current!=null && hs.contains(current.val)){
                temp.next = current.next;
            }
            else{
                temp = temp.next;
            }
        }
        return temp1.next;
    }
}