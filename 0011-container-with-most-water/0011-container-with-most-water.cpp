class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int heightt=0;
        int width=0;
        int area=0;
        int area_max=0;
        while(i<j){
            heightt=min(height[i],height[j]);
            width=j-i;
            area=heightt*width;
            area_max=max(area_max,area);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return area_max;
    }
};