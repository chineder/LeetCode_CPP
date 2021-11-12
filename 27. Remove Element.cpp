/*************************************************************************
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
Memory Usage: 8.7 MB, less than 72.15% of C++ online submissions for Remove Element.

start從0的位置開始找到第一個<等於>val值的位置，標註出來

end從最尾端(size()-1)開始找到第一個<不等於>val值的位置，


**************
如果start位置比end還前端，那就就end位置的val取代start位置內的值，
各自往下一格邁進。

如果start位置正好是end位置，那就兩種可能
1.該位正是val值，那忽略不計，直回傳start的值
2.該位不是val值，那該位置也要計算，回傳start+1的值 (index 換算個數，因為index都是從0開始)
loop break

如果start位置比end還從端，很明顯歷訪全部了，直接loop break

**************************************************************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if(nums.size()==0) return 0 ;
        //if(nums.size()==1 && nums.at(0) == val) return 0 ;
        
        int start = 0 , end = nums.size() - 1;
        
        while(1)
        {
            while(nums.at(start) != val && start < end )
            {
                start++ ;
            }
            
            while(nums.at(end) == val && end > start)
            {
                end--;
            }
            
            if(start < end)
            {
                nums.at(start) = nums.at(end) ;
                
                start++ ;
                end--; 
            }
            else if(start == end)
            {
                if(nums.at(start) != val) start++ ;                
                break ;
            }
            else 
            {             
                break;
            }

        }
        
        return start  ;
    }
};