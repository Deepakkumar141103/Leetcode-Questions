class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = 0;

        for (int x : arr) {
            total += x;
        }

        if (total % 3 != 0) return false;

        int target = total / 3;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            sum += arr[i];

            if (sum == target) {
                count++;
                sum = 0;
            }

            if (count == 2) return true;
        }

        return false;
    }
};