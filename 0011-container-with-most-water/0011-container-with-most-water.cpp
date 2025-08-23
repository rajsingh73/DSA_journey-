class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int ans=0;
        int j=height.size()-1;
        while(i<j){
            int mini=min(height[i],height[j]);
            ans=max(ans,mini*(j-i));
            if(height[i]==height[j]){
                i++;
                j--;
            }
            else if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};