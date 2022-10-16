/**
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p , *r = l1 ;
        int c=0;
        while(l1!=NULL && l2!=NULL){
            l1->val = l1->val+l2->val+c;
            c = l1->val/10;
            l1->val = l1->val%10;
            p = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1==NULL && l2!=NULL){
            p->next = l2;
            l1 = l2;
        }
        while(l1!=NULL and c!=0){
            l1->val = l1->val+c;
            c = l1->val/10;
            l1->val = l1->val%10;
            p = l1;
            l1=l1->next;
        }
        if(c!=0){
            ListNode *b = new ListNode(c);
            p->next = b;
        }
        return r;


    }
};
