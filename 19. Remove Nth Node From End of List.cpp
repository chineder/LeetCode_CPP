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

/*******************************************************************
兩個指標，其一先行N個後，另一個再一起前進。

雙指標間保持持間格N，先行指標到底後，後行指向距離N的位置

*******************************************************************/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next == NULL) return NULL;
        ListNode *tail = head, *currn = head;
        
        while( n > 0 )
        {
            tail = tail->next ;
            n--;
            
            if(tail == NULL) //跑到底
            {
                if(n == 0) return head->next; //如果是剛好跑完，代掉刪掉的是第一個
                else return NULL; //否則表示 N > 總個數
            }
        }

        
        while( tail->next != NULL )
        {
            tail = tail->next ;
            currn = currn->next ;
        }
        
        currn->next = currn->next->next ;
        
       return head ; 
        
    }
};