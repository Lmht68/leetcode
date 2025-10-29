class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index = 0, index1 = 0, index2 = numbers.size() - 1, sum = 0;
        vector<int> results;

        while (true) {
            sum = numbers[index1] + numbers[index2];

            if (sum == target) {
                results.push_back(index1 + 1);
                results.push_back(index2 + 1);
                break;
            }

            if (sum > target) {
                index2--;
                continue;
            }

            index1++;
        }

        return results;
    }
};