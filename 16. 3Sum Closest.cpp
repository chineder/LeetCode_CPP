/***********************************************************************************
�Pleetcode 15 �Ѫk�A
�ì����U�Ptaget���t�A�̫ᰵ�^�ӡC
�������ѵ���target ����return 


�H�Ĥ@�ӭȬ���ǡA�᭱��찵 2 sum ���վ�A

����leetcode 11�A���̤j�e�n�����k�A�令���w�e�n������
sort��Afirst������ǡA�Bfirst�@�w <= 0�A�~����k�T�Ƭۥ[��0
second ��third �qfirst���U�@���̧��A�������A�䵪��

first�Y�X�{���ơA�h���L�A�]�����_�X�{���Ƨ�쪺���סA���]�t��Ĥ@���X�{
second �� third �@�˪�����


Runtime: 8 ms, faster than 82.47% of C++ online submissions for 3Sum Closest.
Memory Usage: 9.8 MB, less than 58.52% of C++ online submissions for 3Sum Closest.
***********************************************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        vector<int>::iterator head_it = nums.begin(); 
        vector<int>::iterator tail_it = nums.end() - 1; 
        
        std::sort(nums.begin(), nums.end());

        int tmpsum = 0;
        int difference = INT_MAX ;
        
        for(int i = 0 ; i < nums.size() - 2 ; i++)
        {                                       
            if( i > 0 && nums[i] == nums[i-1]) continue ;

            head_it = nums.begin() + 1 + i; 
            tail_it = nums.end() - 1;  
        
        
            while(head_it < tail_it)
            { 
                tmpsum = nums[i] + *head_it + *tail_it ;
                
                if( tmpsum == target)
                {       
                    return target;
                }
                
                else if( tmpsum > target)
                {   
                    difference = abs(difference) < abs(target - tmpsum) ? difference : (target - tmpsum) ;
                    do
                    {
                        tail_it--;
                    }while( head_it < tail_it && *tail_it == *(tail_it + 1));
                }
            
                else //if( tmpsum < target)
                {   
                    difference = abs(difference) < abs(target - tmpsum) ? difference : (target - tmpsum) ;
                    do
                    {
                        head_it++ ;
                    }while( head_it < tail_it && *head_it == *(head_it - 1)  );
                }
            }  
        }

        return target - difference ;
        
    }
};



