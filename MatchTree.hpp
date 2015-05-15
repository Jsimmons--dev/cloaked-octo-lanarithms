#ifndef MATCHTREE_H
#define MATCHTREE_H
#include <vector>
#include <array>
#include <iostream>
#include "MatchTreeNode.hpp"

class  MatchTree {
    std::vector<MatchTreeNode*> leaves;
    MatchTreeNode* root;
  public:
    MatchTree(int,int,char,char);
    std::vector<MatchTreeNode*> getLeaves();
    MatchTreeNode* getRoot();
};



#endif /*MATCHTREE_H*/
