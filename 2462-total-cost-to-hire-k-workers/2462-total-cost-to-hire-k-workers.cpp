class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> left,right;
        int i=0;
        int n=costs.size();
        int j=n-1;
        for(int temp=0;temp<candidates && i<=j;temp++){
            left.push({costs[i],i});
            i++;
        }
        for(int temp=0;temp<candidates && j>=i ;temp++){
            right.push({costs[j],j});
            j--;
        }
        long long ans=0;
        for(int temp=0;temp<k;temp++){
            if(!left.empty() && !right.empty()){
                if(left.top()<=right.top()){
                    auto [val,index]=left.top(); left.pop();
                    if(i<=j){
                        left.push({costs[i],i});
                        i++;
                    }
                    ans+=val;
                }
                else{
                    auto [val,index]=right.top(); right.pop();
                    if(j>=i){
                        right.push({costs[j],j});
                        j--;
                    }
                    ans+=val;
                }
            }
            else if(!right.empty()){
                auto [val,index]=right.top(); right.pop();
                if(j>=i){
                    right.push({costs[j],j});
                    j--;
                }
                ans+=val;
            }
            else{
                auto [val,index]=left.top(); left.pop();
                if(i<=j){
                    left.push({costs[i],i});
                    i++;
                }
                ans+=val;                
            }
        }
        return ans;  
    }
};