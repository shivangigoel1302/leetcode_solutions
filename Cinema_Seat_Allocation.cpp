class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
         unordered_map<int,string> row;
        for(const auto& i:reservedSeats) {
            if(!row.count(i[0])) row[i[0]]="0123456789";
            row[i[0]][i[1]-1]='X';
        }

        int count=(n-row.size())*2;

        for(const auto& i:row) {
            if(i.second.find("12345678")!=string::npos) ++++count;
            else if(i.second.find("1234")!=string::npos
                 or i.second.find("3456")!=string::npos
                 or i.second.find("5678")!=string::npos) ++count;
        }

        return count;
    }

};
