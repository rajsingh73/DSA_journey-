class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int maxleft=0;
        int maxright=0;
        int ans=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(maxleft<=height[left]) maxleft=height[left];
                else ans=ans+(maxleft-height[left]);
                left++;
            }
            else{
                if(maxright<=height[right]) maxright=height[right];
                else ans=ans+(maxright-height[right]);
                right--;
            }
        }
        return ans;
        
    }
};