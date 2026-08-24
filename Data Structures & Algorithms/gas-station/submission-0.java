class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0;
        int gas_left = 0;
        int start = 0;

        int sum_gas = Arrays.stream(gas).sum();
        int sum_cost = Arrays.stream(cost).sum();

        if (sum_gas < sum_cost) {
            return -1;
        }

        for (int i = 0; i < gas.length; i++) {
            int net_gas = gas[i % gas.length] - cost[i % gas.length];

            gas_left += net_gas;
            total += net_gas;

            // if gas_left ever becomes negative
            if (gas_left < 0) {
                start = i + 1;
                gas_left = 0;
            }
        }

    
        return start;
    }
}
