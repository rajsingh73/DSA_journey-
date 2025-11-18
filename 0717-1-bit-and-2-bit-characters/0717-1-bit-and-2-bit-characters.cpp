class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool onebit=false;
        bool twobit=false;
        int i=0;
        while(i<bits.size()){
            if(bits[i]==1){
                twobit=true;
                onebit=false;
                i=i+2;
            }
            else{
                twobit=false;
                onebit=true;
                i++;
            }
        }
        return onebit;
        
    }
};