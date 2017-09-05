/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    
public:
    void DisplayList(RandomListNode * head) {
        while(head != nullptr) {
            cout << head->label << ":" << head << ":" << head->next << ":" << head->random <<  ", ";
            head = head->next;
        }
        cout << endl;
    }
    
    void CreateAndInterplaceList(RandomListNode *head) {
        while(head != nullptr) {
            RandomListNode *new_node = new RandomListNode(head->label);
            RandomListNode *next_node = head->next;
            new_node->next = head->next;
            head->next = new_node;
            head = next_node;
        }
    }
    void FixRandomPointers(RandomListNode* head) {
        RandomListNode *node = head;
        while (node != nullptr) {
            RandomListNode *copy_node = node->next;
            copy_node->random = (node->random != nullptr) ? node->random->next : nullptr;
            // move the 'node' pointer.
            node = copy_node->next;
        }
    }
    
    void FixNextPointers(RandomListNode* head) {
        RandomListNode *node = head;
        while (node != nullptr) {
            RandomListNode *copy_node = node->next;
            node->next = copy_node->next;
            copy_node->next = (copy_node->next) ? copy_node->next->next : nullptr;
            node = node->next;
        }
    }
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        // DisplayList(head);
        CreateAndInterplaceList(head);
        //DisplayList(head);
        RandomListNode *head2 = head->next;
        FixRandomPointers(head);
        FixNextPointers(head);
        //DisplayList(head);
        //DisplayList(head2);
        return head2;
    }
};