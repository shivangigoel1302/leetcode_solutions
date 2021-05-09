class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double>ans(5,0.0);
        int minimum = 0;
        int maximum = INT_MIN;
        bool minfound = false;
        int countnum=0;
        long long int total = 0;
        int mode=0;
        int maxcount = 0;
        for(int i = 0 ; i < 256 ; i++){
             total += i*count[i];
            countnum += count[i];
            if(!minfound && count[i] != 0){
                minimum = i;
                ans[0]= minimum*(1.0);
                minfound = true;
            }
            if(count[i] !=0 && i > maximum){
                maximum = i;
            }
            if(count[i] > maxcount){
                maxcount = count[i];
                mode = i;
            }
        }
        ans[1] = maximum*(1.0);
        ans[4]= mode*(1.0);
        double mean = total/(countnum*(1.0));
        ans[2] = mean*(1.0);
        int x=-1,y=-1;
        int req = countnum/2;
        int curr = 0;
        bool found = false;

        for(int i = 0 ; i < 256 ; i++){
            curr+= count[i];

            if(curr >= req && x==-1){

                x = i;
                if(countnum%2 != 0) {
                    ans[3] = i*(1.0);
                    break;
                }
                if(curr - 1  >= req){
                    y = i;
                    ans[3] = (x+y)/2;
                    found = true;
                    break;
                }
                else{
                    for(int j = i+1; j < 256; j++){
                        if(count[j] != 0){
                            ans[3] = (x + j)/(2*(1.0));
                            found = true;
                            break;
                        }
                    }
                }
            }
            if(found){
                break;
            }
        }
        return ans;
    }
};
