class Solution {
public:
    bool find(int num)
    {
        if(num==1)
        {
            return true;
        }
        if(num%2==0)
        {
            return find(num/2);
        }
        if(num%3==0)
        {
            return find(num/3);
        }
        if(num%5==0)
        {
            return find(num/5);
        }
        return false;
    }
    bool isUgly(int num) {
        if(num==0)
        {
            return false;
        }
        if(find(num))
        {
            return true;
        }
        return false;
    }
};
