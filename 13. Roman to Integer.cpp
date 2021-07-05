/*************************************************************
Runtime: 8 ms, faster than 75.81% of C++ online submissions for Roman to Integer.
Memory Usage: 6 MB, less than 82.15% of C++ online submissions for Roman to Integer.
*************************************************************/

class Solution {
public:
    int romanToInt(string s) {
        
        int num = 0 ;
        int tmp = 0 ;
        
        //�e�@�쪺�Ʀr>=�᭱�@��ۥ[�A�e�@�쪺�Ʀr<�᭱�@��ۥ[�A
        //�@��������A�ҥH���˼ƲĤG�쬰��A
        //�̫�@��Ʀr���@�w�O�ۥ[�A�ӥB���L�S�����Ʀr��A�A��|out_of_range erroe
        while(s.size() >= 2)
        {
            if(symbolint(s.at(0)) >= symbolint(s.at(1))) num = num + symbolint(s.at(0));
            else num = num - symbolint(s.at(0));
            
            s.erase(0,1);
        }
        
        if(s.size() == 1)
        {
            num = num + symbolint(s.at(0));
        }            
        return num ;
    }
private:
    int symbolint(char c)
    {
        if(c == 'I') return 1 ;
        else if(c == 'V') return  5;
        else if(c == 'X') return  10;
        else if(c == 'L') return  50;
        else if(c == 'C') return  100;
        else if(c == 'D') return  500;
        else if(c == 'M') return  1000;
        else return 0 ;
    }  
};