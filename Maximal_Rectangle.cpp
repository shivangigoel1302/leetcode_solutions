class Solution {
public:
    int getArea(vector<int>v){
        vector<int>left;
        vector<int>right;
        stack<int>s;
        for(int i = 0 ; i < v.size(); i++){
            while(!s.empty() && v[s.top()] >= v[i]){
                s.pop();
            }
            if(s.empty()){
                left.push_back(-1);
            }
            else{
                left.push_back(s.top());
            }
            s.push(i);
        }
        // for(int i = 0 ; i < left.size(); i++){
        //     cout<<left[i]<<" ";
        // }
        while(!s.empty()) s.pop();
          for(int i = v.size()-1 ; i >=0; i--){
            while(!s.empty() && v[s.top()] >= v[i]){
                s.pop();
            }
            if(s.empty()){
                right.push_back(v.size());
            }
            else{
                right.push_back(s.top());
            }
            s.push(i);
        }

        int maxarea = 0;
        for(int i = 0 ; i< v.size(); i++){
            int x = left[i];
            int y = right[v.size()-1-i];
            int base = y - x - 1;
            int area = v[i]*base;

            maxarea = max(area,maxarea);
        }

        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        for(int i = matrix.size()-1; i >=0 ; i--){
            vector<int>v;
            for(int j = 0 ; j < matrix[i].size(); j++){
                int count = 0;
                int k = i;

                while(k >=0 && matrix[k][j] == '1'){

                    count++;
                    k--;
                }

                v.push_back(count);
            }
            int rect = getArea(v);
            ans = max(ans,rect);
        }
        return ans;
    }
};
