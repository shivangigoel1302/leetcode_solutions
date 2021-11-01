bool compare(vector<int>&v1,vector<int>&v2){
    return v1[1] > v2[1];
}
class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n=rooms.size();
        int m=queries.size();
        for(int i=0;i<m;i++)
        {
            queries[i].push_back(i);
        }
        sort(rooms.begin(),rooms.end(),compare);
        sort(queries.begin(),queries.end(),compare);
        vector<int>ans(m,-1);
        int j=0;
        set<int>s;
        // for(auto &q:queries)
        //     cout<<q[0]<<" "<<q[1]<<" "<<q[2]<<endl;

        for(auto &q:queries){
            while(j<n && q[1]<=rooms[j][1]){
                s.insert(rooms[j][0]);
                j++;
            }
            if(s.empty())
                continue;
            // cout<<q[1]<<" "<<s.size()<<endl;
            auto it=s.lower_bound(q[0]);
           if(it==s.end()){
               ans[q[2]]=*prev(it);
           }
            else if(it==s.begin()){
                ans[q[2]]=*it;
            }
            else{
                int h=*it;
                int g=*prev(it);
                if(abs(g-q[0])<=abs(h-q[0]))
                    ans[q[2]]=g;
                else
                    ans[q[2]]=h;
            }
        }
        return ans;
    }
};
