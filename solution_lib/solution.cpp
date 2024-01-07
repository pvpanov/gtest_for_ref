//
// Created by ppv on 1/7/2024.
//
#include <vector>
#include <deque>
#include <iostream>
#include <list>
#include <tuple>

struct TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { std::cout << "ha!"; }
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
private:
};

class Tree {
public:
    explicit Tree(TreeNode* root): root(root) { };
    explicit Tree(const std::vector<int>& elems) {
        auto iter = elems.begin();
        if(iter == elems.end()) {
            this->root = nullptr;
        } else {
            this->root = new TreeNode(*iter);
            auto free_last  = std::deque<TreeNode*> {root};
            auto free_next  = std::deque<TreeNode*> ();
            while(++iter != elems.end()) {
                if(free_last.empty()) {
                    free_last = free_next;
                    free_next = std::deque<TreeNode*> ();
                }
                auto node = free_last.front();
                auto new_node = new TreeNode(*iter);
                if (node -> left == nullptr) {
                    node->left = new_node;

                } else if (node -> right == nullptr){
                    node->right = new_node;
                    free_last.pop_front();
                }
                free_next.push_back(new_node);
            }
        }
    }
    std::vector<int>* preorder() {
        auto result = new std::vector<int>();
        auto nodes = std::deque<TreeNode*>{this->root};
        while(!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop_front();
            if (node == nullptr) {
                continue;
            }
            result->emplace_back(node->val);
            nodes.push_back(node->left);
            nodes.push_back(node->right);
        }
        return result;
    }

    TreeNode* get_root() {
        return this->root;
    }

private:
    TreeNode *root;
};

class Solution {
public:
    static int countNodes(TreeNode* root) {
        auto tree = Tree(root);
        auto result = int(tree.preorder()->size());
        return result;
    }
    static int countFromArr(const std::vector<int>& arr) {
        auto tree = Tree(arr);
        return countNodes(tree.get_root());
    }
};

template <typename T>
concept Iterable = requires(T t) {
{ begin(t) } -> std::input_or_output_iterator;
{ end(t) } -> std::input_or_output_iterator;
};

template <Iterable T>
void printIterable(const T& iterable) {
    for (const auto& element : iterable) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}
