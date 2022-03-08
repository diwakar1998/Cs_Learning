/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (69.50%)
 * Likes:    10820
 * Dislikes: 184
 * Total Accepted:    2M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2]
 * Output: [2,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 * 
 * 
 * 
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
 * 
 */

// @lc code=start
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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp1 = head;
        int count=0;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        else if(head->next->next == nullptr){
            swap(head->val,head->next->val);
            return head;
        }
        else{
            while(temp!= nullptr){
                count++;
                temp = temp->next;
            }            
            int tempcount = count;
            if(count%2 == 1){
                count = (count/2)+1;
            }
            else{
                count = count/2;
            }
            // cout<<count;
            while(count>0){
                ListNode* loophead=temp1; 
                for(int i=0;i<tempcount-1;i++){
                    loophead=loophead->next;
                }
                // cout<<head->val;
                swap(head->val,loophead->val);
                // cout<<loophead->val;
                head = head->next;
                tempcount--;
                count--;
                }
            }
            // cout<<count;
            // cout<<head->val;
            return temp1;
    }
};
// @lc code=end

