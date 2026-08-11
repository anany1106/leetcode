/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
class Solution {
public:
    // TC - O(N)
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr= head;
        while(curr != NULL && curr -> next != NULL)
        {
            ListNode *first= curr;
            ListNode *sec= curr -> next;

            int t= first -> val;
            first -> val = sec -> val;;
            sec ->val= t;

            curr = sec -> next;
        }
        return head;
    }
};

class Solution {
public:
    // TC - O(N)
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
    return head;

            ListNode *first= head;
            ListNode *sec= head -> next;

            int t= first -> val;
            first -> val = sec -> val;;
            sec ->val= t;

            swapPairs(sec -> next);
        return head;
    }
};
*/

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
    void reverse(ListNode*head,int times)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(times--)
        {
            ListNode*nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return head;
        }
        ListNode*res=NULL;
        ListNode*left = head;
        ListNode*right;
        ListNode*prevleft=NULL;
        int size=2;
        while(true)
        {
            right=left;
            for(int i=0;i<size-1;i++)
            {
                if(right==NULL)
                {
                    break;
                }
                right=right->next;
            }
           if(right) 
           { 
            ListNode*nextleft=right->next;
            reverse(left,size);
            if(prevleft)
              {
                prevleft->next=right;
              }
            prevleft=left;
            if(res==NULL)
                {
                    res=right;
                }
            left=nextleft; 
           }     
           else
            {
            if(prevleft)
              {
                prevleft->next=left;
              }
            break;
            }           
        }
        return res;        
    }
};