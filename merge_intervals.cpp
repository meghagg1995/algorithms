class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        vector<vector<int>> ans;
        /* sort(intervals.begin(), intervals.end(), compare); */
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0] <= end) {
                /* common mistake */
                /* current interval can completely overlap ith interval */
                /* end = intervals[i][1] */
                end = max(end, intervals[i][1]);
            } else {
                vector<int> v{start, end};
                ans.push_back(v);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> v{start, end};
        ans.push_back(v);
        return ans;
    }
};
