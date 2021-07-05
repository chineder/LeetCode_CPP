/***********************************************************************************
以第一個值為基準，後面兩位做 2 sum 的調整

類似leetcode 11，取最大容積的做法，改成指定容積的概念
sort後，first先為基準，且first一定 <= 0，才有辦法三數相加為0
second 跟third ，分別從first的下一位跟最尾，往內夾，找答案

first若出現重複，則跳過，因為重復出現的數找到的答案，必包含放第一次出現
second 跟 third 一樣的概念

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