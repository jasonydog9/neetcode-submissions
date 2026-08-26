class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : nums)
        {
            map.putIfAbsent(i, 0);
            map.put(i, map.get(i) + 1);
        }

        for (int i : map.keySet())
        {
            if (map.get(i) != 2)
                return i;
        }
        return 0;
    }
}
