class Solution {
public:
    int finddiff(string s1,string s2){
        string h1 = s1.substr(0,2);
        string h2 = s2.substr(0,2);
        string m1 = s1.substr(3);
        string m2 = s2.substr(3);
        if(h1 == "00" && h2 > "12"){
            h1 = "24";
        }
        if(h2 == "00" && h1 > "12"){
            h2 = "24";
        }
        int hdiff = 0;
        int mdiff = 0;
        if(h1 > h2){
            mdiff += 60 - stoi(m2);
            hdiff += stoi(h1) - stoi(h2) - 1;
            mdiff += stoi(m1);
        }
        else if(h1 < h2){
            mdiff += 60 - stoi(m1);
            hdiff += stoi(h2) - stoi(h1) - 1;
            mdiff += stoi(m2);
        }
        else{
            mdiff += abs(stoi(m1) - stoi(m2));
        }

        return min(mdiff+hdiff*60,1440 - mdiff - hdiff*60);
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int n = timePoints.size();
        int diff = INT_MAX;
        for(int i = 0; i < timePoints.size()-1; i++){
            diff = min(diff,finddiff(timePoints[i],timePoints[i+1]));
        }
        diff = min(diff,finddiff(timePoints[0],timePoints[n-1]));
        return diff;
    }
};
