/**************************************************************************************
1.��Dynamic programming, 
2. "*" �T�ر��p�n�S�O�B�z
    a.���e�@����۲� 
    b.���e�@��O"."
    c."*"��zero���A�M�šA���e���ѷӡA���L"*"�Ψ�e�@�r�� e.g. mis* v.s. mi == true
3. vector �O (s.length() + 1 * p.length() + 1) ���G���}�C ==> +1 �O�h�@�� 0 ���Ŷ�
   ��S ,  P ��vector �s���O (0 ~ length - 1), debug �`�N��ӷ|�t1 
   vector[0][0] �O�šA vector[1][1]�O�Ĥ@�Ӧr s[0]��p[0] �ۤ�

Runtime: 4 ms, faster than 84.41% of C++ online submissions for Regular Expression Matching.
Memory Usage: 6.8 MB, less than 64.41% of C++ online submissions for Regular Expression Matching.
**************************************************************************************/
class Solution {
public:
    bool isMatch(string s, string p) {
        
        vector<vector<bool>> re(s.length() + 1, vector<bool>(p.length() + 1, false));    
        
        re[0][0] = true ;
        
        // .*.*.*.*  , a*b*c*d*,  a*.*b*.*,  �U�ض���* �O�ŦX�Ŧr�ꪺ       
        for(int i = 2 ; i <= p.size()   ; i = i + 2 )
        {
            if(p[i - 1] == '*') re[0][i] = re[0][i - 2];
        }
        
        
        for(int i = 1 ; i <= s.size()  ; i++ )
        {
            for(int j = 1 ; j <= p.size()  ; j++ )
            {
                
                if(s[i - 1] == p[j - 1]  or  p[j - 1] == '.') 
                {
                    re[i][j] = re[i-1][j-1];            
                }
                
                else if( p[j - 1] == '*')
                {
                    //a.���e�@����۲�  b.���e�@��O"." 
                    if((s[i - 1] == p[j - 1 - 1]  or  p[j - 1 - 1] == '.')) 
                    {
                        re[i][j] =  re[i - 1][j];
                    }
                    //c."*"��zero���A�M�šA���e���ѷӡA���L"*"�Ψ�e�@�r�� e.g. mis* v.s. mi == true
                    if(!re[i][j])
                    {
                        re[i][j] = re[i][j-2] ; 
                    }
                }
            }
        }
       
        return re[s.length()][p.length()] ;
    }
};