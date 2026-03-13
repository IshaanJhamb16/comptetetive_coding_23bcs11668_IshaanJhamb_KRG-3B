class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        while(l<h){
            int mid = (l+h)/2;
            int op =0;
            for(int i=0;i<nums.size();i++){
               op += (nums[i]-1)/mid;
            }
            if(op<=maxOperations){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};