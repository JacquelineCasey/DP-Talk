/* https://open.kattis.com/problems/everythingisanail 
 * A problem at 2022 Mid-Central regional. 
 *
 * A correct but slow recursive version of soln.cpp
 * 
 * Status: Time Limit Exceeded at the 18th test */

#include <iostream>
#include <vector>
#include <array>

/* Given a fixed order of `tools`, determines the maximum number of tasks that can
 * be completed out of tasks[0...i] (inclusive) and tools [0..j] */
int max_tasks(std::vector<int>& tasks, std::array<int, 3>& tools, int i, int j) {
    // Please don't forget the (&)'s
    
    // slightly more convenient base case.
    if (i == -1) {
        return 0;
    }

    // Hit the current task with the current tool
    int highest = max_tasks(tasks, tools, i-1, j) + (tasks[i] == tools[j] ? 1 : 0);

    for (int k = j - 1; k >= 0; k--) {
        // Or switch from a previous tool
        highest = std::max(highest, max_tasks(tasks, tools, i, k));
    }

    return highest;
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
        max = std::max(max_tasks(tasks, tools, n-1, 2), max);   
    }

    std::cout << max << '\n';
}
