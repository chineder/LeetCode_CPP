/************************************************************************************
1.先用一個head指向min的node，做為開頭
2.currn負責跟著尋訪，並更改l1,l2的中next的連結位置。
  重要是currn得先new一個記憶，不能貪方便一開始就跟head指向同一個地方，
  否則，第一次比完更改連結，會造成infinite loop
  e.g. [1,2,4] [2,3,4] currn沒有new，直接point to 1，第一次loop currn->next = l1 後，
        currn->next == currn ，infinite loop
  
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