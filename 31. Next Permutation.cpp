/******************************************************************
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Permutation.
Memory Usage: 12 MB, less than 74.78% of C++ online submissions for Next Permutation.
Next challenges:

倒计т逼计 

1.т材1璶ユ传计
疭┦眖程计┕玡т材跑  eg.123"6"976654 い6


2.т材2璶ユ传计眖6┕т┮Τゑ6计い程 eg.123_6_9"7"6654 い7

3.ユ传 eg.123_6_9_7_6654 -> eg.123_7_9_6_6654

4.ユ传穝计璶逼Θ程碞琌7ぇ场は锣eg.1237_966654 -> 1237456669

5.ゑ 1236976654 ┮Τ计い程(碞琌逼)1237456669

6.计琌程逼杠跑Θ程

******************************************************************/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size() <= 1 ) return ;
        
        int left = nums.size() - 1; 

        while( left > 0) //Ю狠秨﹍т材跑计
        {
            if(nums[left] > nums[left-1])
            {
                left-- ;
                break;
            }
            
            left--;
         }

        
        int right = left + 1; //left┕т┮Τleftい程计
        while( right < nums.size())
        {  
            if(nums[right] <= nums[left])//т材or单计碞break单ユ传⊿種竡
            {

                break ;
            }
            
            right++;
        }
        
        swap(nums ,left, --right) ;//right琌材or单┪禲┏┮┕玡癶

        
        if(left == right) //计竒琌程钡场は锣(跑Θ程逼)
        {
            Allreverse( nums , left  , nums.size() - 1 );
        }
        
        else if(left + 1 < nums.size() - 1)
        {
            Allreverse(nums , left + 1  , nums.size() - 1 );
        }    
    }
            
private:
    void Allreverse(vector<int>& nums , int start, int end )
    {
        while(start < end)
        {
            swap(nums, start, end) ;
            start++;
            end--;
        }
    }
    
    void swap(vector<int>& nums , int left, int right)
    {
        if(left != right)
        {
            int temp ;
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp ;
        }
    }
    
};