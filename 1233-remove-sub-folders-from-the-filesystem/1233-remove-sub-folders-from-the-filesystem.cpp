class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort folders lexicographically
        sort(folder.begin(), folder.end());
        
        vector<string> result;
        string currentParent = "";

        for (const string& f : folder) {
            // If f is not a sub-folder of the current parent, add it to result
            if (currentParent.empty() || f.find(currentParent + "/") != 0) {
                result.push_back(f);
                currentParent = f;
            }
        }
        
        return result;
    }
};