/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]
Example:
  1. Given nums = [1,5,1,1,6,4] one possible answer is [1,4,1,5,1,6]
  2. Given nums = [1,3,2,2,3,1] one possible answer is [2,3,1,3,1,2]

Note:
  You may assume all input has valid answer.

Follow up:
  can you do it in O(n)time and/or in-place with O(1) extra space?
*/


//--------------------------------------------------easiest Solution

class Solution {
public:
  void wiggleSort(vector<int>& nums) {
      vector<int> sorted(nums);
      sort(sorted.begin(), sorted.end());
      for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
          nums[i] = sorted[i&1 ? k++ : j++];
  }
};

//---------------------------------hard--******--**--*-*-*-*----O(n)time + O(1)space


void wiggleSort(vector<int>& nums) {
    int n = nums.size();

    // Find a median.
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}
