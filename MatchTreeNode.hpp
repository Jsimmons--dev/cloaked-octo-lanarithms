#ifndef MATCHTREENODE_H
#define MATCHTREENODE_H
#include <vector>
#include <array>
#include <iostream>



class MatchTreeNode {
    int x;
    int y;
    int keywordIndex;
    char thisChar;
    char nextChar;
    MatchTreeNode* parent = NULL;
    std::vector<MatchTreeNode*> children;
    public:
        MatchTreeNode(int,int,int, char, char, std::vector<MatchTreeNode*>*);
        std::vector<MatchTreeNode*> getParents();
        std::vector<MatchTreeNode*> getChildren();
        MatchTreeNode* getChild(int);
        MatchTreeNode* addChild(MatchTreeNode*);
        void setParent(MatchTreeNode*);
        MatchTreeNode* getParent();
        bool equals(MatchTreeNode*);
        int getX();
        int getY();
        int getKeywordIndex();
        char getChar();
        char getNextChar();
        void printChildren();
        void printParents();
        void printNode();
};






#endif /*MATCHTREENODE_H*/
