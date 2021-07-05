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
��ӫ��СA��@����N�ӫ�A�t�@�ӦA�@�_�e�i�C

�����ж��O��������N�A������Ш쩳��A�����V�Z��N����m

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
            
            if(tail == NULL) //�]�쩳
            {
                if(n == 0) return head->next; //�p�G�O��n�]���A�N���R�����O�Ĥ@��
                else return NULL; //�_�h��� N > �`�Ӽ�
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