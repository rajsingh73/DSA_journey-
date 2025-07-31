class Solution {
public:
    bool f(int count,int index,string &s,vector<vector<int>> & dp){
        if(count<0) return false;
        if(index==s.size()){
            if(count==0) return true;
            else return false;
        }
        if(dp[index][count]!=-1) return dp[index][count];
        if(s[index]=='('){
            return dp[index][count]=f(count+1,index+1,s,dp);
        }
        else if(s[index]==')'){
            return dp[index][count]=f(count-1,index+1,s,dp);
        }
        else {
            return dp[index][count]=f(count+1,index+1,s,dp) || f(count-1,index+1,s,dp) || f(count,index+1,s,dp);
        }
    }

    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,s,dp);
        

        
    }
};