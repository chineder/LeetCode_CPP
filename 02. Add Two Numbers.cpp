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
     
        long sum = 0 ;
        
        sum = ListToNum(l1) + ListToNum(l2) ;
        
        if (sum == 0 ){
            ListNode* zero = new ListNode(0) ;
             return zero ;
        }
        
        return  NumToList(sum) ;
    }

private:
    
    long ListToNum(ListNode* lis)
    {
        long Num = 0 ;        
        int i = 0 ;
        while(lis != NULL){        
            Num = Num + lis->val * pow(10,i) ;
            lis = lis->next ;  
            i++;
        }
        
        return Num ;
    }
        
    ListNode* NumToList(int sum){
        
        if(sum<= 0 ) return NULL ;
        
        ListNode* node =  new ListNode(sum % 10);
        node->next = NumToList(sum / 10);
                
        return node ;
    }
};