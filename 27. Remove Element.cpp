/*************************************************************************
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
Memory Usage: 8.7 MB, less than 72.15% of C++ online submissions for Remove Element.

start�q0����m�}�l���Ĥ@��<����>val�Ȫ���m�A�е��X��

end�q�̧���(size()-1)�}�l���Ĥ@��<������>val�Ȫ���m�A


**************
�p�Gstart��m��end�٫e�ݡA���N�Nend��m��val���Nstart��m�����ȡA
�U�۩��U�@���ڶi�C

�p�Gstart��m���n�Oend��m�A���N��إi��
1.�Ӧ쥿�Oval�ȡA���������p�A���^��start����
2.�Ӧ줣�Oval�ȡA���Ӧ�m�]�n�p��A�^��start+1���� (index ����ӼơA�]��index���O�q0�}�l)
loop break

�p�Gstart��m��end�ٱq�ݡA�ܩ�����X�����F�A����loop break

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