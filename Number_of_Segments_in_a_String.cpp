class Solution {
public:
    int countSegments(string s) {
       stringstream str(s);
        string word;
        int c= 0;
        while(str >> word){
            c++;
        }
        return c;
    }
};
