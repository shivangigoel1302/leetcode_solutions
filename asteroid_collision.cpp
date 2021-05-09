class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>v;
        if(asteroids.size()==1){
            v.push_back(asteroids[1]);
            return v;
        }
        stack<int>s;
        s.push(asteroids[0]);
         bool isright =false;
        if(s.top() >= 0){
            isright = true;
        }

        for(int i = 1 ; i < asteroids.size() ; i++){
            if(isright){
                    long long int top = asteroids[i];
                    while(!s.empty() && top!= 10000 && s.top() * top <0){
                        if(abs(s.top()) < abs(top)){
                            s.pop();
                        }
                        else if(abs(s.top()) > abs(top)){
                            top = s.top();
                            s.pop();
                            break;
                        }
                        else if(abs(s.top()) == abs(top)){
                            s.pop();
                            top = 10000;
                        }
                    }
                if(top != 10000){
                    s.push(top);
                }
                if(s.empty() || s.top() < 0){
                    isright = false;
                }
            }
            else{
                if(asteroids[i] >= 0){
                    isright = true;
                }
                s.push(asteroids[i]);
            }
        }
        if(!s.empty()){
          while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        }

        return v;
    }
};
