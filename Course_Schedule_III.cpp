class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
     sort(courses.begin(),courses.end(),[](vector<int>v1,vector<int>v2){
         if(v1[1] != v2[1]){
             return v1[1] < v2[1];
         }
         return v1[0] < v2[0];
     });
     int start = 0;
        int count = 0;
        priority_queue<int>pq;
        for(int i = 0; i < courses.size();){
      // cout<<courses[i][0]<<" "<<courses[i][1]<<endl;
            int end = start + courses[i][0];
            if(end <= courses[i][1]){
                //cout<<i<<endl;
                //courses[count++] = courses[i];
                count++;
                pq.push(courses[i][0]);
                start = end;
            }
            else{
                if( ! pq.empty() && pq.top() > courses[i][0]){
                    start = start - pq.top() + courses[i][0];
                    pq.pop();
                    pq.push(courses[i][0]);
                }
                // int max_i = i;
                // for(int k = 0; k < count; k++){
                //     if(courses[k][0] > courses[max_i][0]){
                //         max_i = k;
                //     }
                // }
                // if(courses[max_i][0] > courses[i][0]){
                //     start = start - courses[max_i][0] + courses[i][0];
                //     courses[max_i] = courses[i];
                // }
            }
            i++;
        }
        return count;
    }
};
