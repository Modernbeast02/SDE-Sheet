#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    vector<int>left_mini(n, 1e9);
    vector<int>right_maxi(n, -1);
    for(int i = 0; i < n; i++){
        if(i == 0){
            left_mini[i] = prices[i];
        }
        else{
            left_mini[i] = min(left_mini[i - 1], prices[i]);
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1){
            right_maxi[i] = prices[i];
        }
        else{
            right_maxi[i] = max(right_maxi[i + 1], prices[i]);
        }
    }
    int ans = -1;
    for(int i = 0; i < n; i++){
        ans = max(ans, right_maxi[i] - left_mini[i]);
    }
    return ans;
}
