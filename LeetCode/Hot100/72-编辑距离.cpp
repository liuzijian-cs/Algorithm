//
// Created by alpha on 2025/7/3.
//

// 我觉得这个题本质上是计算最小公共子串的问题
// 那么我觉得第一步应该是先分配一个二维dp数组
// dp[i][j] 代表word1[0...i]与字符串word2[0...j]最大公共子串长度

//     h o r s e
//   0 0 0 0 0 0
// r 0 0 0 1 1 1
// o 0 0 1 1 1 1
// s 0 0 1 1 2 2

// 转移函数：
// if(word1[i]==word2[j]) dp[i+1][j+1] = dp[i][j]+1;
// else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])

// 在得到整个dp数组之后，dp[word1.size()][word2.size()] 将代表最大公共子序列长度
// 比如horse和ros的公共子序列2，即os，由于我们只需要长度，那么只需要返回max(word1.size(),word1.size())-dp[word1.size()][word2.size()]即可
// 空间优化方便我们不需要2D dp,只需要prev和curr,大小为word1.size()


//
// 为什么我不能将这个问题按照最大公共子序列的问题进行求解？
// 这是一个非常好的问题，它触及了这两个经典动态规划问题的核心区别。
// 虽然它们的概念有关联，但不能将编辑距离问题等同于最长公共子序列（LCS）问题来求解。
// 根本原因在于，您的方法忽略了“替换”这个操作的成本。
// 最长公共子序列 (LCS):
// 它的目标是找出两个字符串中都存在的、最长的字符序列。它只关心“匹配”的字符，对于不匹配的字符，它会直接“跳过”。 编辑距离
// (Edit Distance): 它的目标是用最少的操作（插入、删除、替换）。它必须处理每一个字符，无论是匹配还是不匹配。


// 2. “替换”操作是关键区别 (The "Substitution" Operation is the Key Difference)
// 通过LCS找到公共部分，然后把各自多余的字符删除或添加。这个过程实际上只考虑了删除和插入两种操作。
// 让我们用一个简单的例子来说明：
// 将 word1 = "cat" 转换为 word2 = "cut"
// 如果按照您的LCS思路：
// 找到LCS (Find LCS): cat 和 cut 的最长公共子序列是 "ct"，长度为 2。

// 决定性的反例 (A Decisive Counterexample)
// 让我们考虑两个新的单词：
// word1 = "sea"
// word2 = "eat"

// 1. 首先，我们用您的公式来计算 (First, let's use your formula)
// word1 的长度是 3。
// word2 的长度是 3。
// "sea" 和 "eat" 的最长公共子序列 (LCS) 是 "ea"，长度为 2。
// 根据您的公式： max(3, 3) - 2 = 1。
// 您的公式预测，只需要 1 次操作。
// 1次操作绝对无法完成转换。

// 为什么您的公式在这里会失效？(Why did your formula fail here?)
// 您的公式隐含了一个假设：所有不在最长公共子序列（LCS）中的字符，都可以通过一次操作（比如替换）来解决。
// 在 word1 = "sea" 中，不在LCS("ea")里的字符是 's'。
// 在 word2 = "eat" 中，不在LCS("ea")里的字符是 't'。
// 您的公式似乎在说：“我们只需要把 's' 变成 't' 就行了，这不就是一次替换吗？”
// 但问题的关键在于位置 (Position) 。
// 字符 's' 在LCS("ea")的前面。
// 字符 't' 在LCS("ea")的后面。
// 你不能用一次操作，既处理掉字符串开头的 's'，又变出字符串结尾的
// 't'。它们是两个在空间上分离的问题，因此必须用两次独立的操作来解决（一次删除 和 一次插入）。


// =======================================
// 编辑距离（Edit Distance） 问题，也叫Levenshtein Distance
// 编辑距离不是求最大公共子序列，而是求将一个字符串转换为另一个字符串所需的最少操作次数。
// 正确的分析思路：
// 使用动态规划，dp[i][j] 表示将 word1[0...i-1] 转换为 word2[0...j-1] 所需的最少操作数
// 状态转移:
// 如果 word1[i-1] == word2[j-1]，则 dp[i][j] = dp[i-1][j-1]（不需要操作）
// 否则，取三种操作的最小值：
// 插入：dp[i][j-1] + 1
// 删除：dp[i - 1][j] + 1
// 替换：dp[i - 1][j - 1] + 1

// 进一步理解：
// 这个设计的核心思想是 “如何通过解决一个稍小一点的子问题，来解决当前的这个问题” 。
// 我们先牢牢记住 dp[i][j] 的定义：
// dp[i][j] = 将 word1 的前 i 个字符（即 word1[0...i-1]）转换成 word2 的前 j 个字符（即
// word2[0...j-1]）所需要的最少操作数。 我们的目标是求 dp[m][n]，m 和 n 分别是 word1 和 word2 的总长度。为了求出
// dp[m][n]，我们需要一步步地从 dp[0][0] ，填充整个DP表格。 现在，假设我们正在计算
// dp[i][j]，并且所有比它“小”的子问题（如 dp[i-1][j-1], dp[i-1][j], dp[i][j-1]）我们都已经计算出来了。
// 我们现在的任务是，利用这些已知的结果，来推导出 dp[i][j]。
// 我们只关注两个字符串的最后一个字符：word1[i-1] 和 word2[j-1]。
// 情况一：最简单的情况 word1[i-1] == word2[j-1]
// 这意味着，对于这最后一个字符，我们根本不需要进行任何操作，dp[i-1][j-1]。 情况二：有挑战的情况 word1[i-1] !=
// word2[j-1] 替换：1 (本次替换操作) + dp[i-1][j-1] (历史成本)；
//   我们把 word1[i-1] 强行替换成 word2[j-1]。这个动作本身花费了 1 次操作。
//   经过替换后，word1 的前 i 个字符的末尾现在和 word2 的前 j 个字符的末尾一样了。
//   问题就退化成了我们上面讨论的“情况一”，我们只需要解决 word1[0...i-2] 到 word2[0...j-2] 的转换问题。
// 删除：1 (本次删除操作) + dp[i-1][j] (历史成本)
//   我们认为 word1[i-1] 是多余的，必须删掉它才能匹配 word2 的前 j 个字符。这个动作本身花费了 1 次操作。
//   1 (本次删除操作) + dp[i-1][j] (历史成本)
// 插入： 1 (本次插入操作) + dp[i][j-1] (历史成本)
//   插入后，源字符串的末尾已经匹配了目标字符串的末尾。但我们还没处理完源字符串 word1[0...i-1]。
//   现在的任务是，把原始的源字符串 (word1 的前 i 个字符) 变成目标字符串去掉末尾字符后的部分，即 word2[0...j-2]。


#include <iostream>
#include <vector>
using namespace std;

// 96.06% - 15.52%
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();

        vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1, 0));

        // 初始化边界条件：空字符串转换需要的操作数等于目标字符串长度

        // 删除word1的字符
        for (int i = 1; i <= word1.size(); i++) dp[0][i] = i;

        // 插入word2前j个字符
        for (int j = 1; j <= word2.size(); j++) dp[j][0] = j;

        // 填充DP表格
        for (int i = 0; i < word2.size(); i++) {
            for (int j = 0; j < word1.size(); j++) {
                if (word2[i] == word1[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
            }
        }

        return dp[word2.size()][word1.size()];
    }
};
