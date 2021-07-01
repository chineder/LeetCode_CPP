/*輸入是唯一字串，我們要在其中找到字元不重複的子字串。
如果這個字元已經存在陣列中，則一直刪除陣列開頭的值，直到當前判斷的字元不存在於陣列中為止。
*/


#include<string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0 ;
        string substr = "" ;
        
        for(int i = 0 ; i <s.size() ; i++)
        {
           while( substr.find(s[i],0) != -1)
	   // == while( substr.find(s[i],0) != std::string::npos)
            {
                substr = substr.assign(substr,1,substr.size()-1);               
            }
            
            substr = substr + s[i] ;
            max= max > substr.size() ? max : substr.size() ;
       } 
        
        return max ; 
    }
};