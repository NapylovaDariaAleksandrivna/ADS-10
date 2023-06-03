// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <vector>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    return tree.func(n - 1);
}
