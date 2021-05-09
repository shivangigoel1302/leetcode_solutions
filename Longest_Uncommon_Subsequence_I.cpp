class Solution {
public:
    int findLUSlength(string a, string b) {
          if(a.size() == b.size()){
              int i = 0;
              while(i < a.size()){
                  if(a[i] != b[i]){
                      break;
                  }
                  i++;
              }
              if(i == a.size()){
                  return -1;
              }
              return a.size();
          }
        return max(a.size(), b.size());
    }
};
