class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(right.size()==0 || left.size()==0) left.push(num);
        else if(left.top()<num) right.push(num);
        else left.push(num);
        if(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
        
    }
    
    double findMedian() {
        int size=left.size()+right.size();
        if(size%2==0){
            return (left.top()+right.top())/2.0;
        }
        else return left.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */