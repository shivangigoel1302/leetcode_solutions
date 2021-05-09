class Solution {
public:
    bool checkequal(int i1, int j1,int i2,int j2,vector<int>arr){
        int x = i1;
        int y = i2;
        while(x <= j1 && y <= j2){
            if(arr[x] != arr[y]){
                return false;
            }
            x++;
            y++;
        }
        if(x != j1+1 || y != j2+1){
            return false;
        }
        return true;
    }
    vector<int> threeEqualParts(vector<int>& arr) {
        int totalones = 0;
        for(auto i : arr){
            totalones+=i;
        }
        if(totalones == 0){
            return {0,(int)arr.size()-1};
        }
        if(totalones%3 != 0){
            return {-1,-1};
        }
        int ones = totalones/3;
        int i1=-1,j1=-1,i2=-1,j2=-1,i3=-1,j3=-1;
        int curr = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 1){
                curr++;
                if(curr == 1){
                    i1 = i;
                }
                if(curr == ones){
                    j1 = i;
                }
                if(curr == ones+1){
                    i2 = i;
                }
                if( curr == 2*ones){
                    j2 = i;
                }
                if(curr == 2*ones + 1){
                    i3 = i;
                }
                if(curr == 3*ones){
                    j3 = i;
                }
            }
        }
        if(!checkequal(i1,j1,i2,j2,arr)){
            return {-1,-1};
        }
        if(!checkequal(i1,j1,i3,j3,arr)){
            return {-1,-1};
        }
        int x = i2-j1-1;
        int y = i3-j2-1;
        int z = arr.size()-j3-1;
        if(z > x || z > y){
            return {-1,-1};
        }
        return {j1+z,j2+z+1};
    }
};
