/************************************************************************
�H�Ĥ@�Ӧr�ꬰ��ǡA�@���@�r���A�P�᭱�r�����
�ĤG��loop�p�G�J�줣�P�r�����Y�q��break�A

vector���u���@�Ӧr��A���ĤG��loop�A���|�i�J�C
����Ĥ@��loop�]���A�Ǧ^�`���סC

Runtime: 4 ms, faster than 74.03% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.1 MB, less than 92.52% of C++ online submissions for Longest Common Prefix.
************************************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        bool commonPrefix = true ;
        
        int length = 0;
        for(length = 0 ; length < strs[0].size() ; length++)
        {
            for(int j = 1 ; j < strs.size() ; j++)
            {
                if( strs[0].substr(length,1) != strs[j].substr(length,1))
                {
                    commonPrefix = false;
                    break ;
                }
            }

            if(!commonPrefix) break;
        }
        
        return strs[0].substr(0,length) ;
    }
};