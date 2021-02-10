#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// stolen from internet https://en.wikipedia.org/wiki/Hamming_weight
// hamming weight problem
int hammingWeight(uint32_t x) {
  x = x - ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x + (x >> 4)) & 0x0F0F0F0F;
  x = x + (x >> 8);
  x = x + (x >> 16);
  return x & 0x0000003F;
}
//-------------------
//Definition for a binary tree node.
// trimBST problem
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* trimBST(TreeNode* R, int L, int H) {
  if (!R) return R;
  if (R->val < L) return trimBST(R->right,L,H);
  else if (R->val > H) return trimBST(R->left,L,H);
  R->left = trimBST(R->left,L,H) ;
  R->right = trimBST(R->right,L,H);
  return R;
}
//-------------------
//linked Cycle list
// https://en.wikipedia.org/wiki/Cycle_detection
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
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
//-------------------
//  Longest Harmonious Subsequence
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
//-------------------
std::string simplifyPath(std::string path) {
    // using vector in place of stack
    vector<string> v;
    int n = path.length();
    string ans;
    for (int i = 0; i < n; i++) {
        string dir = "";
        // forming the current directory.
        while (i < n && path[i] != '/') {
            dir += path[i];
            i++;
        }

        // if ".." , we pop.
        if (dir == "..") {
            if (!v.empty())
                v.pop_back();
        }
        else if (dir == "." || dir == "") {
            // do nothing (added for better understanding.)
        }
        else {
            // push the current directory into the vector.
            v.push_back(dir);
        }
    }

    // forming the ans
    for (auto i : v) {
        ans += "/" + i;
    }

    // vector is empty
    if (ans == "")
        return "/";

    return ans;
}
//-------------------
vector<int> rightSideView(TreeNode* root) {
    std::vector<int> res;
    queue<TreeNode*> q;
    if(!root) return res;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (size_t i = 1; i <= n; i++) {
            TreeNode* temp = q.front();
            q.pop();
            if (i == n) res.push_back(temp->val);
            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }
    }
    return res;
}
//-------------------
vector<int> shortestToChar(string s, char c) {
    std::vector<int> res;
    res.resize(s.length());
    int prev = -99999999;

    for (int i = 0; i < s.length(); i++){
        if (s.at(i) == c) prev = i;
        res[i] = abs(i-prev);
    }
    prev = 9999999;
   for (int i = s.length()-1; i >= 0; i--) {
       if (s.at(i) == c) {
           prev = i;
       }
       // get the smaller one of the two answers
       res[i] = min(res[i], prev - i);
   }
   return res;
}
//-------------------
class Iterator {
		struct Data;
 		Data* data;
		Iterator(const vector<int>& nums);
 		Iterator(const Iterator& iter);

 		// Returns the next element in the iteration.
		int next();

		// Returns true if the iteration has more elements.
		bool hasNext() const;
	};
    class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {

	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {

	}

	bool hasNext() const {

	}
};
int main(){


}
