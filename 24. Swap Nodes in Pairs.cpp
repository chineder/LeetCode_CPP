/*****************************************************************************
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 7.5 MB, less than 91.51% of C++ online submissions for Swap Nodes in Pairs.

�p�G�֩����I�A�����^��head


��l 
tempA���|���վ�ɪ��Ĥ@���I�A�վ�ᬰ�ĤG���I
tempB���|���վ�ɪ��ĤG���I�A�վ�ᬰ�Ĥ@���I
tempC�ܭ��n�I�I�ȦsA�A�Ψӵ�B�^���A�ӥB�n�ץ�C->next�����T��m(�Y�쥻3��ը�4�A�ݭץ�����վ�᪺3)

head���V�վ��|���վ�ɪ��ĤG���I�A�վ�ᬰ�Ĥ@���I (head = nede2)

1->2 , 2->3 , 3->4 , 4->5 
1->3 , 2->3 , 3->4 , 4->5
1->3 , 2->1 , 3->4 , 4->5

1->3 , 2->3 , 3->5 , 4->5
1->3 , 2->1 , 3->5 , 4->3 (�S��c���ܡI�o��2->1->3->5�A4�_��!!�ҥHc->next�n�ץ�)

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