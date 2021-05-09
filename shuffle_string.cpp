class Solution {
public:
    string restoreString(string& s, vector<int>& indices) {
        string res="";
    int l = indices.size();
    char arr[l];
    for(int i=0;i<l;i++)
    {
      int c;
      c=indices[i];
      arr[c]=s[i];
    }
    for(int i=0;i<l;i++)
    {
      res= res + arr[i];
    }
    return res;
    }
};
