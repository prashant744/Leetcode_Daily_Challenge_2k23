class Solution {
public:
    string predictPartyVictory(string senate) {
        stack<char>st;

        for(int i=0;i<senate.size();i++){
            if(st.empty()){
                st.push(senate[i]);
            }else{
                if(st.top()!=senate[i]){
                    char it=st.top();
                    st.pop();
                    senate+=it;
                }else{
                    st.push(senate[i]);
                }
            }
        }

        if(st.top()=='R'){
            return "Radiant";
        }else{
            return "Dire";
        }
    }
};