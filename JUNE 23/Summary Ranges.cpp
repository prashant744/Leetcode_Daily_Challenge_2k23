class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        if(nums.size()==1){
            return {to_string(nums[0])};
        }

        int a=nums[0],b=nums[0];
        nums.push_back(0);
        vector<string>v;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-1!=nums[i]){
                if(a==b){
                    v.push_back(to_string(a));
                }else{
                    v.push_back(to_string(a)+"->"+to_string(b));
                }
                a=nums[i+1],b=nums[i+1];
            }else{
                b++;
            }
        }
        return v;
    }
};