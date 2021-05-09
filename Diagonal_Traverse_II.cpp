class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({-1,-1});
        vector<int>ans;
        int m = nums.size();
        bool down = true;
        while(!q.empty()){
            auto p = q.front();
            if(p.first == -1){
                q.pop();
                down = true;
                if(!q.empty()){
                    q.push({-1,-1});
                }
            }
            else{
                ans.push_back(nums[p.first][p.second]);
                q.pop();
                if(down == true){
                    if(p.first+1 < m && p.second < nums[p.first+1].size()){
                        q.push({p.first+1,p.second});
                    }
                    if(p.second+1 < nums[p.first].size()){
                        q.push({p.first,p.second+1});
                    }
                    down = false;
                }
                else{
                    if(p.second+1 < nums[p.first].size()){
                        q.push({p.first,p.second+1});
                    }
                }
            }
        }
        return ans;
    }
};
