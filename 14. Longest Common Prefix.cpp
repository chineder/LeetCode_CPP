/************************************************************************
�H�Ĥ@�Ӧr�ꬰ��Ǥ@���@�Ӧr���A�P�᭱�r�����
�ĤG��loop�p�G�J�줣�P�r�����Y�q��break�A

vector���u���@�Ӧr��A���ĤG��loop�A���|�i�J�C
����Ĥ@��loop�]���A�Ǧ^�`���סC
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