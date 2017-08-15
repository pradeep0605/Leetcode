/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* NewListNode(int x = 0) {
    return new ListNode(x);
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *list1 = l1, *list2 = l2;
        ListNode *result = nullptr, *curr_node = nullptr;
        
        int carry = 0;
        while (list1 || list2) {
            int ans = (list1 ? list1->val : 0)  + (list2 ? list2->val : 0) + carry;
            carry = 0;
            if (ans >= 10) {
                ans = ans % 10;
                carry = 1;
            }
            
            if(result == nullptr) {
                result = NewListNode(ans);
                curr_node = result;
                
            } else {
                curr_node->next =  NewListNode(ans);
                curr_node = curr_node->next;
            }
            if (list1) {list1 = list1->next;}
            if (list2) {list2 = list2->next;}
        }
        if (carry) {
            curr_node->next = NewListNode(carry);
        }
        return result;
    }
};