/*********************************************************************************
Runtime: 8 ms, faster than 99.15% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 11.4 MB, less than 71.34% of C++ online submissions for Reverse Nodes in k-Group.

��recursive���覡
�Q������list����k�Ӥ@��k�Ӥ@�ժ��X��list�A���O������


����̫�@�q�A�p�G�㰣�A���I�srecursive�|����NULL�A���� return ��head
����̫�@�q�A����k�ӡA�]�����ઽ�� return ��head

�����q�^��newhead�A
�Q��loop�^����next��k-1�B�A�i�H����k��node�A
��M�A�Nk+1�Ak�ӡA�浹recursive��W�s��k+1(�U�@�q�s��noehade)�A
���node(������ܦ���k��)��node->next

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
        
        //���q���ǫܭ��n�A���i�~
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