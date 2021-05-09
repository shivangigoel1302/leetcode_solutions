class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>m;
        for(int i= 0 ; i < barcodes.size(); i++){
            m[barcodes[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i :m){
            pq.push({i.second,i.first});
        }
        int start = 0;
        while(pq.size()>=2){
            auto fir = pq.top();
            pq.pop();
            auto sec = pq.top();
            pq.pop();
            barcodes[start++]=fir.second;
            barcodes[start++] = sec.second;
            if(fir.first > 1){
                pq.push({fir.first-1,fir.second});
            }
            if(sec.first > 1){
                pq.push({sec.first-1,sec.second});
            }
        }
        if(pq.size()){
            barcodes[barcodes.size()-1] = pq.top().second;
        }
        return barcodes;
    }
};
