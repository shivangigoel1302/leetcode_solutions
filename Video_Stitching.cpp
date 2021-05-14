class Solution {
public:
    int helper(int i,int j, vector<bool>visited,vector<vector<int>>clips,int T){
        if(j >= T){
            return 0;
        }
        int count = 0;
        int maximum = j;
        int index = -1;
        for(int k = 0 ; k < clips.size(); k++){
            if(!visited[k]){
                if(clips[k][0] >=i && clips[k][0] <= j){
                    if(clips[k][1] > maximum){
                        maximum = clips[k][1];
                        index = k;
                    }
                }
            }
        }
        if(index == -1){
            return -1;
        }
        visited[index] = true;
        int temp = helper(clips[index][0],clips[index][1],visited,clips,T);
        if(temp == -1){
            return -1;
        }
        count += temp + 1;
        return count;
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        vector<bool>visited(n,false);

        return helper(0,0,visited,clips,T);
    }
};
