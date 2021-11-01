class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
     long long int maxstone = 0;
     long long int sum = 0;
        for(int i = 0; i < milestones.size(); i++){
            sum += milestones[i];
            maxstone = max(maxstone,(long long)milestones[i]);
        }
        sum -= maxstone;
        if(sum < maxstone){
            return sum*2 + 1;
        }
        return sum+maxstone;
    }
};
