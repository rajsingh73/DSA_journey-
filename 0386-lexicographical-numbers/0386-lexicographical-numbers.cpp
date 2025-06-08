class Solution {
public:
    void solve(int n,vector<int> & result,int value){
        if(result.size()==n) return;
        if(value>n) return;
        result.push_back(value);
        for(int i=0;i<=9;i++){
            int temp=value;
            value=(value*10)+i;
            solve(n,result,value);
            value=temp;
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i=1;i<=n;i++){
            solve(n,result,i);
        }
        return result;
    }
};