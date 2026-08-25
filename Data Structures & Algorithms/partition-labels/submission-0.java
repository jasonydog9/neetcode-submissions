class Solution {
    public List<Integer> partitionLabels(String s) {
        int count = 0;
        ArrayList<Integer> res = new ArrayList<>();
        HashSet<Character> set = new HashSet<>();
        HashMap<Character, Integer> map = new HashMap<>(); 
        for (char c : s.toCharArray())
        {
            map.putIfAbsent(c, 0);
            map.put(c, map.get(c) + 1);
        }
        for (int i = 0; i < s.length(); i++)
        {
            count++;
            set.add(s.charAt(i));
            map.put(s.charAt(i), map.get(s.charAt(i)) - 1);
            if (map.get(s.charAt(i)) != 0)
            {
                continue;
            }
            boolean allZero = true;
            for (char c : set)
            {
                if (map.get(c) != 0)
                    allZero = false;
            }
            if (allZero)
            {
                res.add(count);
                count = 0;
            }
        }
        return res;
    }
}
