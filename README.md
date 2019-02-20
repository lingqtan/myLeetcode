# myLeetcode
leetcode刷题日志

## Array

#### array-0-star

| [\*1. Two Sum](https://leetcode.com/problems/two-sum/) **Easy** 20190129 |
|:---|
| 给出数组和target，从数组中找出2个数之和等于target，保证只有一组解 |
| A 用一个map记录每个数字的位置，扫一遍数组，对每个数字a若target-a的count不为0即为解。解决重复问题：若遇到重复，则把key加上一个固定的大数，保证在map中重复的数字有不同pos。不用multimap原因：麻烦。 |

`better solution` unordered_map
```C++
unordered_map<int, size_t> m;
m.reserve(nums.size());
for (size_t i = 0; i < nums.size(); ++i) {
    m[nums[i]] = i;
}
for (size_t i = 0; i < nums.size(); ++i) {
    auto it = m.find(target - nums[i]);
    if (it != m.end() && it->second != i) {
        return {i, it->second};
    }
}
return {};
```

#### array-1-star

| [\*283. Move Zeroes](https://leetcode.com/problems/move-zeroes/) **Easy** 20190131 |
|:---|
| 将数组中的0全部挪到最后面，其他元素相对位置不变，要求 in-place 处理 |
| A 双指针处理，i 扫描数组，j 为当前非0元素位置，最后补0 |

| [\*665. Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/) **Easy** 20190129 |
|:---|
| 输入数组，是否能改动最多1个元素使之为非递减数组 |
| A 讨论清楚多种边界条件 |

---

## String

#### string-水题

| [709. To Lower Case](https://leetcode.com/problems/to-lower-case/) **Easy** 20190129 |
|:---|
| 水题 将输入转为小写 |

| [771. Jewels and Stones](https://leetcode.com/problems/non-decreasing-array/) **Easy** 20190129 |
|:---|
| 水题 leetcode 通过率最高的题目。两个字符串 J 和 S，J 字母保证distinct，问 S 中包含 J 中字母的个数 |
| A 对 J 和 S 排序后扫一遍，复杂度 O(NlogN) |

| [804. Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/) **Easy** 20190208 |
|:---|
| 水题 给出摩斯码表，输入一个字符串列表，求对应的不同摩斯码的个数 |

| [929. Unique Email Addresses](https://leetcode.com/problems/unique-email-addresses/) **Easy** 20190129 |
|:---|
| 水题 给定一个 email 列表和一些特殊符号规则，问共有多少个不同email |

#### string-0-star

| [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) **Medium** 20190130 |
|:---|
| 输入字符串，输出最长子串长度，子串由不同字符组成 |
| A 暴力求解，hash 表记录每个字母最后一次出现的位置用于更新搜索起始位置 |

| [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) **Medium** 20190130 |
|:---|
| 求字符串的最长回文子串 |
| A 暴力求解，遍历中心字符，分别求奇数和偶数长度的最长回文子串，复杂度 O(n^2) |

| [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) **Medium** 20190208 |
|:---|
| 输入 n，输出 n 对括号所有合法的组合方式，即每个左括号都有右括号对应（可嵌套） |
| A 这题做得很开心，递归求每个位置是哪个括号，字符串的任意前缀要满足num(左括号) >= num(右括号) |

---

## Tree

#### tree-水题

| [100. Same Tree](https://leetcode.com/problems/same-tree/) **Easy** 20190131 |
|:---|
| 水题 判断两棵二叉树是否一样 |

| [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) **Easy** 20190130 |
|:---|
| 水题 求二叉树的最大深度 |

| [107. Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) **Easy** 20190203 |
|:---|
| 按层遍历二叉树，每层节点一个 vector，自下而上遍历 |
| A 按顺序遍历完以后 reverse 结果 |

| [226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) **Easy** 20190131 |
|:---|
| 水题 翻转二叉树 |

| [404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/) **Easy** 20190203 |
|:---|
| 水题 求二叉树所有左叶子之和 |

| [513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/) **Medium** 20190206 |
|:---|
| 水题 求二叉树最下面一层的最左边的叶子 |

| [515. Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/) **Medium** 20190206 |
|:---|
| 水题 求二叉树每层节点的最大值 |

| [559. Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/) **Easy** 20190131 |
|:---|
| 水题 N叉树的最大深度 |

| [617. Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/) **Easy** 20190130 |
|:---|
| 水题 输入两棵二叉树，求对应相同位置节点相加后的新二叉树 |

| [700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/) **Easy** 20190131 |
|:---|
| 水题 BST 搜索元素 |

| [701. Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/) **Medium** 20190131 |
|:---|
| 水题 BST 插入元素 |

| [965. Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree/) **Easy** 20190131 |
|:---|
| 水题 判断二叉树所有节点是否同一个值 |

#### tree-0-star

| [110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) **Easy** 20190203 |
|:---|
| 判断二叉树是否height-balanced，定义为任意节点其两个子树的高度之差<=1 |
| A 递归求各节点左右子树高度，若高度差>1返回 false |

| [111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/) **Easy** 20190203 |
|:---|
| 二叉树的最小深度，定义为根节点到所有叶子中的最短路径长度 |
| A 按层遍历，遇到第一个叶子即为最短路径的叶子 |

| [112. Path Sum](https://leetcode.com/problems/path-sum/) **Easy** 20190204 |
|:---|
| 二叉树从根节点到叶子的所有 path 中，是否存在 path 经过节点之和等于给定 target |
| A 遍历所有 path，若满足条件则尽快返回 |

`cleaner solution`
```C++
if(!root) return false;
if(root&&root->val==sum&&!root->left&&!root->right) return true;
return hasPathSum(root->left, sum-root->val)||hasPathSum(root->right, sum-root->val);
```

| [144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) **Medium** 20190203 |
|:---|
| 先序遍历二叉树，要求非递归 |
| A 非递归遍历二叉树，先序最简单，按照递归顺序入栈 |

| [429. N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/) **Easy** 20190203 |
|:---|
| N叉树按层遍历节点，每层节点用一个 vector 存放，返回结果为`vector<vector<int>>` |
| A 关键问题是如何区分入队的节点分属哪一层，解决办法是记录每层节点数(等于每层迭代前的队列长度)，for 循环 pop 出来的节点即为同一层 |

| [508. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/) **Medium** 20190208 |
|:---|
| 二叉树的子树之和定义为子树上所有节点之和(包括根节点)，求所有子树和中出现频率最高的值，若频率相等输出所有值 |
| A 递归求出所有子树和，再用一个 map 求出频率高的子树和 |

`tricky solution` 一次循环同时完成求最高频率和对应子树和
```C++
int max_count = 0;
for (auto &p : m) {
    if (p.second == max_count) v.push_back(p.first);
    else if (p.second > max_count) {
        v.clear();
        v.push_back(p.first);
        max_count = p.second;
    }
}
return v;
```

| [538. Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/) **Easy** 20190203 |
|:---|
| 输入 BST，修改每个节点，使之加上所有大于它的节点值之和 |
| A 初始化累加值为 BST 右下角节点值(最大值)，递归处理右子树后，累加值累加到根节点，更新累加值，再递归处理左子树 |

| [563. Binary Tree Tilt](https://leetcode.com/problems/binary-tree-tilt/) **Easy** 20190203 |
|:---|
| 二叉树每个节点的 tilt 定义为abs(sum(左子树节点),sum(右子树节点))，求所有节点 tilt 之和 |
| A 递归求解左右子树之和，累加绝对值，返回子树与根节点之和 |

| [572. Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) **Easy** 20190204 |
|:---|
| 给定两个二叉树 s 和 t，判断 t 是否为 s 的一个子树 |
| A 遍历 s 的节点 x，判断x 和 t 是否相等 |

| [589. N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/) **Easy** 20190131 |
|:---|
| N叉树的先序遍历，要求非递归 |
| A 按照递归顺序入栈，children 用`vector<Node*>::reverse_iterator`迭代器遍历 |

| [606. Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/) **Easy** 20190203 |
|:---|
| 将二叉树转化为字符串，用括号代表连接关系，即root(left)(right)，空节点用()表示 |
| A 模拟题，分别讨论左右子树是否为空的情况 |

| [637. Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/) **Easy** 20190203 |
|:---|
| 二叉树每层节点的平均值 |
| A 与429类似，关键是区分出每层节点 |

| [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) **Easy** 20190203 |
|:---|
| BST 中是否存在两个数，相加之和为给定值 target |
| A 遍历 BST 节点 x，查找是否存在 target-x |

| [654. Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/) **Medium** 20190131 |
|:---|
| 输入无重复元素的数组，根据规则输出二叉树：一、数组最大元素为根节点；二、最大元素左侧元素递归构造左子树，同理递归构造右子树 |
| A 按照定义递归构造 |

| [814. Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/) **Medium** 20190131 |
|:---|
| 由0和1组成的二叉树，删除所有不包含1的子树 |
| A 先递归删除左右子树，若删除后左右子树为空，且根节点为0则删除根节点 |

| [872. Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/) **Easy** 20190201 |
|:---|
| 二叉树的所有叶子从左到右组成一个leaf value sequence，判断两颗二叉树它们的叶子序列是否相等 |
| A 暴力，求出各自叶子序列后判断 |

| [919. Complete Binary Tree Inserter](https://leetcode.com/problems/complete-binary-tree-inserter/) **Medium** 20190206 |
|:---|
| 完全二叉树的插入元素实现 |
| A 先求出完全二叉树的节点个数n，每个节点从上到下从左到右依次编号0 - (n-1)，则插入元素为编号 n，其父节点编号为(n-1)/2 |

| [951. Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees/) **Medium** 20190206 |
|:---|
| 给定两个二叉树root1 root2，判断root1是否能通过若干次节点的子树翻转变成 root2 |
| A 递归判断两种情况：左右子树没有翻转是否相等；左右子树翻转后是否相等 |

#### tree-1-star

| [\*94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) **Medium** 20190206 |
|:---|
| 二叉树中序遍历，要求非递归 |
| A 根节点若有左节点，则先压入根节点，当前节点变为左节点；否则输出根节点，当前节点变为右节点。关键点：维护一个 `from_stack`布尔变量判断当前节点是否从栈弹出，若是则不能重复进行左子树处理 |

`better solution` 需要压入栈的都是有左子树的节点
```C++
TreeNode* curr = root;
while (curr != NULL || !s.empty()) {
    while (curr != NULL) {
        s.push(curr);
        curr = curr->left;
    }
    curr = s.pop();
    ans.push_back(curr->val);
    curr = curr->right;
}
return ans;
```

| [\*590. N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal) **Easy** 20190131 |
|:---|
| N叉树的后序遍历，要求非递归 |
| A 根据访问顺序倒序放入栈，`unordered_set<Node*> visited` 记录已展开children的节点 |

`tricky solution`
```C++
s.push(root);
while(!s.empty()){
    Node * node = s.top(); s.pop();
    result.push_back(node->val);
    for(Node* child : node->children){
        s.push(child);
    }
}
reverse(result.begin(),result.end());
```

| [\*687. Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/) **Easy** 20190201 |
|:---|
| 二叉树任意两节点之间构成一个 path，求最长 path 满足经过的所有节点值相等 |
| A `map<TreeNode*, int> lLongestLen, rLongestLen`分别记录每个节点的左/右子树最大长度(包含此节点本身)，递归左右节点后，分别求出根节点到左右子树最大长度，若根==左==右则更新最大长度。 |

`cleaner solution`
```C++
int arrowLength(TreeNode* node) {
    if (node == NULL) return 0;
    int left = arrowLength(node->left)
    int right = arrowLength(node->right);
    int arrowLeft = 0, arrowRight = 0;
    if (node->left != NULL && node->left->val == node->val) {
        arrowLeft += left + 1;
    }
    if (node->right != NULL && node->right->val == node->val) {
        arrowRight += right + 1;
    }
    ans = max(ans, arrowLeft + arrowRight);
    return max(arrowLeft, arrowRight);
}
```

| [\*865. Smallest Subtree with all the Deepest Nodes](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/) **Medium** 20190207 |
|:---|
| 求二叉树的最小子树，使之包含所有最大深度的叶子 |
| A 暴力 先求出数的深度 n，再求出所有符合要求的路径存放到数组 paths，扫描 paths 求出最近祖先 |

`better solution` 先求出所有最大深度的叶子，递归求解答案：若 node 为最大深度叶子返回 node；递归求解左右子树答案 L R，若L R 均不为空则返回 node；否则返回非空一边子树的答案
```C++
map<TreeNode*, int> depth;
int max_depth;
void dfs(TreeNode* node, TreeNode* parent) {
    if (node) {
        depth[node] = depth[parent] + 1;
        max_depth = max(depth[node], max_depth);
        dfs(node->left, node);
        dfs(node->right, node);
    }
}

TreeNode* answer(TreeNode* node) {
    if (node == NULL || depth[node] == max_depth) return node;
    TreeNode* L = answer(node->left);
    TreeNode* R = answer(node->right);
    if (L && R) return node;
    if (L) return L;
    if (R) return R;
    return NULL;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    depth[NULL] = -1;
    max_depth = -1;
    dfs(root, NULL);
    return answer(root);
}
```

| [\*889. Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) **Medium** 20190206 |
|:---|
| 输入二叉树的先序遍历和后序遍历，构造出其中一个可能的二叉树 |
| A 先序遍历的第一个元素和后序遍历的最后一个元素必须相等，为根节点，然后递归划分左右子树时，只需满足根节点规则（实践证明不需要再次判断左(右)子树的先序/后序元素集合是否一致） |

| [\*979. Distribute Coins in Binary Tree](https://leetcode.com/problems/distribute-coins-in-binary-tree/) **Medium** 20190206 |
|:---|
| 二叉树每个节点上有一些金币，树上一共有 N 个金币(二叉树节点数)，相邻节点之间可任意方向移动金币，问最小移动金币数，使得每个节点上恰好有1个金币 |
| A 从叶子开始递归，每个节点需要移动的金币数为[当前节点的金币数]与1的绝对值，当前节点金币数若为负表示需要流入金币，每个节点返回`root->val + x + y - 1`即为流入到其父节点的金币数 |

#### tree-2-star

| [\*\*236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) **Medium** 20190218 |
|:---|
| 最近公共祖先 LCA |
| A 递归每次状态(root, p, q)表示 root 为根节点的子树下，包含 p 或 q 的最近祖先，若左右子树均非空则返回 root；否则返回非空的子树结果。 |

`solution`
```C++
if (root == NULL || root == p || root == q) return root;
TreeNode* left = lowestCommonAncestor(root->left, p, q);
TreeNode* right = lowestCommonAncestor(root->right, p, q);
if (left && right) return root;
else if (left) return left;
else if (right) return right;
return NULL;
```

---

## Linked List

#### linkedlist-水题

| [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) **Medium** 20190129 |
|:---|
| 水题 两个用链表表示的数相加，返回链表 |

---

## misc

#### misc-水题

| [136. Single Number](https://leetcode.com/problems/single-number/) **Easy** 20190131 |
|:---|
| 水题 给定一个数组，只有1个元素出现了1次，其他元素恰好出现了2次，求那个出现1次的元素 |
| A ans ^= nums[i]; |

| [195. Tenth Line](https://leetcode.com/problems/tenth-line/) **Easy** 20190129 |
|:---|
| 水题 [Shell]输出文件的第10行 |
| A 先wc 判断文件是否有10行 |

| [461. Hamming Distance](https://leetcode.com/problems/hamming-distance/) **Easy** 20190130 |
|:---|
| 水题 求汉明距离 |

#### misc-0-star

| [46. Permutations](https://leetcode.com/problems/permutations/) **Medium** 20190209 |
|:---|
| 输入没有重复元素的数组，输出数组的全排列 |
| A 维护一个status 状态变量，用位图表示用过的元素 |

| [338. Counting Bits](https://leetcode.com/problems/counting-bits/) **Medium** 20190130 |
|:---|
| 输入 num，输出0<=i<=num范围每个 i 的二进制中1的个数，要求时间复杂度和空间复杂度均为 O(n) |
| A 打表法，先求出0 - 255(1byte)每个数中1的个数，再遍历 i，每个 i 最多查表4次(4byte)相加即为结果 |

`tricky solution`
```C++
for (int i = 1; i <= num; ++i)
    ret[i] = ret[i&(i-1)] + 1; // i&(i-1) 去掉 i 的最后一个1
return ret;
```

#### misc-1-star

| [\*406. Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/) **Medium** 20190131 |
|:---|
| 由(h, k)组成的数组，h 表示高度为 h 的人，k 表示在他前面的高度>=h的人数，要求重新排列数组 |
| A 贪心法，每次确定当前最矮的那个人的位置，若相同高度优先确定 k 较小的人的位置 |
