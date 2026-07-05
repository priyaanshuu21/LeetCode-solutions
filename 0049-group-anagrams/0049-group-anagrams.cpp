class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m;
        vector<vector<string>> result;

        for(string i : strs){
            string temp = i;    //temp contains the original string
            sort(temp.begin(), temp.end());   //gets sorted here
            m[temp].push_back(i);    //temp now contains the sorted string as key.
        }

        for(auto it : m){
            result.push_back(it.second);
        }
        return result;
    }
};