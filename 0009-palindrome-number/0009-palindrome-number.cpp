class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<10) return true;
        if(x%10==0) return false;
        int temp=0;
        while(x>temp){
            int rem=x%10;
            temp=temp*10+rem;
            x=x/10;
        }
        if(temp==x || temp/10==x) return true;
        return false;
        
        
    }
};