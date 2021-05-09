class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>q;
        for(auto vector:matrix)
        {
            for(auto i:vector)
            {
                if(q.size()<k)
                {
                    q.push(i);
                }
                else if(q.top()>i)
                {
                    q.pop();
                    q.push(i);
                }
            }
        }
        return q.top();
    }
};
