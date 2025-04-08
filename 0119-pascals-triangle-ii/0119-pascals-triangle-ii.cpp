class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        for(int i=0;i<=rowIndex;i++){
            vector<int> front(i+1);
            front[0]=1;
            front[i]=1;
            for(int j=1;j<i;j++){
                front[j]=prev[j-1]+prev[j];
            }
            prev.resize(i+1);
            prev=front;
        }
        return prev;
    }
};