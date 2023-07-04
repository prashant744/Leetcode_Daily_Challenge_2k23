class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>map;
        for(const int num:nums){
            if(map.count(num)>0){
                map[num]++;
            }else{
                map[num]=1;
            }
        }
        for(const auto&[num,count] : map){
            if(count==1){
                return num;
            }
        }
        return -1;
    }
};