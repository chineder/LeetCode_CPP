/***********************************************************************************
�H�Ĥ@�ӭȬ���ǡA�᭱��찵 2 sum ���վ�

����leetcode 11�A���̤j�e�n�����k�A�令���w�e�n������
sort��Afirst������ǡA�Bfirst�@�w <= 0�A�~����k�T�Ƭۥ[��0
second ��third �A���O�qfirst���U�@���̧��A�������A�䵪��

first�Y�X�{���ơA�h���L�A�]�����_�X�{���Ƨ�쪺���סA���]�t��Ĥ@���X�{
second �� third �@�˪�����

Runtime: 48 ms, faster than 98.76% of C++ online submissions for 3Sum.
Memory Usage: 19.9 MB, less than 85.91% of C++ online submissions for 3Sum.
***********************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3) return {};
        
        vector<vector<int>> ans = {};
        vector<int>::iterator head_it = nums.begin(); 
        vector<int>::iterator tail_it = nums.end() - 1; 
        
        std::sort(nums.begin(), nums.end());

        
        for(int i = 0 ; i < nums.size() - 2 && nums[i] <= 0; i++)
        {                                       
            if( i > 0 && nums[i] == nums[i-1]) continue ;

            head_it = nums.begin() + 1 + i; 
            tail_it = nums.end() - 1;  
        
        
            while(head_it < tail_it)
            { 
                int tmpsum = nums[i] + *head_it + *tail_it ;
                
                if( tmpsum == 0)
                {       
                    ans.push_back({nums[i] , *head_it , *tail_it}) ;

                    do
                    {
                        tail_it--;
                    }while( head_it < tail_it && *tail_it == *(tail_it + 1));
                    
                    do
                    {
                        head_it++ ;
                    }while( head_it < tail_it && *head_it == *(head_it - 1)  );
                }
                
                else if( tmpsum > 0)
                {                        
                    do
                    {
                        tail_it--;
                    }while( head_it < tail_it && *tail_it == *(tail_it + 1));
                }
            
                else //if( tmpsum < 0)
                {     
                    do
                    {
                        head_it++ ;
                    }while( head_it < tail_it && *head_it == *(head_it - 1)  );
                }
            }  
        }
              
        return ans;
    }
};