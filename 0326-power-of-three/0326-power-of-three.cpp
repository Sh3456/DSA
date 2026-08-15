class Solution {
public:
    bool isPowerOfThree(int n) {
        bool ans = false;

        if(n <= 0) {
            return ans;
        }

        while(n%3==0){
            n=n/3;
        }

        return n==1;
    }
};