/************************************************************************
Recusiven解：

若剩最後一個元元時：return ")" ，因為合法字組最後一定是")" 

若不是最後一個字元時：字串，拆成 "(" + 剩餘組合 or ")"+剩餘組合

Runtime: 12 ms, faster than 14.60% of C++ online submissions for Generate Parentheses.
Memory Usage: 23 MB, less than 7.70% of C++ online submissions for Generate Parentheses.
************************************************************************/

class Solution {
public:
        
    vector<string> generateParenthesis(int n) {

       return generate(n,n) ;       
    }
    
private:    
    vector<string> generate(int m, int n) //m: "(" Quantity', n:")"Quantity
    {
        vector<string> s1 ;
        vector<string> s2 = {""};

        
        if(m == 0 and n == 1) //合化的字串，最後一定剩一個 ")"
        {
            return {")"};
        }
        
        if(m >= 1)
        {
            s2 = generate(m - 1, n) ;  

            for(int i = 0 ; i < s2.size() ; i++)
            {
                s1.push_back("(" + s2[i]);
            }
        }
        
        if(n > m) //because m minmum is 0, so, n >= 0
        {
            s2 = generate(m ,n - 1) ;  //cout << s2.size() << endl ;

            for(int i = 0 ; i < s2.size() ; i++)
            {
                s1.push_back(")" + s2[i]);
            } 
        }
        
        return s1 ;
    } 
};