class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        if(target>=letters[n-1]) return letters[0];
        for(auto it: letters){
            if(it>target) return it;
        }
        return '0';
        
    }
};