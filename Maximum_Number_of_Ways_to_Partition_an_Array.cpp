#define ll long long
class Solution {
public:
     vector<ll> left(vector<int> num){

        ll n=num.size();
        vector<ll> v(n,0);
        ll x=num[0];
        for(ll i=1;i<n;i++){
            v[i]=x;
            x+=num[i];
        }
        return v;
    }
    vector<ll> right(vector<int> num){

        ll n=num.size();
        vector<ll> v(n,0);
        v[n-1]=num[n-1];
        for(int i=n-2;i>=0;i--){
            v[i]=v[i+1]+num[i];
        }
        return v;
    }
    int waysToPartition(vector<int>& nums, int k) {

        vector<ll> l=left(nums);
        vector<ll> r=right(nums);
        unordered_map<ll,ll> m1,m2;

        ll n=nums.size();
        ll c=0;

        for(int i=1;i<n;i++){
            if(l[i]==r[i])
                c++;
        }
        ll ans=c;
        c=0;

        for(int i=1;i<n;i++){
            m1[r[i]-l[i]]++;
        }

          ll diff= k-nums[0];
          c+=m1[diff];
          ans= max(ans,c);
         m1[r[1]-l[1]]--;

        for(ll i=1;i<n;i++){
              c=0;
             m2[l[i]-r[i]]++;
            diff= k-nums[i];

              c+=m2[diff];
              c+=m1[diff];

            ans= max(ans,c);

            if(i!=(n-1 ))
              m1[r[i+1]-l[i+1]]--;
        }

        return ans;
    }
};
