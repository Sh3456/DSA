class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while(left <= right) {

            int mid = left + (right - left) / 2;

            int sum = 0;
            int daysUsed = 1;

            for(int i : weights) {

                if(sum + i <= mid) {
                    sum += i;
                }
                else {
                    daysUsed++;
                    sum = i;
                }
            }

            if(daysUsed > days) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};