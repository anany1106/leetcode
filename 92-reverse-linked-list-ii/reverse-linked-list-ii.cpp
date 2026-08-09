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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if( right == left ) return head;
        if( head == NULL ) return NULL;
        ListNode* t= head;
        ListNode* before = NULL;
        int pos=1;
        while( t != NULL)
        {
            if( pos < left )
            {
                before = t;
                t= t -> next;
                pos++;
                continue;
            }
            ListNode* curr= t;
            int times= right-left+1;
            ListNode* prev= NULL;
            
            while(times-- )
            {
                ListNode* nex= curr -> next;
                curr -> next = prev;
                prev = curr;
                curr= nex;
            }
            t -> next= curr;
            if(before)
            {
                before -> next = prev;
                return head;
            }
            else
            return prev;
        }
        return head;
    }
};