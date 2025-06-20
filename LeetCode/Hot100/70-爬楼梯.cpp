//
// Created by alpha on 2025/6/20.
//

# include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        // Initialize first two states: f(1)=1, f(2)=2,
        int n_1 = 1;
        int n_2 = 2;
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = n_1 + n_2; // n_3
            n_1 = n_2;      // n_2
            n_2 = current;  // n_3
        }
        return current;
    }
};

int main() {
    Solution solution;
    std::cout << "n = 2: " << solution.climbStairs(2) << std::endl; // 应输出2 / Output: 2
    std::cout << "n = 3: " << solution.climbStairs(3) << std::endl; // 应输出3 / Output: 3
    std::cout << "n = 4: " << solution.climbStairs(4) << std::endl; // 应输出5 / Output: 5
    return 0;
}
