class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>ans(n,-1);
        stack<int>st;
        unordered_map<int,int>mpp;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(nums2[i]);
        mpp[nums2[i]]=ans[i];
    }
    vector<int>result;
        for(int x:nums1){
            result.push_back(mpp[x]);
    }

    return result;
    }
};