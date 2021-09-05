class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.size() == 0 || rectangles[0].size() == 0){
            return false;
        }
        int x1 = INT_MAX;
        int x2 = INT_MIN;
        int y1 = INT_MAX;
        int y2 = INT_MIN;
        int area= 0;
        unordered_set<string>s;
        for(int i = 0; i < rectangles.size(); i++){
            x1 = min(rectangles[i][0],x1);
            x2 = max(rectangles[i][2],x2);
            y1 = min(rectangles[i][1],y1);
            y2 = max(rectangles[i][3],y2);
             area += (rectangles[i][0] - rectangles[i][2])*(rectangles[i][1] - rectangles[i][3]);
             string s1 = to_string(rectangles[i][0]) + " " + to_string(rectangles[i][1]);
             string s2 = to_string(rectangles[i][0]) + " " + to_string(rectangles[i][3]);
            string s3 = to_string(rectangles[i][2]) + " " + to_string(rectangles[i][1]);
            string s4 = to_string(rectangles[i][2]) + " " + to_string(rectangles[i][3]);
            if(s.find(s1) != s.end()){
                s.erase(s1);
            }
            else{
                s.insert(s1);
            }
            if(s.find(s2) != s.end()){
                s.erase(s2);
            }
            else{
                s.insert(s2);
            }
            if(s.find(s3) != s.end()){
                s.erase(s3);
            }
            else{
                s.insert(s3);
            }
            if(s.find(s4) != s.end()){
                s.erase(s4);
            }
            else{
                s.insert(s4);
            }
        }
        string s1 = to_string(x1) + " " + to_string(y1);
             string s2 = to_string(x1) + " " + to_string(y2);
            string s3 = to_string(x2) + " " + to_string(y1);
            string s4 = to_string(x2) + " " + to_string(y2);
        if(s.size() != 4 || s.find(s1) == s.end() || s.find(s2) == s.end() || s.find(s3) == s.end() || s.find(s4) == s.end()){
            return false;
        }
        return area == (x1-x2)*(y1-y2);
    }
};
