class Solution {
public:
    bool solve(int index,vector<int> & gas,vector<int> & cost){
        int gasin=gas[index]-cost[index];
        int n=gas.size();
        int tempindex=index+1;
        tempindex=tempindex%n;
        while(tempindex!=index && gasin>=0){
            gasin+=(gas[tempindex]-cost[tempindex]);
            tempindex++;
            tempindex=tempindex%n;
        }
        if(tempindex==index && gasin>=0) return true;
        else return false;

    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            if(gas[i]>=cost[i]){
                if(solve(i,gas,cost)) return i;
            }
        }
        return -1; 
    }
};