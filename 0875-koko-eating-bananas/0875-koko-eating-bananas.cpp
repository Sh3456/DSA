class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int maxPile = INT_MIN;

        for (int i : piles) {
            if (maxPile < i) {
                maxPile = i;
            }
        }

        int right = maxPile;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;

            for (int i : piles) {
                hours += (i + mid - 1LL) / mid;
            }

            if (hours <= h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
