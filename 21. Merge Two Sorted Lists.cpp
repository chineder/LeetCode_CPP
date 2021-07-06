/************************************************************************************
1.���Τ@��head���Vmin��node�A�����}�Y
2.currn�t�d��۴M�X�A�ç��l1,l2����next���s����m�C
  ���n�Ocurrn�o��new�@�ӰO�СA����g��K�@�}�l�N��head���V�P�@�Ӧa��A
  �_�h�A�Ĥ@���񧹧��s���A�|�y��infinite loop
  e.g. [1,2,4] [2,3,4] currn�S��new�A����point to 1�A�Ĥ@��loop currn->next = l1 ��A
        currn->next == currn �Ainfinite loop
  
Runtime: 4 ms, faster than 96.11% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 14.8 MB, less than 86.87% of C++ online submissions for Merge Two Sorted Lists.
************************************************************************************/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if( l1 == NULL || l2 == NULL)
        {
            if( l1 != NULL) return l1 ;
            else if( l2 != NULL ) return l2 ;
            else return NULL; 
        }
        
        ListNode *head , *currn = new ListNode;
        
        head = l1->val <= l2->val ? l1 : l2 ;


        while(l1 != NULL and l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                currn->next = l1 ;
                l1 = l1-> next ; 

            }
            else if(l1->val > l2->val)
            {  
                currn->next = l2 ;
                l2 = l2-> next ;
            }
            
            currn = currn-> next ;
        }
        
        if( l1 != NULL) currn->next = l1  ;
        else if( l2 != NULL ) currn->next = l2  ;       
        
        return head ;
    }
};