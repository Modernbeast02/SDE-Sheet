#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int end1 = intervals[0][1];
    int start1 = intervals[0][0];
    for(int i = 1; i < n; i++){
        if(intervals[i][0] > end1){
            ans.push_back({start1, end1});
            start1 = intervals[i][0];
            end1 = intervals[i][1];
        }
        else{
            end1 = max(end1,intervals[i][1]);
        }
    }
    ans.push_back({start1, end1});
    return ans;
}
