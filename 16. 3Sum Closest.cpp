/***********************************************************************************
同leetcode 15 解法，
並紀錄下與taget的差，最後做回來。
中間找到解等於target 直接return 


以第一個值為基準，後面兩位做 2 sum 的調整，

類似leetcode 11，取最大容積的做法，改成指定容積的概念
sort後，first先為基準，且first一定 <= 0，才有辦法三數相加為0
second 跟third 從first的下一位跟最尾，往內夾，找答案

first若出現重複，則跳過，因為重復出現的數找到的答案，必包含放第一次出現
second 跟 third 一樣的概念


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



