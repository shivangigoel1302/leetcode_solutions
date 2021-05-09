class Solution {
public:
    vector<int>getmax(vector<int>v, int k){
        int n = v.size();
        int remove = n - k;
        stack<int>s;
        vector<int>temp(k);
        for(int i = 0 ; i < v.size(); i++){
            while(!s.empty() && s.top() < v[i] && remove){
                remove--;
                s.pop();
            }
            s.push(v[i]);
        }
        while(remove){
            s.pop();
            remove--;
        }
        int c = k-1;
        while( c>= 0 ){
            temp[c--] = s.top();
            s.pop();
        }
        return temp;
    }
    vector<int>merge(vector<int>a,vector<int>b){
        int as = a.size();
        int bs = b.size();
        vector<int>temp(as+bs);
        int c = 0;
        int i = 0,j=0;
        while(i < as && j < bs){
            if(a[i] > b[j]){
                temp[c++] = a[i++];
            }
            else if(a[i] < b[j]){
                temp[c++] = b[j++];
            }
            else{
                int x=i,y=j;
                while(x < as && y < bs){
                    if(a[x] > b[y]){
                        temp[c++] = a[i++];
                        break;
                    }
                    else if(a[x] < b[y]){
                        temp[c++] = b[j++];
                        break;
                    }
                    x++;
                    y++;
                }
                if(x == a.size()){
                    temp[c++] = b[j++];
                }
                else if(y == b.size()){
                    temp[c++] = a[i++];
                }
            }
        }
        while(i < as){
            temp[c++] = a[i++];
        }
        while(j < bs){
            temp[c++] = b[j++];
        }
        return temp;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>ans(k,INT_MIN);
        for(int i = 0; i <= nums1.size(); i++){
            if(k - i < 0){
                break;
            }
            if(k - i > nums2.size()){
                continue;
            }
            auto a = getmax(nums1,i);
            auto b = getmax(nums2,k-i);
            auto c = merge(a,b);
            if(c > ans){
                ans = c;
            }
        }
        return ans;
    }
};
