/****************************************************************
Runtime: 4 ms, faster than 46.97% of C++ online submissions for Divide Two Integers.
Memory Usage: 6 MB, less than 28.42% of C++ online submissions for Divide Two Integers.

1. 用long long int 以免overflow 
2. quotient = quotient + (1LL << i);   1LL  long long int 才不會voerflow
3.直接用loop做減法會Time Limit Exceeded，所以用位元運算比較快

用位移運算
每往左移一格表示變2倍，

1.if dividend > divisor的2^n倍，減掉 divisor的2的 n 次方 
2.if dividend > divisor的2^(n - 1)倍，減掉 divisor的2的 n - 1 次方
3.if dividend > divisor的2^(n - 2)倍，減掉 divisor的2的 n - 2 次方
4.if dividend > divisor的2^(n - 3)倍，減掉 divisor的2的 n - 3 次方
以此類推，同時將有減掉的位數相加，PS: N = 31 int的位元數，

e.g  10 / 3
10 < 3*(2^2) 不動作

10 > 3*(2^1) 
10 - 3*2 = 4

4 > 3*(2^0)
4 - 3*1 = 1

(2^1) + (2^0) = 3

****************************************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
       
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX ;
        if(divisor == 1 ) return dividend ;

        long long int quotient = 0;
        
        long long int Ldividend , Ldivisor ;
        bool Positivesign = true ;
        
        if(dividend < 0)
        {
            Ldividend = 0 - (long long int)dividend ;
            Positivesign = !Positivesign ;
        }
        else Ldividend = dividend ;

        if(divisor < 0)
        {
            Ldivisor = 0 - (long long int)divisor ;
            Positivesign = !Positivesign ;
        }
        else Ldivisor = divisor ;

        for(int i = 31 ; i >= 0 ; i--)
        {
            if(Ldivisor << i <= Ldividend)   
            {   
                Ldividend = Ldividend - (Ldivisor << i) ;
                quotient = quotient + (1LL << i);
            }
        }

        if(Positivesign) return quotient ;
        else return 0 - quotient ;
    }
};