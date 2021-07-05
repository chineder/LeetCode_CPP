/************************************************************************************
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
Memory Usage: 6.1 MB, less than 10.23% of C++ online submissions for Reverse Integer.
************************************************************************************/

class Solution {
public:
    int reverse(int x){

        int y[10] ;
        int reverseX = 0 ;
        int carry = x >= 0 ? 1 : -1 ;
        
        //min int = -2147483648 max int = 2147483648-1 
        //min int ¨úµ´¹ï­È·|Ãz±¼
        if(x == INT_MIN)  return 0 ;
        x = abs(x) ;

        
        int i = 0 ;
        while(1)   
        {
            y[i] = x % 10 ;
            
            x = int(x /10) ;
            
            if(x > 0) i++;
            else break ;

        }
        

        for(int j = 0 ;  ; j++)
        {

            if(y[j] * pow(10,i)+ reverseX > INT_MAX )  return 0;            
            reverseX = y[j] * pow(10,i) + reverseX ;             
            
            if( i > 0)  i-- ;
            else break ;

        }
        
        reverseX = reverseX * carry ;
        
        if(reverseX > INT_MAX || reverseX < INT_MIN)  return 0;
        else return  reverseX ;
    }
};
      