class Solution {
public:
    bool isPalindrome(int x) {
        
        if( x < 0) return false;
        
        string s ;
        s = to_string(x) ;

        int i = 0 ,j = s.length()-1 ;       
             
        for( ; i <= j ; i++ , j-- )
        {   
            if(s.substr(i,1) != s.substr(j,1)) return false ;
        }
        
        
        return true ;

    }
};