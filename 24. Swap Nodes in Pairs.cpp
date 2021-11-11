/*****************************************************************************
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 7.5 MB, less than 91.51% of C++ online submissions for Swap Nodes in Pairs.

如果少於兩個點，直接回傳head


初始 
tempA為尚未調整時的第一個點，調整後為第二個點
tempB為尚未調整時的第二個點，調整後為第一個點
tempC很重要！！暫存A，用來給B回指，而且要修正C->next的正確位置(即原本3位調到4，需修正指到調整後的3)

head指向調整後尚未調整時的第二個點，調整後為第一個點 (head = nede2)

1->2 , 2->3 , 3->4 , 4->5 
1->3 , 2->3 , 3->4 , 4->5
1->3 , 2->1 , 3->4 , 4->5

1->3 , 2->3 , 3->5 , 4->5
1->3 , 2->1 , 3->5 , 4->3 (沒有c的話！這裡2->1->3->5，4斷掉!!所以c->next要修正)

1->4 , 2->1 , 3->5 , 4->3

*****************************************************************************/

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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head ;
        
        ListNode *tempA, *tempB , *tempC;

        tempA = head ;      
        tempB = tempA->next ;
        tempC = head ;
        
        head = head->next ;

        while(tempA->next != NULL )
        {

            tempA->next = tempB->next;
            tempB->next = tempC ;
        
            if(tempA->next == NULL || tempA->next->next == NULL) break ;
            tempA = tempA->next ;
            tempB = tempA->next ;
            tempC->next = tempB ;
            tempC = tempA ;

        }

        
        return head ;
    }
};