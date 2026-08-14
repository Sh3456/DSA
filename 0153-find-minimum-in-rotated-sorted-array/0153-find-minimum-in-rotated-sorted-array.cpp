class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int mid=left+(right-left)/2;
        int mini=INT_MAX;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[left]<=nums[mid]){
              mini=min(mini,nums[left]);
                left=mid+1;
            }
        else{
            mini=min(mini,nums[mid]);
            right=mid-1;
        }
        }
            
        
        return mini;
    }
};