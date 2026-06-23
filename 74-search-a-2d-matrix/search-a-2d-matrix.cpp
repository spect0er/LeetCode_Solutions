class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size() - 1;
        while(top <= bottom){
            int mid = (top + bottom) / 2;
            if(matrix[mid][0] <= target and matrix[mid][matrix[0].size() - 1] >= target){
                int left = 0, right = matrix[0].size() - 1;
                while(left <= right){
                    int m = (left + right) / 2;
                    if(matrix[mid][m] == target) return true;
                    else if(matrix[mid][m] > target) right = m - 1;
                    else left = m + 1;
                }
                return false;
            }else if(matrix[mid][0] > target){
                bottom = mid - 1;
            }else{
                top = mid + 1;
            }
        }
        return false;
    }
};