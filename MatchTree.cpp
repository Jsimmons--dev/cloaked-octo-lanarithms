#include "MatchTree.hpp"
#include "MatchTreeNode.hpp"

using namespace std;
MatchTree::MatchTree(int initX, int initY, char thisc, char nextc){
    root = new MatchTreeNode(initX, initY, thisc, nextc, leaves);
}

vector<MatchTreeNode*> MatchTree::getLeaves()
{
    return leaves;
}

MatchTreeNode* MatchTree::getRoot(){
    return root;
}
