/*��J�O�ߤ@�r��A�ڭ̭n�b�䤤���r�������ƪ��l�r��C
�p�G�o�Ӧr���w�g�s�b�}�C���A�h�@���R���}�C�}�Y���ȡA�����e�P�_���r�����s�b��}�C������C
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