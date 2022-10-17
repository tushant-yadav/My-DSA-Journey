/**
61. Rotate List
https://leetcode.com/problems/rotate-list
Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head ==NULL || head->next == NULL) return head;
        int cnt = 0;
        ListNode *f = head,*b = head,*p;
        while(f!=NULL){
            cnt++;
            f = f->next;
        }
        f = head;
        k = k%cnt;
        if(k==0) return head;
        for(int i=0;i<k;i++){
            //if(f->next!=NULL) f=head;
            f = f->next;
        }
        //f = f->next;
        while(f!=NULL && f->next!=NULL){
            f = f->next;

            b = b->next;
        }
        f->next = head;
        head = b->next;
        cout<<b->val;
        b->next = NULL;
        return head;
        
    }
};
