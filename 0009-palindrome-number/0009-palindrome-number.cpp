class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) return true;
        if(x<0 || x%10==0) return false;
        int last=0;
        while(x>last){
            int rem=x%10;
            last=(last*10)+rem;
            x=x/10;
        }
        return x==last  || x==last/10;
    }
};