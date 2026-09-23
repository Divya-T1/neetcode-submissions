class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, 0);
        f(coins,memo,amount);
        if(memo[amount]<0) return -1;
        else return memo[amount];
    }

    int f(vector<int> coins, vector<int>& memo, int curr) {
        if(curr == 0) return 0;
        if(curr < 0) return -1e9;

        if(memo[curr]==0) {
            int minV = 1e9;
            for(int c:coins) {
                int v = f(coins,memo,curr-c);
                if(v>-1) minV = min(minV,v);
            }
            if(minV==1e9) memo[curr] = -1e9;
            else memo[curr] = 1+minV;
        }

        return memo[curr];
    }
};
