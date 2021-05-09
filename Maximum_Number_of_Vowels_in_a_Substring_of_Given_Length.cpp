class Solution {
public:
    int maxVowels(string s, int k) {
        deque<char>q;
        string vowel = "aeiou";
        int count = 0;
        int ans = 0;
        for(int i = 0 ; i < k; i++){
            q.push_back(s[i]);
            if(vowel.find(s[i]) != string::npos){
                count++;
            }
        }

        ans = max(ans,count);
        for(int i = k; i < s.size(); i++){
             cout<<count;
            if(vowel.find(q.front()) != string::npos){
                count--;
                // q.pop_front();
            }
             if(vowel.find(s[i]) != string::npos){
                count++;

            }
            q.push_back(s[i]);
            q.pop_front();
            ans = max(ans,count);
        }
        return ans;
    }
};
