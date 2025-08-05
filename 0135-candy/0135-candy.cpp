class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=1;
        int i=1;
        int sum=0;
        while(i<n){
            if(ratings[i]<=ratings[i-1]) left[i]=1;
            else left[i]=left[i-1]+1;
            i++;
        }
        right[n-1]=1;
        i=n-2;
        while(i>=0){
            if(ratings[i]<=ratings[i+1]) right[i]=1;
            else right[i]=right[i+1]+1;
            i--;
        }
        for(int i=0;i<n;i++){
            sum+=max(right[i],left[i]);
        }
        return sum;


    }
};