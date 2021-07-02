/* 
1. 有兩種可能，一種是正中間為單一個字元e.g. abcba，另一種為雙字元e.g. abccba
2. 以index為中心，向兩邊切兩個sub string ，前段的最後字跟後段的最前字一個一個比較
*/

class Solution {
public:
    string longestPalindrome(string s) 
    {
    
        if(s.empty()) return "" ;
        
        int max = 1 ;
        int tmp = 0 ;
        int midchar = 0 ;
        
        // Palindromic Substring 正中間為單數字組 e.g. aba
        for(int i = 0 ; i < s.size() - 1 ; i++)
        {
            tmp = CompareString(s.substr( 0 , i ),s.substr(i+1 , s.size()-i ));
            
            if(max < tmp * 2 + 1)
            {
                max = tmp * 2 + 1 ;//加原本正中間的那一格
                midchar = i ;
            }
            //剩餘還沒比較的字元為中心的情況下， 
            //就算最長也比己知Palindromic Substring還短就不用比了
            if((s.size() - i) * 2 + 1 < max ) break ;
        }  

        
        // Palindromic Substring 正中間為雙數字組 e.g. abba
        for(int i = 0 ; i < s.size()-1 ; i++)
        {
            if(s.substr( i , 1 ) == s.substr( i + 1, 1 ))
            {
                tmp = CompareString(s.substr( 0 , i ),s.substr(i + 2, s.size() - i - 1 ));

                if(max < tmp * 2 + 2)
                {
                    max = tmp * 2 + 2 ;//加原本正中間的那兩格
                    midchar = i ;
                }
            
            	//剩餘還沒比較的字元為中心的情況下， 
            	//就算最長也比己知Palindromic Substring還短就不用比了
               if((s.size() - i) * 2 + 2 < max ) break ;
            }
        }   

        if(max % 2 == 1) return s.substr(midchar - (max-1)/2,max);
        else return s.substr(midchar - (max-2)/2, max);
    }
    
    int CompareString(string s1, string s2)
    {
        int i = 0 ;
        while(1)
        {
            if(s1.empty() || s2.empty()) break ;
            if(s1.back() != s2.front()) break ;
            
            s1.pop_back();
            s2.erase(0,1); 
            i++ ;
        }
        return i ;        
    }
};