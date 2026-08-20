class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int n = image.size();
        int m = image[0].size();

        // Reverse every row
        for(int i = 0; i < n; i++) {
            int left = 0;
            int right = m - 1;

            while(left < right) {
                swap(image[i][left], image[i][right]);
                left++;
                right--;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(image[i][j] == 0) {
                    image[i][j] = 1;
                }
                else {
                    image[i][j] = 0;
                }
            }
        }

        return image;
    }
};