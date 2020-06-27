class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int* left=new int[prices.size()];
        int* right=new int[prices.size()];
        int minimum=INT_MAX;
        int localmax=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<minimum)
            {
                minimum=prices[i];
            }
            else
            {
                localmax=max(localmax,prices[i]-minimum);
            }
            left[i]=localmax;
        }
        int maximum=INT_MIN;
        localmax=0;
        for(int i=prices.size()-1;i>=0;i--)
        {
            if(prices[i]>maximum)
            {
                maximum=prices[i];
            }
            else
            {
                localmax=max(localmax,maximum-prices[i]);
            }
            right[i]=localmax;
        }
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            ans=max(ans,left[i]+right[i]);
        }
        return ans;
    }
};
