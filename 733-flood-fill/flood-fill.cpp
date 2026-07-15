class Solution {
public:
    void helper(int row,int col, int color, int orgColor, vector<vector<int>>&image){
        if(row < 0 || row >= image.size() ||  col < 0 || col >= image[0].size()){
            return;
        }
        if(image[row][col] == color) return;
        if(image[row][col] == orgColor){
            image[row][col] = color;
        }else{
            return;
        }
        helper(row,col-1,color,orgColor,image);
        helper(row,col+1,color,orgColor,image);
        helper(row-1,col,color,orgColor,image);
        helper(row+1,col,color,orgColor,image); 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        helper(sr,sc,color,orgColor,image);
        return image;
    }
};