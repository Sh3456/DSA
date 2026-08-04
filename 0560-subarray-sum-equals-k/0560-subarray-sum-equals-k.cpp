class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix;
        int ans = 0;
        int count = 0;

    
        for(int i = 0; i < nums.size(); i++) {
            ans += nums[i];
            prefix.push_back(ans);
        }

        for(int i = 0; i < prefix.size(); i++) {
            if(prefix[i] == k) {
                count++;
            }
        }

        for(int i = 0; i < prefix.size(); i++) {
            for(int j = i + 1; j < prefix.size(); j++) {
                if(prefix[j] - prefix[i] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};