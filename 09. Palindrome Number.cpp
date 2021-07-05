/************************************************************************************
Runtime: 20 ms, faster than 21.34% of C++ online submissions for Palindrome Number.
Memory Usage: 6 MB, less than 27.06% of C++ online submissions for Palindrome Number.
************************************************************************************/

class Solution {
public:
    bool isPalindrome(int x) {
        
        if( x < 0) return false;
        
        string s ;
        s = to_string(x) ;

        for(int i = 0 ,j = s.length()-1 ; i <= j ; i++ , j-- )
        {   
            if(s.substr(i ,1 ) != s.substr(j ,1)) return false ;
        }
        return true ;
    }
};