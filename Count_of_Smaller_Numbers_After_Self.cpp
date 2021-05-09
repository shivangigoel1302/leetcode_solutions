class Solution {
public:
    void merge(vector<int>&count, int s , int e , int mid, vector<pair<int,int>>&v){
        int i = s;
        int j = mid+1;
        vector<pair<int,int>>temp(e-s+1);
        int k = 0;
        while(i <= mid && j <= e){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                count[v[i].second] += e - j +1;
                temp[k++] = v[i++];
            }
        }
        while(i <= mid){
            temp[k++]= v[i++];
        }
        while( j <= e){
            temp[k++] = v[j++];
        }
        for(int p = s; p <=e ;p++){
            v[p] = temp[p-s];
        }
    }
    void mergesort(vector<int>&count, vector<pair<int,int>>&v,int s, int e){
        if(s>=e) return;
        int mid = (s+e)/2;
        mergesort(count,v,s,mid);
        mergesort(count,v,mid+1,e);
        merge(count,s,e,mid,v);
    }
    vector<int> countSmaller(vector<int>& nums) {
       int N = nums.size();
        vector<int>count(N,0);
        vector<pair<int,int>>v(N);
        for(int i = 0 ; i < N; i++){
            v[i]={nums[i],i};
        }
        mergesort(count,v,0,N-1);
        return count;
    }
};
