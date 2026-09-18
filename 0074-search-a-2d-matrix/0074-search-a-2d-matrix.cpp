class Solution {
public:

    bool searchinrow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();

        int start = 0;
        int end = n - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(mat[row][mid] == target) {
                return true;
            }
            else if(mat[row][mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int target) {

        if(mat.empty() || mat[0].empty()) {
            return false;
        }

        int m = mat.size();
        int n = mat[0].size();

        int startrow = 0;
        int endrow = m - 1;

        while(startrow <= endrow) {

            int midrow = startrow + (endrow - startrow) / 2;

            if(target >= mat[midrow][0] &&
               target <= mat[midrow][n-1]) {

                return searchinrow(mat, target, midrow);
            }

            else if(target > mat[midrow][n-1]) {
                startrow = midrow + 1;
            }

            else {
                endrow = midrow - 1;
            }
        }

        return false;
    }
};