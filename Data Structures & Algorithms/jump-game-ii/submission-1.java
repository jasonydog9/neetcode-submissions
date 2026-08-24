class Solution {
    public int jump(int[] nums) {
        int curr = 0;
        int jumps = 0;
        while (curr < nums.length - 1)
        {
            int reach = nums[curr] + curr; // 2
            int idx = curr + 1; // 3
            if (reach >= nums.length - 1 )
            {
                jumps++;
                break;
            }
            for (int i = curr + 2; i <= reach; i++) // 4
            {
                if (nums[i] + i > nums[idx] + idx) // 
                { 
                    idx = i;
                }
            }
            curr = idx;
            jumps++;
        }
        return jumps;
    }
}
