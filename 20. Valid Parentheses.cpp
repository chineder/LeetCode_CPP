/**************************************************************
�Q��stack �������A�Ȧs�bs1
�u�n�X�{, ')','}',']',�o�T�زŸ��As1 pop �X�̫�@�Ӧr���ä��A

��異�ѡA�N�Ofalse�A

�䥦�Ÿ��N�@���[�Js1���ݡA

�̫�s1���ݲM�šA�_�hfalse

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6 MB, less than 99.44% of C++ online submissions for Valid Parentheses.
**************************************************************/

class Solution {
public:
    bool isValid(string s) {

        string s1 = "";
        
        for(auto i : s)
        {   
            if( i == ')')
            {
                if( s1.back() == '(') s1.pop_back();
                else return false ;
            }
            else if( i == '}')
            {
                if( s1.back() == '{') s1.pop_back();
                else return false ;
            }
            else if( i == ']')
            {
                if( s1.back() == '[') s1.pop_back();
                else return false ;
            }
            else s1.push_back(i);
        }
                
        if(! s1.empty()) return false ;
        else return true ;
    }   
};