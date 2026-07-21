class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int temp = x;
        int sum = 0;
        while(temp > 0){
            int last_digit = temp % 10;
            sum = sum + last_digit;
            temp = temp / 10;
        }
        //got the sum.

        if(x%sum == 0) return sum;
        else{
            return -1;
        }
    }
};