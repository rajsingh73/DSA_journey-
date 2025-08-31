class SmallestInfiniteSet {
public:
    set<int> st;
    priority_queue<int,vector<int>,greater<int>> pq;
    SmallestInfiniteSet() {
        for(int i=1;i<=1001;i++){
            st.insert(i);
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int val=pq.top(); pq.pop();
        st.erase(val);
        return val;
        
    }
    
    void addBack(int num) {
        if(st.count(num)==0){
            pq.push(num);
            st.insert(num);
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */