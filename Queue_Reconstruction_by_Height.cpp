class Solution {
private:
bool static comp(vector<int> &v1,vector<int> &v2)
    {
        return v1[0] < v2[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int row = people.size();
        vector<vector<int>> q(row,{INT_MAX,0});
        sort(people.begin(),people.end(),comp);
        for(int i = 0; i < row; i++)
        {
            int f = 0;
            for(int j = 0; j < row; j++)
            {
                if(q[j][0] >= people[i][0] && f < people[i][1])
                    f++;
                else if(f == people[i][1] && q[j][0] == INT_MAX)
                {
                    q[j] = people[i];
                    break;
                }

            }
        }
        return q;
    }
};
