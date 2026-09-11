class Solution {
public:
    int solve(vector<int> & freq,int pos){
        if(pos==3) return 1;
        int count=0;
        for(int digit=0;digit<10;digit++){
            if(freq[digit]==0) continue;
            if(pos==0 && digit==0) continue;
            if(pos==2 && digit%2!=0) continue;
            freq[digit]--;
            count+=solve(freq,pos+1);
            freq[digit]++;
        }
        return count;
    }
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(auto it: digits){
            freq[it]++;
        }
        return solve(freq,0);
    }
};