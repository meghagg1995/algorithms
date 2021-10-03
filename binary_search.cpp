class Solution {
public:
    int search(vector<int>& nums, int x, int s, int e) {
        if(s > e) return -1;
        int mid = (s + e)/2;
        if(nums[mid] == x) return mid;
        if(nums[mid] > x) return search(nums, x, s, mid-1);
        return search(nums, x, mid+1, e);
    }
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        while(s <= e) {
            int mid = (s + e)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) e = mid-1;
            else s = mid + 1;
        }
        return -1;
        return search(nums, target, 0, nums.size()-1);
    }
};
