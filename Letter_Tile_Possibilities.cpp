class Solution {
public:
    int helper(int a[]){
        int sum = 0;
        for(int i = 0 ; i < 26; i++){
            if(a[i] == 0)continue;
            sum++;
            a[i]--;
            sum += helper(a);
            a[i]++;
        }
        return sum;
    }
    int numTilePossibilities(string tiles) {
        int a[26]={0};
        for(int i = 0; i < tiles.size(); i++){
            a[tiles[i] - 'A']++;
        }
        return helper(a);
    }
};
