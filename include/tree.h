// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>
class Tree {
 private:
    struct Node {
        char symbol;
        std::vector<Node*> descendants;
    };
    Node* root;
    std::vector<std::vector<char>> permutations;
    Node* Create(Node* root, const std::vector<char> permutations) {
        if (!root) {
          root = new Node;
        }
        if (permutations.empty()) {
          return root;
        }
        for (int i = 0; i < permutations.size(); i++) {
            std::vector<char> vect = permutations;
            Node* val = new Node;
            val->symbol = permutations[i];
            root->descendants.push_back(val);
            Create(root->descendants[i], vect);
        }
        return root;
    }
    std::vector<char> Perm(Node* root, std::vector<char>* ch) {
        for (int i = 0; i < root->descendants.size(); i++) {
            ch->push_back(root->descendants[i]->symbol);
            if (root->descendants[i]->descendants.empty()) {
                return *ch;
            }
            Perm(root->descendants[i], ch);
            if (ch->size() != 1) {
                permutations.push_back(*ch);
            }
            for (int j = 0; j < ch->size(); j++) {
                ch->pop_back();
            }
        }
        return *ch;
    }

 public:
  std::vector<char> func(int i) const {
       if (permutations.size() < i) {
         return std::vector<char>();
       }
       return permutations[i];
  }
  explicit Tree(std::vector<char> permutations): root(nullptr) {
    root = Create(root, permutations);
    std::vector<char> ch;
    Perm(root, &ch);
  }
}

#endif  // INCLUDE_TREE_H_
