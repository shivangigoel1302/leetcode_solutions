class Solution {
public:
    void fillcolor(vector<vector<int>> &image,int i,int j, int n,int o){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != o){
            return;
        }
        image[i][j] = n;
        fillcolor(image,i+1,j,n,o);
        fillcolor(image,i-1,j,n,o);
        fillcolor(image,i,j+1,n,o);
        fillcolor(image,i,j-1,n,o);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor){
            return image;
        }
        fillcolor(image,sr,sc,newColor,oldColor);
        return image;
    }
};
