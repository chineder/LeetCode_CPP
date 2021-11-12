/**************************************************************************
Runtime: 8 ms, faster than 91.23% of C++ online submissions for Remove Duplicates from Sorted Array.
Memory Usage: 18.3 MB, less than 93.35% of C++ online submissions for Remove Duplicates from Sorted Array.

counter 用來紀錄重現不同數字的個數

因為sotred，從nums.at(1)的位置開始，當nums.at(i) != nums.at(i - 1)
counter++，紀錄出現幾個不同的數字，

如果counter != at(i)，才表示前面己經有重復的，這時才需要做取代的動作。
e.g. 1,2,4,6,7,8,9,9,9,9,10 
     當 i == 5的位置，這時cunter == 5，前五個數值都不重復，所以不需取代，
     直拉再往下走訪
     
     當 i == 11 的位置，這時cunter == 8，at(11)數值10，放入第at(8)位置

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