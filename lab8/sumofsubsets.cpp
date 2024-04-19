#include <iostream>
#include <vector>

using namespace std;

// Function to print the subset that sums up to the target
void printSubset(const vector<int>& subset) {
    cout << "Subset with target sum found: ";
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}
//nums =vector of integers representing input size
//subset=current subset being constructed 
//index=index of current element in 'nums' being constructed
// Backtracking function to find subsets with the target sum
void subsetSumUtil(const vector<int>& nums, int target, vector<int>& subset, int index) {
    // Base case: if the subset's sum equals the target, print the subset
    if (target == 0) {
        printSubset(subset);
        return;
    }

    // Base case: if index exceeds the size of the nums array or target becomes negative, backtrack
    if (index == nums.size() || target < 0) {
        return;
    }

    // Include the current element in the subset
    subset.push_back(nums[index]);
    subsetSumUtil(nums, target - nums[index], subset, index + 1);

    // Exclude the current element from the subset
    subset.pop_back();
    subsetSumUtil(nums, target, subset, index + 1);
}

// Function to find subsets with the target sum using backtracking
void subsetSum(const vector<int>& nums, int target) {
    vector<int> subset;
    subsetSumUtil(nums, target, subset, 0);
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 8;

    cout << "Subsets with sum " << target << " are:" << endl;
    subsetSum(nums, target);

    return 0;
}

