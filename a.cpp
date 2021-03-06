#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// recursive inorder BST traversal
// 1st right then current node then left
void transformBST(TreeNode* node,int& sum) {
    if (node == nullptr) return;
    transformBST(node->right,sum);
    sum += node->val;
    node->val = sum ;
    transformBST(node->left,sum);
}
TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    transformBST(root,sum);
    return root;
}
int numberOfSteps(int num){
    int res = 0;
    while (num != 0) {
        if (num == 1){
            res++;
            std::cout << res << '\n';
            return res;
        }
        if(num%2 == 0) {
            res++;
            num = num/2;
        }else{
            res++;
            num--;
        }

    }
    return res;
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int N = grid.size();
    if (grid[0][0] or grid[N-1][N-1]) return -1;
    vector<pair<int, int>> coordinate = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    queue<pair<int,int>> q;
    q.push({0, 0});
    grid[0][0] = 1;
    int res = 0;
    while (!q.empty()) {
        res++;
        for (int i = q.size(); i > 0; i--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == N-1 and y == N-1) return res;
            for (auto i = 0; i < coordinate.size(); ++i) {
                int a = coordinate[i].first;
                int b = coordinate[i].second;
                if (x + a >= 0 and x + a < N and y + b >= 0 and y + b < N and !grid[x + a][y + b]) {
                    // label as discovered
                    grid[x + a][y + b] = 1;
                    q.push({x + a, y + b});
                }
            }
        }
    }
    return -1;
}
bool dfs(vector<vector<int>>& graph, vector<int>& colors, int i){
    for (int neighbor : graph[i])
    {
        if (!colors[neighbor]) //unvisited
        {
            colors[neighbor] = -(colors[i]);
            //continue traverse
            if (!dfs(graph, colors, neighbor)) return false;
        }
        else if(colors[neighbor] == colors[i]) // same color
        {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph){
   int n = graph.size();
   vector<int> colors(n, 0);
   for (int i = 0; i < n; i++)
   {
       if (!colors[i] )
       {
           colors[i]=1;
           if (!dfs(graph, colors, i)) return false;
       }
   }
   return true;
}
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int, int>>  mapID;// key is id ,value is sum
    for (int i = 0; i < mat.size(); i++){
        int sum = 0;
        for (int j = 0; j < mat[i].size(); j++){
            sum += mat[i][j];
        }
        mapID.push_back(make_pair(i,sum));
    }
    sort(mapID.begin(), mapID.end());
       vector<int> res;
       for (int i = 0; i<k; i++){
           res.push_back(mapID[i].second);
       }
       return res;
    return res;
}
void dfs2(string S, vector<string> &ans, int i, int len) {
    if (i < len) {
        dfs2(S, ans, i+1, len);
        if (isalpha(S[i])) {
            S[i] = toupper(S[i]);
            dfs2(S, ans, i+1, len);
        }
    } else ans.push_back(S);
}
vector<string> letterCasePermutation(string S) {
    for (int i = 0; i < S.size(); i++)
        S[i] = tolower(S[i]);
    vector<string> ans;
    dfs2(S, ans, 0, S.size());
    return ans;
}
int bruteforcemaxArea(vector<int>& height) {
    int n = height.size();
    int res = 0;
    for (int i = 0; i < n ; i++){
        for (size_t j = i+1; j < n; j++) {
            res = max(res,abs(int(i-j))*min(height[i],height[j]));
        }
    }
    return res;
}
int maxArea(vector<int>& height) {
    int start = 0;
    int end = height.size()-1;
    int res = 0;
    while(start < end){
        res = max(res,abs(int(start-end))*min(height[start],height[end]));

        if (height[start] < height[end]){
            start++;
        }
        else end--;
    }
    return res;
}
int numberOfArithmeticSlices(vector<int>& A) {
    int count = 0, ans = 0, diff = 999999999;
    for (int i = 1; i < A.size(); i++) {
        int newDiff = A[i] - A[i-1];
        if (newDiff == diff) ans += count++;
        else {
            diff = newDiff;
            count = 1;
        }
    }
    return ans;
}
int brokenCalc(int X, int Y) {
    if(X>=Y) return X -Y ;
    if(X < Y and Y%2 == 0){
        return 1 + brokenCalc(X, Y/2);
    }
    return 1 + brokenCalc(X, Y+1);
}
int main(void) {
    int ans;
    std::vector<int> v;
    v.push_back(1);v.push_back(2);v.push_back(3);v.push_back(4);
    ans = numberOfArithmeticSlices(v);
        std::cout << ans << '\n';
    v.push_back(5);v.push_back(6);v.push_back(7);
    ans = numberOfArithmeticSlices(v);
    std::cout << ans << '\n';
    return 0;
}
