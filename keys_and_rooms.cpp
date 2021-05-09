class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int>s;
        vector<bool>visited(rooms.size(),false);
        for(int i = 0  ; i < rooms[0].size(); i++){
            s.push(rooms[0][i]);
            visited[rooms[0][i]] = true;
        }
        visited[0] = true;
        while(!s.empty()){
            int room = s.top();
            s.pop();
            for(int i = 0 ; i < rooms[room].size(); i++){
                if(!visited[rooms[room][i]]){
                    visited[rooms[room][i]] = true;
                    s.push(rooms[room][i]);
                }
            }
        }
        for(int i = 0 ; i < visited.size(); i++){
            if(!visited[i]){
               return false;
            }
        }
        return true;
    }
};
