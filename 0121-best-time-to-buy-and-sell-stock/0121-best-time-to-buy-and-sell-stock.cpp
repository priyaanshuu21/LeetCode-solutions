class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minimumP = prices[0];
        int answer = 0;
        int n = prices.size(); 

        for(int i = 0; i < n; i++){
            minimumP = min(prices[i], minimumP);
            profit = prices[i] - minimumP;
            answer = max(answer, profit);
        }
        return answer;
    }
};