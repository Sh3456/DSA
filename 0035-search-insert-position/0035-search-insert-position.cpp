class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int left=0;
        int right=arr.size()-1;
        int mid=left+(right-left)/2;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid]==target){
                return mid;
            }else if(arr[mid]>target){
                 right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};