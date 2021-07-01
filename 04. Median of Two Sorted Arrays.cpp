//using namespace std ;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        double mid = 0 ;
        int index = 0 ;
        
        vector<int>::iterator it_i;
        for(it_i = nums2.begin(); it_i!=nums2.end(); ++it_i) 
        {
            nums1.push_back(*it_i);
        }
    
        sort(nums1.begin(), nums1.end());
        index = nums1.size() / 2;
        
        if(nums1.size() % 2 != 0)
        {
            mid = nums1[nums1.size() / 2] ;           
        }
        else
        {
            mid = (nums1[nums1.size() / 2]  + nums1[nums1.size() / 2 - 1]) / 2.0 ;
        }
        
        return mid;
    }
    
};