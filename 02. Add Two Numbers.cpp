/*********************************************************************************
直接將相加的值update L1, 比new L3 list 省空間

first loop L1, L2 兩位數字及進位數字相加，直到
1. L1先結束,將L2尾端接到,L1->NXET = L2,L1仍沿著新的L1的路線
2. L2先結束或同時結束,L1仍沿著L1的路線

second loop
以上三種情況都有一共通點，至少其中一數己結束,只需再修正進位即可。
特殊情形即L1 己經NULL,仍有進位，
目前做法是從HEAD(一開始即ASSIGN L1)，再從跑一次至L1->NEXT == NULL時，將新NODE接上，
後續調整新做法。

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
        while(l2 != NULL) // 等同while(l1 != NULL and l2 != NULL)
        {
            /*
                錯誤寫法！！第一行後，l1->val被修正，第二行MathCarry有可能出錯， 
                順序對調的話，且同樣概念變成 l1->val 出錯。 
                l1->val = (l1->val + l2->val + MathCarry) % 10 ;
                MathCarry = (l1->val + l2->val + MathCarry) / 10 ;
                
                所以一定要先加總，再計算 % , /
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
                
                //MathCarry = 0 ;//己經最後一位了，進位清空，避免又入loop，造成不必要的error
                return head ; //如果不管進位，最後一位了，直接return效率更快
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