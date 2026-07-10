class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> L(n + 1), R(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    cnt++;
                }
            }
            L[cnt].push_back(sum);
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    cnt++;
                }
            }
            R[cnt].push_back(sum);
        }

        for (int i = 0; i <= n; i++)
            sort(R[i].begin(), R[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int cnt = 0; cnt <= n; cnt++) {
            for (int x : L[cnt]) {

                int need = n - cnt;

                int target = total / 2 - x;

                auto &vec = R[need];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int s1 = x + *it;
                    int s2 = total - s1;
                    ans = min(ans, abs(s1 - s2));
                }

                if (it != vec.begin()) {
                    --it;
                    int s1 = x + *it;
                    int s2 = total - s1;
                    ans = min(ans, abs(s1 - s2));
                }
            }
        }

        return ans;
    }
};