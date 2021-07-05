/***********************************************************************************
用Recursive
將字串digits 切出 第一個字及後續的字組 (substr(0,1) 及 substr(1,length-1))


Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.4 MB, less than 96.65% of C++ online submissions for Letter Combinations of a Phone Number.
***********************************************************************************/

class Solution {
    
    vector<string> button = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> s ;
        
        s = Translation(digits) ;
        
        return s ;
    }

private:
    vector<string> Translation(string s )
    {
        
        vector<string> s1 = {}; 
        
        if(s.size() == 1) 
        {
            int num = stoi(s.substr(0,1));          
            for(int i = 0 ; i < button[num].size() ; i++)
            {
                s1.push_back(button[num].substr(i,1)); 
            }
        }
        else if(s.size() > 1)      
        {   
            vector<string> s2 = {};
            s2 = Translation(s.substr(1,s.size() - 1));
            
            int num = stoi(s.substr(0,1));          
            for(int i = 0 ; i < button[num].size() ; i++)
            {
                for(int j = 0 ; j < s2.size() ; j++)
                {
                    s1.push_back(button[num].substr(i,1) + s2[j]); 
                }
            }
        }

        return s1 ;
    }
        
};