/************************************************************************************
�q�̨���}�l�A
�����C�A���䩹���Y�@��A
�k���C�A�k�䩹���Y�@��A
����@�˰��A����P���Y�@��A

�ˤ�������A�@�w�O�ݧC�����䰪�׬��D�C
�ҥH����C��������ݬݦ��S���󰪪��A���M�e�׷|�ܤp�A�ҥH�n�A��e�q

����@�˰��A�u���䤤�@�䩹�����󰪪����A
���C�䪺���פ@�˨S�ܡA�]���e�׷|�ܤp�A�ҥH�e�q�@�w��p�C
�]���A�@�_������ݬݦ��S����h�q
************************************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        vector<int>::iterator head_it = height.begin(); 
        vector<int>::iterator tail_it = --height.end(); 

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