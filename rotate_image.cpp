class Solution {
public:
    void rotate(vector<vector<int>>&matrix) {
       int n=matrix.size();
        if(n%2!=0)
        {
          for(int i=0;i<n-1;i++)
        {
            for(int j=i;j<n-i-1;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(k==0)
                    {

                        swap(matrix[i][j],matrix[n-1-j][i]);

                    }
                    else if(k==1)
                    {

                        swap(matrix[n-1-j][i],matrix[n-i-1][n-1-j]);
                    }
                    else if(k==2)
                    {

                        swap(matrix[n-i-1][n-1-j],matrix[j][n-i-1]);
                    }
                }

            }

        }
        }
        else
        {
            for(int i=0;i<n-1;i++)
        {
            for(int j=i;j<n-1-i;j++)
            {
                if(j==(n/2)-1&&i==(n/2)-1)
                {
                    break;
                }
                for(int k=0;k<3;k++)
                {
                    if(k==0)
                    {

                        swap(matrix[i][j],matrix[n-1-j][i]);

                    }
                    else if(k==1)
                    {

                        swap(matrix[n-1-j][i],matrix[n-i-1][n-1-j]);
                    }
                    else if(k==2)
                    {

                        swap(matrix[n-i-1][n-1-j],matrix[j][n-i-1]);
                    }
                }

            }
        }
           int key=matrix[(n/2)-1][(n/2)-1];

            matrix[(n/2)-1][(n/2)-1]=matrix[n/2][(n/2)-1];
           matrix[(n/2)][(n/2)-1]=matrix[n/2][n/2];
            matrix[n/2][n/2]=matrix[(n/2)-1][(n/2)];
            matrix[(n/2)-1][(n/2)]=key;
        }

    }
};
