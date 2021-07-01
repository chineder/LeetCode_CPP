class Solution {
public:
    int myAtoi(string s) {

        bool isSign = false; //�קK�X�{�s��Φh�����t���γ�W���t���S����ۼƦr
        bool isPositive = true;
        bool havefindnum = false;//�v�g�X�{�D0���Ʀr
        int space_count = 0 ;
        
        int i = 0 , start = -1, end = -1;
        for( ; i < s.size() ; i++)
        {
            if(havefindnum)
            {
                if(!isdigit(s[i])) break ; 
            }
            else if(isdigit(s[i]))
            {
                {
                    havefindnum = true ;
                    start = i ;
                }
            }
            else if(s[i] == ' ')      
            {
                if(isSign) break ;
                space_count++ ;
            }
            else if( s[i] == '+') 
            {
                if(isSign) break ;
                isSign = true ;
            }
            else if( s[i] == '-') 
            {
                if(isSign) break ;
                isSign = true ;
                isPositive = false ;
            }
            else break;
        }
        end = i - 1 ;

        
        //�S�����D�s���Ʀr
        if(!havefindnum) return 0 ;

        
        //�קK�X�{�@��ťդ�ӨS����ۼƦr   
        if( space_count == i ) return 0 ;

        
        //�קK�X�{�s�򥿭t��
        if( s[i-1] == '+' || s[i-1] == '-' ) return 0 ; //

        long num = 0;
        if(isPositive)
        {
            for(int k = 0 ; k < end - start + 1 ; k++)
            {
                num = num * 10 + stoi(s.substr(start + k , 1)) ;  
                if(num >= INT_MAX) return INT_MAX;

            }
            return num ;
        }
        else
        {

            for(int k = 0 ; k < end - start + 1 ; k++)
            {
                num = num * 10 - stoi(s.substr(start + k , 1)) ;
                if(num <= INT_MIN) return INT_MIN;
            }
            return num ;
        }

    }
};
