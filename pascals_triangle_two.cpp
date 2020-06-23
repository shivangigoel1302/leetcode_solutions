class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>>ans;
        vector<int>v;
        if(rowIndex==0)
        {
            v.push_back(1);
            return v;
        }
        v.push_back(1);
        ans.push_back(v);
        v.erase(v.begin(),v.end());
        for(int i=2;i<=rowIndex+1;i++)
        {
            v.push_back(1);
            for(int j=0;j<ans[i-2].size()-1;j++)
            {
                int x=ans[i-2][j]+ans[i-2][j+1];
                v.push_back(x);
            }
            v.push_back(1);
            ans.push_back(v);
            if(i==rowIndex+1)
            {
                return v;
            }
            v.erase(v.begin(),v.end());
        }
        return v;
    }
};
