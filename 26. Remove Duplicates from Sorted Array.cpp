/**************************************************************************
Runtime: 8 ms, faster than 91.23% of C++ online submissions for Remove Duplicates from Sorted Array.
Memory Usage: 18.3 MB, less than 93.35% of C++ online submissions for Remove Duplicates from Sorted Array.

counter �ΨӬ������{���P�Ʀr���Ӽ�

�]��sotred�A�qnums.at(1)����m�}�l�A��nums.at(i) != nums.at(i - 1)
counter++�A�����X�{�X�Ӥ��P���Ʀr�A

�p�Gcounter != at(i)�A�~��ܫe���v�g�����_���A�o�ɤ~�ݭn�����N���ʧ@�C
e.g. 1,2,4,6,7,8,9,9,9,9,10 
     �� i == 5����m�A�o��cunter == 5�A�e���Ӽƭȳ������_�A�ҥH���ݨ��N�A
     ���ԦA���U���X
     
     �� i == 11 ����m�A�o��cunter == 8�Aat(11)�ƭ�10�A��J��at(8)��m

**************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() <= 0) return 0 ;
        
        int counter = 0 ;
        
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(nums.at(i) != nums.at(i - 1))
            {
                counter++;
                
                if(counter != i )
                {
                    nums.at(counter) = nums.at(i);
                }
            }
        }
        return counter + 1 ;
    }
};