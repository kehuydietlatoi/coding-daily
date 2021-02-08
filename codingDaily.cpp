#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
int hammingWeight(uint32_t x) {
  x = x - ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x + (x >> 4)) & 0x0F0F0F0F;
  x = x + (x >> 8);
  x = x + (x >> 16);
  return x & 0x0000003F;
}

 //Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
int findLHS(std::vector<int>& nums) {
     std::unordered_map<int, int> m;
  for (const int n : nums)
     ++m[n];
  int max_ = 0;
  for (const auto & i : m) {
     auto it = m.find(i.first + 1);
     if (it != m.end())
        max_ = std::max(max_, i.second + it->second);
  }
  return max_;
}
bool hasCycle(ListNode *head) {
ListNode* fast = head;
    ListNode* slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }
    return false;
}
TreeNode* trimBST(TreeNode* R, int L, int H) {
  if (!R) return R;
  if (R->val < L) return trimBST(R->right,L,H);
  else if (R->val > H) return trimBST(R->left,L,H);
  R->left = trimBST(R->left,L,H) ;
  R->right = trimBST(R->right,L,H);
  return R;
}
int main(){
  std::cout << "enter bit" << '\n';
  uint32_t input;
  std::cin >> input;
  std::cout << "Result : "<< hammingWeight(input) << '\n';
}
