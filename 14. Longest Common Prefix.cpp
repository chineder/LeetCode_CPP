/************************************************************************
以第一個字串為基準，一次一字元，與後面字的比較
第二個loop如果遇到不同字元的即通知break，

vector中只有一個字串，那第二個loop，不會進入。
等放第一個loop跑完，傳回總長度。

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