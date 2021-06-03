class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>a;
        vector<int>b;
        int primary =0,secondary=0;
        vector<int>ans(seq.size());
        for(int i = 0; i < seq.size();i++){
            if(seq[i]=='('){
                  if(a.size() == 0|| primary < secondary){
                a.push_back(i);
                    primary++;
                }
                else{
                    b.push_back(i);
                    secondary++;
               }
            }
          else{
              if(secondary > primary){
                  b.push_back(i);
                  secondary--;
              }
              else{
                  a.push_back(i);
                  primary--;
              }
          }

        }
        for(auto i: a){
            ans[i] = 0;
        }
        for(auto i: b){
            ans[i] = 1;
        }
        return ans;
    }
};
