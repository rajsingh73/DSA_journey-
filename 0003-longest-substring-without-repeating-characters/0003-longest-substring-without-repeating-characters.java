class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> mp=new HashMap<>();
        int i=0,j=0,ans=0;
        while(j<s.length()){
            if(mp.containsKey(s.charAt(j))){
                while(mp.containsKey(s.charAt(j))){
                    mp.remove(s.charAt(i));
                    i++;
                }
            }
            mp.put(s.charAt(j),mp.getOrDefault(s.charAt(j),0)+1);
            ans=Math.max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
}