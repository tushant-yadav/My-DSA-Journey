/**
234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.


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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return 1;
        ListNode *c = head,*p=NULL,*n, *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        if(n->next!=NULL && n->next->val == p->val) n = n->next;
        else if(p->val != n->val) return 0;
        while(n!=NULL){
            if(n->val!=p->val){
                return 0;
            }
            n = n->next;
            p = p->next;
        }
        if(p!=NULL) return 0;
        return 1;
         
    }
};
