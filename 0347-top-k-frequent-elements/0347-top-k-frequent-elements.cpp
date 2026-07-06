class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> m;
        vector<pair<int, int>> v;

        for(int i : nums){
            m[i]++;
        }

        for(auto it : m){
            v.push_back(it);  //whole pair is getting pushed into this vector.
        }

        sort(v.begin(), v.end(), [](auto a, auto b){ return a.second > b.second;});
           //got sorted in frequency's descending order.

        for(int i = 0; i < k; i++){
            result.push_back(v[i].first);
        }
            return result;
    }
};