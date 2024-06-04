#include <bits/stdc++.h>
using namespace std;
vector<int> minunits(const vector<int>& units, int maxval) 
{
    vector<int> dp(maxval + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= maxval; ++i) 
    {
        for (int j : units) 
        {
            if (j <= i && dp[i - j] != INT_MAX) 
            {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
    return dp;
}

pair<vector<int>, double> opt_units(const vector<int>& posunits, int maxval) 
{
    double minavg =DBL_MAX;
    vector<int> bestcomb;
    vector<int> combination(6);
    vector<int> ind(posunits.size());
    iota(ind.begin(), ind.end(), 0);
    do 
    {
        for (int i = 0; i < 6; ++i) 
        {
            combination[i] = posunits[ind[i]];
        }

        vector<int> dp = minunits(combination, maxval);
        double sum_units = accumulate(dp.begin() + 1, dp.end(), 0);
        double avgunits = sum_units / maxval;

        if (avgunits < minavg) 
        {
            minavg = avgunits;
            bestcomb = combination;
        }
    } while (next_permutation(ind.begin(), ind.end()));

    return {bestcomb, minavg};
}

int main() 
{
    vector<int> posunits ;
    for(int i=0;i<6;i++)
    {
        int d;
        cin>>d;
        posunits.push_back(d);
    }
    auto result = opt_units(posunits, 99);
    vector<int> bestcomb = result.first;
    double minavg = result.second;
    cout << "Opt set of units: ";
    for (int i : bestcomb) 
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Avg number of units used: " << minavg << endl;

    return 0;
}