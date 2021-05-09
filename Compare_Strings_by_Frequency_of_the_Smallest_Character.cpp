class Solution {
public:
    int frequency(string word){
        int arr[26]={0};
        for(int i = 0 ; i < word.size(); i++){
            arr[word[i]-'a']++;
        }
        for(int i = 0 ; i < 26; i++){
            if(arr[i] !=0){
                return arr[i];
            }
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>q(queries.size());
        vector<int>w(words.size());
        for(int i = 0 ; i < queries.size(); i++){
            q[i]=frequency(queries[i]);
        }
        for(int i = 0 ; i < words.size(); i++){
            w[i]= frequency(words[i]);
        }
        sort(w.begin(),w.end());
        vector<int>ans(queries.size());
        for(int i =0 ; i <q.size(); i++){
            int j = 0;
            for( ; j < w.size() && q[i] >=w[j] ; j++){
            }
            ans[i] = w.size()-j;
        }
        return ans;
    }
};
