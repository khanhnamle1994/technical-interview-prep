/* We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job.

Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i].

Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.

What is the most profit we can make?

Example 1:
Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperately. */

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    // Build index array
    vector<int> indices(difficulty.size());

    iota(indices.begin(), indices.end(), 0);

    // Sort indices based on increasing 1. difficulty 2. profit
    sort(indices.begin(), indices.end(), [&difficulty, &profit] (int i1, int i2) {
        return difficulty[i1] == difficulty[i2] ? profit[i1] < profit[i2]
                                                : difficulty[i1] < difficulty[i2];
    });

    // Sort workers with increasing difficulty
    sort(worker.begin(), worker.end());

    // Total profit
    int totalProfit = 0;

    // End of search space
    auto itend = indices.begin();

    // Lower difficulty job with max profit so far
    int maxProfit = 0;

    // Find max profit for each worker
    for (int w = 0; w < worker.size(); ++w) {
        if (w && worker[w] == worker[w - 1]) {
            totalProfit += maxProfit;
            continue;
        }

        // Iterate from the previous search end
        auto it = itend;

        // Find upper bound for current search
        itend = upper_bound(itend, indices.end(), worker[w], [&difficulty] (int i1, int i2) {
            return i1 < difficulty[i2];
        });

        // Search for max profit in indices range - [prev upper bound, curr upper bound]
        while (it != itend) {
            maxProfit = max(maxProfit, profit[*it]);
            ++it;
        }

        // Add profit
        totalProfit += maxProfit;
    }

    return totalProfit;
}
