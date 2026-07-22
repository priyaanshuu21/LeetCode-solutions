class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1; 
        int right = piles[0];
        for(int i : piles){
            if(i > right) right = i;
        }
        while(left <= right){
            int mid = left + (right - left) / 2;
            long int k = 0; 

            for(int i : piles){
                k = k + (i/mid);      //calculating hours for each pile.
                if(i % mid != 0) k++;  //check if there are more bananas left in that pile.
            }

            if(k > h){
                left = mid + 1;
            }
            else{   //if k <= h
                right = mid - 1;
            }
        }
        return left; //minimum possible when left<=right 
    }
};