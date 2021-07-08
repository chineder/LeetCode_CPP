/**************************************************************************************
1.用Dynamic programming, 
2. "*" 三種情況要特別處理
    a.往前一格比對相符 
    b.往前一格是"."
    c."*"當做zero次，清空，往前兩格參照，跳過"*"及其前一字元 e.g. mis* v.s. mi == true
3. vector 是 (s.length() + 1 * p.length() + 1) 的二維陣列 ==> +1 是多一個 0 的空集
   而S ,  P 的vector 編號是 (0 ~ length - 1), debug 注意對照會差1 
   vector[0][0] 是空， vector[1][1]是第一個字 s[0]跟p[0] 相比

Runtime: 4 ms, faster than 84.41% of C++ online submissions for Regular Expression Matching.
Memory Usage: 6.8 MB, less than 64.41% of C++ online submissions for Regular Expression Matching.
**************************************************************************************/
class Solution {
public:
    bool isMatch(string s, string p) {
        
        vector<vector<bool>> re(s.length() + 1, vector<bool>(p.length() + 1, false));    
        
        re[0][0] = true ;
        
        // .*.*.*.*  , a*b*c*d*,  a*.*b*.*,  各種間格* 是符合空字串的       
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
                    //a.往前一格比對相符  b.往前一格是"." 
                    if((s[i - 1] == p[j - 1 - 1]  or  p[j - 1 - 1] == '.')) 
                    {
                        re[i][j] =  re[i - 1][j];
                    }
                    //c."*"當做zero次，清空，往前兩格參照，跳過"*"及其前一字元 e.g. mis* v.s. mi == true
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