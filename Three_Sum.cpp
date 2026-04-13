#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    // Step 1: Sort
    sort(nums.begin(), nums.end());

    // Step 2: Fix one element
    for (int i = 0; i < n - 2; i++) {

        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        // Step 3: Two pointer search
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for left & right
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

// Driver code
int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = threeSum(nums);

    cout << "Output:\n";
    for (auto &triplet : ans) {
        cout << "[";
        for (int x : triplet) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}