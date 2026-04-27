class Solution {
    public Boolean palindrome(String s,int n,int m){
        while(n<m){
            if(s.charAt(n)!=s.charAt(m)) return false;
            n++;
            m--;
        }
        return true;
    }
    public String longestPalindrome(String s) {
        HashMap<Character,ArrayList<Integer>> mp=new HashMap<>();
        int start=0;
        int end=0;
        int ans=1;
        for(int i=0;i<s.length();i++){
            if(mp.containsKey(s.charAt(i))){
                for(int it: mp.get(s.charAt(i))){
                    if(palindrome(s,it,i)){
                        if(i-it+1>ans){
                            start=it;
                            end=i;
                            ans=i-it+1;
                        }
                    }
                }
            }
            mp.putIfAbsent(s.charAt(i),new ArrayList<>());
            mp.get(s.charAt(i)).add(i);
        }
        if(start==0 && end==0) return s.substring(0,1);
        else return s.substring(start,start+ans);
    }
}