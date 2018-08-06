#include<string>
#include<vector>
#include<iostream>

#include<limits.h>
using namespace std;


int maxProfitIII(vector<int> &prices) {
    if (prices.empty()) return 0;
    int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
    for (int i = 1; i < prices.size(); ++i) {
        int diff = prices[i] - prices[i - 1];
        for (int j = 1; j <= 2; ++j) {
            l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
            g[i][j] = max(l[i][j], g[i - 1][j]);
        }
    }
    return g[n - 1][2];
}

//能够买卖多次
int maxProfit_II(vector<int>& prices) {
    int res = 0, n = prices.size();
    for (int i = 0; i < n - 1; ++i) {
        if (prices[i] < prices[i + 1]) {
            res += prices[i + 1] - prices[i];
        }
    }
    return res;
}
//只买卖一次
int maxProfit_I(vector<int>& prices) {
    int res = 0, buy = INT_MAX;
    for (int i=0;i<prices.size();i++) {
        buy = min(buy, prices[i]);
        res = max(res, prices[i] - buy);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int a[]={1,3,2,9};
    vector<int> v(a,a+4);
    cout<<maxProfitIII(v)<<endl;
    cin.get();

    return 0;
}
