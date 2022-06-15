/******************************************************************
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Permutation.
Memory Usage: 12 MB, less than 74.78% of C++ online submissions for Next Permutation.
Next challenges:

���@�ӼƦC�A��X�ƧǤU�@�j���Ʀr�A 

1.������1�ӭn�洫���ơA
�S�ʬ��q�̫�@�ӼƩ��e��A�Ĥ@���ܤp��  eg.123"6"976654 ����6


2.�A����2�ӭn�洫���ơA�q6�����A�Ҧ���6�j���Ʀr���̤p�� eg.123_6_9"7"6654 ����7

3.�洫 eg.123_6_9_7_6654 -> eg.123_7_9_6_6654

4.�洫�᪺�s�ƦC�A�n�Ʀ��̪��A�N�O7�����������eg.1237_966654 -> 1237456669

5.�� 1236976654 �j���Ҧ��Ʀr���̤p��(�]�N�O�ƧǪ��U�@��)1237456669

6.�Ʀr�v�O�̤j�ƧǪ��ܡA�ܦ��̤p��

*************�@*****************************************************/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size() <= 1 ) return ;
        
        int left = nums.size() - 1; 

        while( left > 0) //���ݶ}�l��Ĥ@���ܤp���Ʀr
        {
            if(nums[left] > nums[left-1])
            {
                left-- ;
                break;
            }
            
            left--;
         }

        
        int right = left + 1; //left������Ҧ��j��left���A�̤p���Ʀr
        while( right < nums.size())
        {  
            if(nums[right] <= nums[left])//���Ĥ@�Ӥpor���󪺼Ʀr�Nbreak�A����洫�S�N�q
            {

                break ;
            }
            
            right++;
        }
        
        swap(nums ,left, --right) ;//�]��right�O�Ĥ@�Ӥpor���󪺡A�ζ]�쩳���ҥH���e�h�@��

        
        if(left == right) //�ƦC�v�g�O�̤j���F�A������������(�ܦ��̤p���Ƨ�)
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