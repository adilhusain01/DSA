//Input size of array, value of array, a target.
//The code gives the only possible answer as index of two numbers in the array whose sum is = target

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_indices;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_indices.find(complement) != num_indices.end()) {
            return {num_indices[complement], i};
        }
        num_indices[nums[i]] = i;
    }

    return {};
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices of the two numbers: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No valid solution found." << endl;
    }

    return 0;
}
