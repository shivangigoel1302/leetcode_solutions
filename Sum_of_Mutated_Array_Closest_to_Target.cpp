class Solution {
public:
    int findc(int target,int size){
        if(size == 0)return 0;
        double curr = target/(size*(1.0));
       // cout<<size<<","<<curr<<" ";
        int c = target/size;
        if(curr - c > 0.5){
            c  += 1;
        }
        return c;
    }
    int findBestValue(vector<int>& arr, int target) {
       sort(arr.begin(),arr.end());
        int minval=INT_MAX,mindiff =INT_MAX;
        int n = arr.size();
        int c = findc(target,n);
        int i = 0;
        int sum = 0;
        for(int i = 0 ; i < n; i++){
            sum += arr[i];
        }
        if(sum == target) return arr[n-1];
        while(i < arr.size()){
            if(arr[i] < c){
                target -= arr[i];
                n--;
                c = findc(target,n);
            }
            else if(arr[i] == c){
                return arr[i];
            }
            else{
                return c;
            }
            i++;
        }
        return arr[arr.size()-1];
    }
};
