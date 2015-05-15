#ifndef MATCHTREENODE_H
#define MATCHTREENODE_H
#include <vector>
#include <array>
#include <iostream>



class MatchTreeNode {
    int x;
    int y;
    char thisChar;
    char nextChar;
    std::vector<MatchTreeNode*> parents;
    std::vector<MatchTreeNode*> children;
    public:
        MatchTreeNode(int,int, char, char, std::vector<MatchTreeNode*>);
        std::vector<MatchTreeNode*> getParents();
        std::vector<MatchTreeNode*> getChildren();
        MatchTreeNode* getChild(int);
        MatchTreeNode* addChild(MatchTreeNode*);
        bool equals(MatchTreeNode*);
        int getX();
        int getY();
        char getChar();
        char getNextChar();
        void printChildren();
        void printParents();
        void printNode();
};






#endif /*MATCHTREENODE_H*/
