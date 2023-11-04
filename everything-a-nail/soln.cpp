/* https://open.kattis.com/problems/everythingisanail 
 * A problem at 2022 Mid-Central regional. 
 *
 * Status: Passes all tests. */

#include <iostream>
#include <vector>
#include <array>

/* Given a fixed order of `tools`, determines the maximum number of tasks that can
 * be completed. */
int max_tasks(std::vector<int>& tasks, std::array<int, 3>& tools) {
    std::vector<std::vector<int>> DP(3, std::vector (tasks.size(), 0));

    const int n = tasks.size();

    // DP[i][j] is how many tasks can you get where you end up at task j holding tool i.

    // Base cases
    DP[0][0] = tasks[0] == tools[0] ? 1 : 0;
    DP[1][0] = tasks[0] == tools[1] ? 1 : 0;
    DP[2][0] = tasks[0] == tools[2] ? 1 : 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < n; j++) {
            // Corresponds to completing task[j] with held tool[i]
            int highest = DP[i][j-1] + (tasks[j] == tools[i] ? 1 : 0);  

            for (int k = i - 1; k >= 0; k--) {
                // Corresponds to switching from tool k to tool i.
                highest = std::max(highest, DP[k][j]); 
            }

            DP[i][j] = highest;
        }
    }

    return DP[2][n-1];
}

std::array<std::array<int, 3>, 6> configs {{
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 1, 0},
    {2, 0, 1}
}};

int main() {
    int n;
    std::cin >> n;

    std::vector<int> tasks(n, 0);

    for (int i = 0; i < n; i++) {
        std::cin >> tasks[i];
    }
    
    int max {0};
    for (auto tools : configs) {
        max = std::max(max_tasks(tasks, tools), max);   
    }

    std::cout << max << '\n';
}
