/************************************************************************
Recusiven�ѡG

�Y�ѳ̫�@�Ӥ����ɡGreturn ")" �A�]���X�k�r�ճ̫�@�w�O")" 

�Y���O�̫�@�Ӧr���ɡG�r��A� "(" + �Ѿl�զX or ")"+�Ѿl�զX

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

        
        if(m == 0 and n == 1) //�X�ƪ��r��A�̫�@�w�Ѥ@�� ")"
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