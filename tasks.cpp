
// 1 (easy)
/**
 * Definition for singly-linked list->
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
    ListNode* deleteDuplicates(ListNode* head) {
            if(head != nullptr) 
                deleteDuplicatesVal(head);
            return head;

        }
    void deleteDuplicatesVal(ListNode* head) {
            if (head == nullptr) return;
            if(head->next != nullptr && head->val == head->next->val) {
                 head->next = head->next->next;
                 deleteDuplicatesVal(head);
                // if(head->next->next != nullptr) {
                //     head->next = head->next->next;
                //     deleteDuplicatesVal(head->next);
                // } else {
                //     head = nullptr;
                //     return;
                // }
            } else if(head->next != nullptr)
                deleteDuplicatesVal(head->next);
            // else if(head->val == head->next->val)
            //     head->next = nullptr;  
        }
};

/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // 2 (medium)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lResult = new ListNode;
        ListNode* cur = lResult;
        bool more10 = false;

        while (l1 || l2) {
            
            if(l1 == nullptr) {
                if (more10) cur->val = l2->val + 1;
                else cur->val = l2->val;
            } else if(l2 == nullptr) {
                if (more10) cur->val = l1->val + 1;
                else cur->val = l1->val;
            } else {
                if (more10) cur->val = l1->val + l2->val + 1;
                else cur->val = l1->val + l2->val;
            }
            more10 = false;
            if (cur->val >= 10) {
                cur->val-=10;
                more10 = true;
            }
            if (l1 != nullptr)  l1 = l1->next;
            if (l2 != nullptr)  l2 = l2->next;
            
            if (l1 || l2) {    
                ListNode* next = new ListNode;
                cur->next = next;
                cur = cur->next;
                }
        }
        if (more10) {
            ListNode* next = new ListNode;
            cur->next = next;
            cur = cur->next;
            cur->val = 1;
        }
        return lResult;
    }
};
