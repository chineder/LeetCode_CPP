/* 
1. ����إi��A�@�جO����������@�Ӧr��e.g. abcba�A�t�@�ج����r��e.g. abccba
2. �Hindex�����ߡA�V��������sub string �A�e�q���̫�r���q���̫e�r�@�Ӥ@�Ӥ��
3. Recurisve is "Time Limit Exceeded"

*/

class Solution {
public:
    string longestPalindrome(string s) 
    {
    
        if(s.empty()) return "" ;
        
        int max = 1 ;
        int tmp = 0 ;
        int midchar = 0 ;
        
        // Palindromic Substring ����������Ʀr�� e.g. aba
        for(int i = 0 ; i < s.size() - 1 ; i++)
        {
            tmp = CompareString(s.substr( 0 , i ),s.substr(i+1 , s.size()-i ));
            
            if(max < tmp * 2 + 1)
            {
                max = tmp * 2 + 1 ;//�[�쥻�����������@��
                midchar = i ;
            }
            //�Ѿl�٨S������r�������ߪ����p�U�A 
            //�N��̪��]��v��Palindromic Substring�ٵu�N���Τ�F
            if((s.size() - i) * 2 + 1 < max ) break ;
        }  

        
        // Palindromic Substring �����������Ʀr�� e.g. abba
        for(int i = 0 ; i < s.size()-1 ; i++)
        {
            if(s.substr( i , 1 ) == s.substr( i + 1, 1 ))
            {
                tmp = CompareString(s.substr( 0 , i ),s.substr(i + 2, s.size() - i - 1 ));

                if(max < tmp * 2 + 2)
                {
                    max = tmp * 2 + 2 ;//�[�쥻�������������
                    midchar = i ;
                }
            
		//�Ѿl�٨S������r�������ߪ����p�U�A 
            	//�N��̪��]��v��Palindromic Substring�ٵu�N���Τ�F
               if((s.size() - i) * 2 + 2 < max ) break ;
            }
        }   

        if(max % 2 == 1) return s.substr(midchar - (max-1)/2,max);
        else return s.substr(midchar - (max-2)/2, max);
    }
    
    int CompareString(string s1, string s2)
    {
        if(s1.empty() || s2.empty()) return 0 ;
        if(s1.back() != s2.front()) return 0 ;

        return CompareString(s1.substr(0,s1.size()-1),s2.substr(1,s2.size()-1)) + 1 ;       
    }
};