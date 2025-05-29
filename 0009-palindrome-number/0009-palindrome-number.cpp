class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0)) return false;
        int temp=0;
        while(temp<x){
            temp=temp*10+x%10;
            x=x/10;
        }
        if(temp==x || temp/10==x) return true;
        return false;
        
    }
};