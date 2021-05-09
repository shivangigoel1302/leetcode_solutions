class Solution {
public:
    int count=0;
 int power(int n){
     if(n==1){
         return count;
     }
     if(n%2==0){
         count++;
        return power(n/2);
     }
     else{
         count++;
        return  power(n*3+1);
     }
 }
    int getKth(int lo, int hi, int k) {
       set<pair<int,int>>s;
        for(int i= lo; i <= hi ; i++){
           int p = power(i);
            count=0;
            s.insert({p,i});
       }
        auto it = s.begin();
       for(int i = 1; i < k ; i++){
           it++;
       }
        return it->second;
    }
};
