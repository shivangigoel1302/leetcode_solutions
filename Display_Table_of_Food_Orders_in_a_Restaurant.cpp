
struct compare {
  bool operator() (string a, string b) const
  {
      if(a.size() > b.size()){
          return false;
      }
      else if(a.size() <b.size()){
          return true;
      }
    return a < b;
  }
};
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string>s1;
        set<string,compare>s2;
        map<string,int>m1;
        map<string,int>m2;
        vector<vector<string>>ans;
        for(int i = 0 ; i < orders.size(); i++){
            s1.insert(orders[i][2]);
            s2.insert(orders[i][1]);
        }
        int i = 1;
        ans.push_back({"Table"});
        for(auto food :s1){
            ans[0].push_back(food);
            m1[food] = i;
            i++;
        }
        i = 1;
        for(auto table:s2){
            ans.push_back({table});
            m2[table] = i;
            i++;
        }
        int a = ans[0].size();
        int b = ans.size();
        for(int i = 1; i < b; i++){
            for(int j = 1; j < a; j++){
                ans[i].push_back("0");
            }
        }
        for(int i = 0 ; i < orders.size(); i++){
            int r = m2[orders[i][1]];
            int c = m1[orders[i][2]];
            int curr = stoi(ans[r][c]);
            curr++;
            string n = "";
            n += (curr +'0');
            ans[r][c] =n;
        }
        return ans;
    }
};
