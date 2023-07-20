class Solution {
public:
    vector<int>ans;
    vector<int> asteroidCollision(vector<int>& asteroids) {
        for(int i=0;i<asteroids.size();i++){
            while(ans.size()>0 && i<asteroids.size() && ans.back()>0 && asteroids[i]<0){
                if(abs(ans.back())>abs(asteroids[i])){
                    i++;
                }else if(abs(ans.back())<abs(asteroids[i])){
                    ans.pop_back();
                }else{
                    ans.pop_back();
                    i++;
                }
            }
            if(i<asteroids.size())ans.push_back(asteroids[i]);
        }
        return ans;
    }
};