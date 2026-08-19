class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left=1;
        int right=10000000;
            if(hour<=dist.size()-1){
                return -1;
            }
                  int mid=left+(right-left)/2;
        while(left<=right){
          int mid=left+(right-left)/2;
                double hours=0;
               for(int i=0;i<dist.size()-1;i++){
                   hours += (dist[i] + mid - 1) / mid;
                }
                hours+=(double)dist.back()/mid;
                if(hours<=hour){
                     right=mid-1;
                }
                else{
                    left=mid+1;
                }
        }
               
               return left;

        }
    
};