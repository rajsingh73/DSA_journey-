class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                long long twosum=pow(i,2)+pow(j,2);
                for(int k=1;k<=n;k++){
                    if(twosum==pow(k,2)) count++;
                }
            }
        }
        return count;
        
    }
};