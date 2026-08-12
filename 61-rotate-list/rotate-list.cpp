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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=1;
        int count=1;
        if(head == NULL)
        return NULL;
        ListNode* last = head;
        while( last -> next != NULL)
        {
            n++;
            last = last -> next;
        }
        k= k%n;
        if(k==0)
        return head;

        ListNode* t= head;
        while(t)
        {
            if(count == (n-k))
            {
                break;
            }
            count++;
            t = t -> next;
        }
        ListNode* res= t ->next;
        last ->next = head;
        t -> next = NULL;
        return res;

    }
};