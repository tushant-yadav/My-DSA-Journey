/**
25. Reverse Nodes in k-Group
https://leetcode.com/problems/reverse-nodes-in-k-group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt =k;
        ListNode* temp = head;
        while( temp!=NULL && k--){
            temp=temp->next;
        }
        ListNode* p = NULL;
        cout<<k<<endl;
        if(k>0) return head;
        else p = reverseKGroup(temp,cnt);
        ListNode *c=head, *n=head;
        while(c!=NULL && cnt--){
            cout<<c->val<<endl;
            n = c->next;
            c->next = p;
            p = c;
            c=n;
        }
        return p;       
    }
};
