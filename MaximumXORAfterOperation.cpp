// LeetCode
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n = 0;
        for(int x : nums) {
            n |= x;
        }
        return n;
    }
};