class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        
        HashMap<Integer, Integer> map = new HashMap<>();
        Arrays.sort(hand);
        for (int i : hand)
        {
            map.putIfAbsent(i, 0);
            map.put(i, map.get(i) + 1);
        }
        if (hand.length%groupSize != 0)
            return false;
        int start = 0;
        for (int i : hand)
        {
            if (map.get(i) == 0)
                continue;
            for (int idx = 0; idx < groupSize; idx++)
            {
                if (!map.containsKey(i) || map.get(i) == 0)
                    return false;
                map.put(i, map.get(i) - 1);
                i++;
            }
        }
        return true;
    }
}
