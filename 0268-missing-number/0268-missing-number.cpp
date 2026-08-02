class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
       int expected_sum=n*(n+1)/2;
       int actualsum=0;
       for(int i:nums){
        actualsum+=i;
       }
       return expected_sum-actualsum;
    }
};