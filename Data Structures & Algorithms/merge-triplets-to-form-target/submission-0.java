class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        HashSet<Integer> set = new HashSet<>();
        int count = 0;
        for (int[] i : triplets)
        {
            int first = i[0];
            int second = i[1];
            int third = i[2];
            if (first > target[0])
                set.add(count);
            if (second > target[1])
                set.add(count);
            if (third > target[2])
                set.add(count);
            count++;
        }

        boolean containsFirst = false;
        boolean containsSecond = false;
        boolean containsThird = false;
        for (int i = 0; i < triplets.length; i++)
        {
            if (set.contains(i))
                continue;
            if (triplets[i][0] == target[0])
                containsFirst = true;
            if (triplets[i][1] == target[1])
                containsSecond = true;
            if (triplets[i][2] == target[2])
                containsThird = true;
        }
        return containsFirst && containsSecond && containsThird;

    }
}
