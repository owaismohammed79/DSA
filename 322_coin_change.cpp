class Solution {
public:
    /*So inf number coins, need to make the exact amt in min number of coins. Sorted
    coins is a pretty good way to go about, then highest to lowest, check number of times
    the current coin multiple can be added to current cost. But will it cover all possible
    combinations?? no i guess? like I can take lesser multiple of the current no, but if I 
    do that it'll increase the number of coins that I pick up,, but there might also be a scenario
    where in I'm not at all able to satisfy the amount when I used a highest multiple but was
    possible when a smaller multiple was taken, even if it has more coins that were picked up??
    Guess just trying out all possible combinations is the simplest way. How would you decide
    that how many coins I should pick?? Maybe another recursion or divide of paths for the solution?*/
    int memo[13][10001]; 

    int fn(vector<int>& coins, int amount, int ind) {
        if(amount == 0) return 0;
        if(ind >= coins.size() || amount < 0) return 1e9;
        if(memo[ind][amount] != -1) return memo[ind][amount];

        //pick the coin
        int pick = 1 + fn(coins, amount - coins[ind], ind);
        //skip the coin
        int skip = fn(coins, amount, ind + 1);
        return memo[ind][amount] = min(pick, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));
        int result = fn(coins, amount, 0);        
        return (result >= 1e9) ? -1 : result;
    }
};