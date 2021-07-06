/*********************************************************************************
�����N�ۥ[����update L1, ��new L3 list �٪Ŷ�

first loop L1, L2 ���Ʀr�ζi��Ʀr�ۥ[�A����
1. L1������,�NL2���ݱ���,L1->NXET = L2,L1���u�۷s��L1�����u
2. L2�������ΦP�ɵ���,L1���u��L1�����u

second loop
�H�W�T�ر��p�����@�@�q�I�A�ܤ֨䤤�@�Ƥv����,�u�ݦA�ץ��i��Y�i�C
�S���ΧYL1 �v�gNULL,�����i��A
�ثe���k�O�qHEAD(�@�}�l�YASSIGN L1)�A�A�q�]�@����L1->NEXT == NULL�ɡA�N�sNODE���W�A
����վ�s���k�C

Runtime: 20 ms, faster than 93.74% of C++ online submissions for Add Two Numbers.
Memory Usage: 70.8 MB, less than 97.19% of C++ online submissions for Add Two Numbers.
*********************************************************************************/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if( l1 == NULL ) return l2;
        if( l2 == NULL ) return l1;
        
        ListNode* head = l1;
        int MathCarry = 0 ;
        
        //cout << 10 % 10 << endl ;
        
        int tmpsum = 0 ; 
        while(l2 != NULL) // ���Pwhile(l1 != NULL and l2 != NULL)
        {
            /*
                ���~�g�k�I�I�Ĥ@���Al1->val�Q�ץ��A�ĤG��MathCarry���i��X���A 
                ���ǹ�ժ��ܡA�B�P�˷����ܦ� l1->val �X���C 
                l1->val = (l1->val + l2->val + MathCarry) % 10 ;
                MathCarry = (l1->val + l2->val + MathCarry) / 10 ;
                
                �ҥH�@�w�n���[�`�A�A�p�� % , /
            */
            tmpsum = l1->val + l2->val + MathCarry ;
            l1->val = tmpsum % 10 ;
            MathCarry = tmpsum / 10 ;
         
            
            l2 = l2->next;
            
            if(l1->next == NULL and l2 != NULL) 
            {
                l1->next = l2 ;
                l1 = l1->next;
                break ;
            }
            else l1 = l1->next;    
        }
        
        /*******************************************************************************/
        
        while(MathCarry != 0 )
        { 
            if(l1 == NULL)
            {
                ListNode* tail = new ListNode(MathCarry) ; 

                l1 = head ;
                while(l1->next != NULL)
                {
                  l1 = l1->next ;  
                }
                l1->next = tail ;   
                
                //MathCarry = 0 ;//�v�g�̫�@��F�A�i��M�šA�קK�S�Jloop�A�y�������n��error
                return head ; //�p�G���޶i��A�̫�@��F�A����return�Ĳv���
            }
            else
            {
               
                tmpsum = l1->val + MathCarry ;
                MathCarry = tmpsum / 10 ;
                l1->val = tmpsum % 10 ;
                
                l1 = l1->next ;
            }
        }

        return head ;
    }

};