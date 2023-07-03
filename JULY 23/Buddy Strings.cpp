class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1=s.size(),n2=goal.size();
        if(n1!=n2 || n1==1){
            return 0;
        }
        vector<int>vec;
        int j=0;
        set<int>st(s.begin(),s.end());

        if(s==goal && st.size()<s.size()){
            return true;
        }

        for(int i=0;i<n1;i++){
            if(s[i]!=goal[i]){
                vec.push_back(i);
            }
        }

        return vec.size()==2 && s[vec[0]]==goal[vec[1]] && s[vec[1]]==goal[vec[0]];

    }
};