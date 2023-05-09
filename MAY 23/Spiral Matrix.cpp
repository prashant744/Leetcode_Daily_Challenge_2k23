class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0,left=0;
        int bottom=matrix.size()-1,right=matrix[0].size()-1;
        int dir=0;
        vector<int>vec;

        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    vec.push_back(matrix[top][i]);
                }
                top++;
            }else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    vec.push_back(matrix[i][right]);
                }
                right--;
            }else if(dir==2){
                for(int i=right;i>=left;i--){
                    vec.push_back(matrix[bottom][i]);
                }
                bottom--;
            }else{
                for(int i=bottom;i>=top;i--){
                    vec.push_back(matrix[i][left]);
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return vec;
    }
};