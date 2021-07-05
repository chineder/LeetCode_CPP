/**************************************************************
利用stack 的概念，暫存在s1
只要出現, ')','}',']',這三種符號，s1 pop 出最後一個字元並比對，

比對失敗，就是false，

其它符號就一直加入s1尾端，

最後s1必需清空，否則false
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