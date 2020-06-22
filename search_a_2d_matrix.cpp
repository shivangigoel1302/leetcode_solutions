class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        if(matrix.size()==0||matrix[0].size()==0)
        {
            return false;
        }
        while(i<matrix.size()&& target>matrix[i][matrix[0].size()-1])
        {
            i++;
        }
        int j=0;
        while(j<matrix[0].size()&&target>matrix[matrix.size()-1][j])
        {
            j++;
        }
        int l=j;
        int r=matrix[0].size()-1;

        while(l<=r)
        {
            int mid=(l+r)/2;
            if(matrix[i][mid]<target)
            {
                l=mid+1;
            }
            else if(matrix[i][mid]>target)
            {
                r=mid-1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
