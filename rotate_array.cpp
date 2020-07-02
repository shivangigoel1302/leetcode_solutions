class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k=k%nums.size();
        int count=0;
    for(int i=0;count<nums.size();i++)
    {
        int current=i;
        int key=nums[i];
        do{
            int next=(current+k)%nums.size();
            int temp=nums[next];
            nums[next]=key;
            key=temp;
            current=next;
            count++;
        }while(current!=i);
      }
    }
};
