class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int,long long> mp;
        int i=0;
        int n=tasks.size();
        long long ans=0;
        while(i<n){
            if(mp.find(tasks[i])!=mp.end()){
                long long br=ans-mp[tasks[i]]-1;
                cout<<br<<" "<<ans<<endl;
                if(space-br>0){
                    ans+=(space-br);
                }
                mp[tasks[i]]=ans;
                ans++;
            }
            else{
                mp[tasks[i]]=ans;
                ans++;
            }
            i++;
        }
        return ans;
        
    }
};