class Solution {
public:
     string nums[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int isavail(int d, int chars[]){
        int ans = INT_MAX;
         //cout<<"cs";


        for(int i = 0 ; i < nums[d].size(); i++){

            ans = min(ans,chars[nums[d][i] -'a']);
            if(ans <= 0){
                return 0;
            }
        }

        return ans;
    }
    string originalDigits(string s) {
        int digits[10] ={0,6,2,8, 7, 3, 4, 5, 9, 1};
        int chars[26]={0};
        for(int i = 0 ; i < s.size(); i++){
           // cout<<"cs";
            chars[s[i]-'a']++;
        }

        string result = "";
        for(int i = 0 ; i < 10; i++){
            // cout<<"cs";
            int num = isavail(digits[i],chars);
             for( char c : nums[digits[i]]) {
            chars[c-'a'] -= num;
        }
            for(int j = 0 ; j < num ; j++){
                result += '0' + digits[i];
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
