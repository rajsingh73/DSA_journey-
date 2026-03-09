class Solution {
public:
    void wiggleSort(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it: arr) pq.push(it);
        int i=arr.size()%2==0?arr.size()-2:arr.size()-1;
        while(i>=0){
            arr[i]=pq.top();
            i-=2;
            pq.pop();
        }
        i=arr.size()%2==0?arr.size()-1:arr.size()-2;
        while(i>=1){
            arr[i]=pq.top();
            i-=2;
            pq.pop();
        }
        
    }
};