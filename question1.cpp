# hw_1121756
//層次遍歷 左到右的順序處理(先進先出使用隊列)
//創立root 1 i=0
//[1]加入對列
//取出 節點(val)1
//創立nodes 2(左子節點)i=1  3 (右子節點)i=2
//[2,3]

//取出2
//創立nodes 4(i=3) 5(i=4)
//[3,4,5]

//取出3
//創立nodes  -1(i=5) -1(i=6)跳過左右邊子節點
//[4,5]

//取出4
//創立nodes  -1(i=7) -1(i=8)跳過左右邊子節點
//[5]
//取出5
//創立nodes 6(i=9) 7(i=10)
//[6,7]
//取出6 7
//i=11 i<v.size()=11

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build the binary tree using level-order input
TreeNode* buildTree(const vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (levelOrder[i] != -1) {
            current->left = new TreeNode(levelOrder[i]);
            q.push(current->left);
        }
        i++;

        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->right = new TreeNode(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to calculate the diameter of the tree
int calculateDiameter(TreeNode* root, int& diameter) {
    if (!root) return 0;

    int leftHeight = calculateDiameter(root->left, diameter);
    int rightHeight = calculateDiameter(root->right, diameter);

    // Update the diameter at each node
    diameter = max(diameter, leftHeight + rightHeight + 1); // Include the current node

    // Return the height of the current node
    return max(leftHeight, rightHeight) + 1;
}

// Main function to calculate the diameter
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}

int main() {
    // Input
    string input;
    cout << "Enter level-order traversal of the binary tree (-1 for null nodes): ";
    getline(cin, input);
    stringstream ss(input);
    vector<int> levelOrder;
    int num;
    while (ss >> num) {
        levelOrder.push_back(num);
    }

    // Build the tree
    TreeNode* root = buildTree(levelOrder);

    // Calculate and print the diameter
    cout << "Diameter of the binary tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
