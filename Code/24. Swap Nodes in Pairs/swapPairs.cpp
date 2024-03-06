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
    int check(ListNode* head, int k){
        ListNode* t = head;
        while(k && t)
            k--, t = t->next;
        return k == 0;
    }

    ListNode* reverseK(ListNode* head, int k){
        if(!head || !check(head, k)) return head;
        ListNode *prev = NULL, *cur = head, *nxt = NULL, *first = head;
        
        int count = 0;
        while(count++ < k){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        first->next = reverseK(cur, k);
        return prev; 
    }

public:
    ListNode* swapPairs(ListNode* head) {
        return reverseK(head, 2);
    }
};