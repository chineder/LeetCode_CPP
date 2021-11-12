/*********************************************************************************
Runtime: 8 ms, faster than 99.15% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 11.4 MB, less than 71.34% of C++ online submissions for Reverse Nodes in k-Group.

用recursive的方式
想像把整個list切成k個一組k個一組的幾組list，分別做反轉


切到最後一段，如果整除，那呼叫recursive會等於NULL，直接 return 原head
切到最後一段，不到k個，也不反轉直接 return 原head

中間段回傳newhead，
利用loop回式往next走k-1步，可以找到第k個node，
當然，將k+1，k個，交給recursive找上新的k+1(下一段新的noehade)，
當原node(反轉後變成第k個)的node->next

**********************************************************************************/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL) return head ;
   
        ListNode *newhead, *currnode, *prevnode , *nextnode;

        newhead = head ;
        for(int i = 1 ; i < k ; i++)
        {
            if(newhead->next == NULL) return head;
            newhead = newhead->next ;
        }
        
        //此段順序很重要，不可誤
        currnode = head;
        nextnode = head->next;
        head->next = reverseKGroup(newhead->next , k);
        
        while(currnode != newhead)
        {
            prevnode = currnode;
            currnode = nextnode;
            nextnode = nextnode->next;

            currnode->next = prevnode;
         }

        return newhead ;
    }
    
};