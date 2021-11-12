/*****************************************************************
Runtime: 64 ms, faster than 57.00% of C++ online submissions for Implement strStr().
Memory Usage: 368.7 MB, less than 11.93% of C++ online submissions for Implement strStr().

截字串比對
haystack從頭開始，截子字串跟needle 比對
*****************************************************************/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(haystack.size() == 0 && needle.size() == 0) return 0 ;
        if(haystack.size() < needle.size()) return -1 ;
        
        for( int i = 0 ; i <= haystack.size() - needle.size() ; i++)
        {
            if(haystack.substr(i,needle.size()) == needle) return i ;
        }
        
        return -1 ;  
    }
};