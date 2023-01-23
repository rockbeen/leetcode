
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
                deleteDuplicatesRecursion(head);
            return head;

        }
    void deleteDuplicatesRecursion(ListNode* head) {
            if (head == nullptr) return;
        
            if (head->next != nullptr && head->val == head->next->val) {
                ListNode* nodedelete = head->next;
                head->next = head->next->next;
                delete nodedelete;
                
                deleteDuplicatesRecursion(head);
                
            } else if(head->next != nullptr)
                deleteDuplicatesRecursion(head->next);
        }
};

 // 2 (medium)
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
// 3(easy)
class Solution {
public:
    bool isValid(string str) {
        stack<char> Stack;
        for(size_t i = 0; i < str.length(); ++i) {
            if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
                Stack.push(str[i]);
            }
            else {
                if(Stack.empty() == true) return false;
                if ((str[i] == '}' && Stack.top() == '{') || (str[i] == ')' && Stack.top() == '(')  || (str[i] == ']' && Stack.top() == '[')) {
                    Stack.pop();

                } else {
                   return false;
                }
            }
        }
        if(Stack.empty() == true) return true;
        else return false;

    }


};
// 4(easy)
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])) str.push_back(tolower(s[i]));
        }
        int l =0;
        int r = str.length() -1;
        while(l < r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
