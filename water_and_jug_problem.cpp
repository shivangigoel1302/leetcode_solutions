class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    bool canMeasureWater(int x, int y, int z) {
if(x+y<z)
{
    return false;
}
        if(z==x||z==y||z==x+y)
        {
            return true;
        }
        if(x==0||y==0)
        {
            if(z==y||z==x)
            {
                return true;
            }
            return false;
        }
        int val;
        if(x<=y)
        {
          val=gcd(x,y%x);
        }
        else
        {
            val=gcd(y,x%y);
        }
        if(z%val==0)
        {
            return true;
        }
        return false;
    }
};
