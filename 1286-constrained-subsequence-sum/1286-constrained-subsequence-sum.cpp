class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap; // Create a max heap to keep track of the maximum sum and its index.
        heap.push({nums[0], 0}); // Push the first element into the heap with its value and index.
        int ans = nums[0]; // Initialize the answer with the first element's value.

        for (int i = 1; i < nums.size(); i++) { // Iterate through the remaining elements in nums.
            while (i - heap.top().second > k) { // While the index difference is greater than k (out of range):
                heap.pop(); // Remove elements from the heap that are out of range.
            }

            int curr = max(0, heap.top().first) + nums[i]; // Calculate the current sum considering the maximum possible value.
            ans = max(ans, curr); // Update the answer with the maximum of the current sum and the previous answer.
            heap.push({curr, i}); // Push the current sum and its index into the heap.
        }

        return ans; // Return the maximum sum of the constrained subset.
    }
};