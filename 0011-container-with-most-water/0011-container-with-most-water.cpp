class Solution {
public:
    int maxArea(vector<int>& height) {
        int j=height.size()-1;
        int i=0;
        int ans=0;
        while(i<j){
            int hei_ght=min(height[i],height[j]);
            int width=j-i;
            int product=hei_ght*width;
            ans=max(ans,product);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};