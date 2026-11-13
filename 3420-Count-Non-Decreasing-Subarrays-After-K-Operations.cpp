
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;

        deque<pair<int, int>> dq;
        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int cnt = 1;

            while (!dq.empty() && dq.back().first < nums[i]) {
                auto [val, freq] = dq.back();
                dq.pop_back();

                cost += 1LL * (nums[i] - val) * freq;
                cnt += freq;
            }

            dq.push_back({nums[i], cnt});

            while (cost > k) {
                auto [val, freq] = dq.front();
                dq.pop_front();

                cost -= 1LL * (val - nums[j]);
                freq--;

                if (freq > 0) {
                    dq.push_front({val, freq});
                }

                j--;
            }

            ans += j - i + 1;
        }

        return ans;
    }
};
