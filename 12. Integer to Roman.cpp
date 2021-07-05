/******************************************************************
Runtime: 4 ms, faster than 84.93% of C++ online submissions for Integer to Roman.
Memory Usage: 6 MB, less than 70.06% of C++ online submissions for Integer to Roman.
******************************************************************/

class Solution {
public:
    string intToRoman(int num) {
    
        string intRomanStr = "";
        
        /*******************************************************/
        for( ; num >= 1000 ; num = num - 1000)
        {
            intRomanStr.push_back('M');       
        }
        
        if(num >= 900)
        {  
            intRomanStr.push_back('C');
            intRomanStr.push_back('M');
            num = num - 900 ;
        }

        /*******************************************************/
        for( ; num >= 500 ; num = num - 500)
        {
            intRomanStr.push_back('D');       
        }
        
        if(num >= 400)
        {            
            intRomanStr.push_back('C');
            intRomanStr.push_back('D');
            num = num - 400 ;
        }
        
        /*******************************************************/
        for( ; num >= 100 ; num = num - 100)
        {
            intRomanStr.push_back('C');     
        }
        
        if(num >= 90)
        {            
            intRomanStr.push_back('X');
            intRomanStr.push_back('C');
            num = num - 90 ;
        }
        
        /*******************************************************/
        for( ; num >= 50 ; num = num - 50)
        {
            intRomanStr.push_back('L');       
        }
        
        if(num >= 40)
        {    
            intRomanStr.push_back('X');
            intRomanStr.push_back('L');
            num = num - 40 ;
        }
        
        /******************************************************/
        for( ; num >= 10 ; num = num - 10)
        {
            intRomanStr.push_back('X');        
        }
        
        if(num >= 9)
        {
            intRomanStr.push_back('I');
            intRomanStr.push_back('X');  
            num = num - 9 ;
        }
        
        /*******************************************************/
        for( ; num >= 5 ; num = num - 5)
        {
            intRomanStr.push_back('V');      
        }
        
        if(num >= 4)
        {                                       
            intRomanStr.push_back('I');
            intRomanStr.push_back('V');
            num = num - 4 ;
        }

        /*******************************************************/
        for( ; num >= 1 ; num--)
        {
            intRomanStr.push_back('I');             
        }
        
        return  intRomanStr ;
    }
};