/****************************************************************
Runtime: 4 ms, faster than 46.97% of C++ online submissions for Divide Two Integers.
Memory Usage: 6 MB, less than 28.42% of C++ online submissions for Divide Two Integers.

1. ��long long int �H�Koverflow 
2. quotient = quotient + (1LL << i);   1LL  long long int �~���|voerflow
3.������loop����k�|Time Limit Exceeded�A�ҥH�Φ줸�B������

�Φ첾�B��
�C�������@������2���A

1.if dividend > divisor��2^n���A� divisor��2�� n ���� 
2.if dividend > divisor��2^(n - 1)���A� divisor��2�� n - 1 ����
3.if dividend > divisor��2^(n - 2)���A� divisor��2�� n - 2 ����
4.if dividend > divisor��2^(n - 3)���A� divisor��2�� n - 3 ����
�H�������A�P�ɱN�������Ƭۥ[�APS: N = 31 int���줸�ơA

e.g  10 / 3
10 < 3*(2^2) ���ʧ@

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