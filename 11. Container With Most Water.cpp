/************************************************************************************
從最兩邊開始，
左邊比低，左邊往內縮一格，
右邊比低，右邊往內縮一格，
兩邊一樣高，兩邊同時縮一格，

裝水的兩邊，一定是看低的那邊高度為主。
所以比較低的往內找看看有沒有更高的，當然寬度會變小，所以要再比容量

兩邊一樣高，只有其中一邊往內找到更高的的，
較低邊的高度一樣沒變，因為寬度會變小，所以容量一定更小。
因此，一起往內找看看有沒有更多量
************************************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        vector<int>::iterator head_it = height.begin(); 
        vector<int>::iterator tail_it = height.end() - 1; 

        int Mostcon = 0;
        int tmpcon = 0;

        while(head_it < tail_it)
        {
      
            if(*head_it > *tail_it)
            {                  
                tmpcon = std::min(*head_it, *tail_it) * (tail_it - head_it);               
                tail_it--;
            }
            
            else if(*head_it < *tail_it)
            {               
                tmpcon = std::min(*head_it, *tail_it) * (tail_it - head_it);
                head_it++ ;
            }
            
            else if(*head_it == *tail_it)
            {               
                tmpcon = std::min(*head_it, *tail_it) * (tail_it - head_it);
                head_it++ ;
                tail_it-- ;
            }

            
            if(tmpcon > Mostcon)
            {
                Mostcon = tmpcon ;
            }
        }
        
        return Mostcon ;
    }
};