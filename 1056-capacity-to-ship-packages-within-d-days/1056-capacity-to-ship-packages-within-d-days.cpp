class Solution {
public:
    bool ispossible(vector<int>& weights, int day, int mid) {
        int daycount = 1;
        long long int sum = 0;
        for (int a : weights) {
            if (sum + a <= mid)
                sum += a;
            else {
                daycount++;
                if (daycount > day or a > mid)
                    return false;

                sum = a;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int weight = 0;
        for (int i : weights)
            weight += i;

        int s = 0, e = weight, mid = s + (e - s) / 2, ans = -1;
        while (s <= e) {
            if (ispossible(weights, days, mid)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};