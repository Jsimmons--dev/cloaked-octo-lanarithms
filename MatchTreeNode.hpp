#ifndef MATCHTREENODE_H
#define MATCHTREENODE_H
#include <vector>
#include <iostream>
using namespace std;
class  MatchTreeNode {
    int x;
    int y;
    vector<MatchTreeNode*> parents;
    vector<MatchTreeNode*> children;
    public:
        MatchTreeNode(int,int);
        vector<MatchTreeNode*> getParents();
        vector<MatchTreeNode*> getChildren();
        MatchTreeNode* getChild(int);
        MatchTreeNode* addChild(MatchTreeNode*);
        int getX();
        int getY();
        void printChildren();
        void printParents();
        void printNode();
};

MatchTreeNode::MatchTreeNode(int initX, int initY)
{
    x = initX;
    y = initY;
}

vector<MatchTreeNode*> MatchTreeNode::getParents()
{
    return parents;
}

vector<MatchTreeNode*> MatchTreeNode::getChildren()
{
    return children;
}
MatchTreeNode* MatchTreeNode::getChild(int index)
{
    return children.at(index);
}

MatchTreeNode* MatchTreeNode::addChild(MatchTreeNode* newNode)
{
  children.push_back(newNode); 
  return newNode;
}

int MatchTreeNode::getX()
{
return x;
}

int MatchTreeNode::getY()
{
return y;
}

void MatchTreeNode::printChildren()
{
    for(int i = 0; i<children.size();i++)
    {
        MatchTreeNode current = *children.at(i);
        cout << "(" << current.getX() << "," << current.getY() << ") ";
    }
    cout << endl;
}

void MatchTreeNode::printParents()
{

}

void MatchTreeNode::printNode()
{
    cout << "(" << x << "," << y << ") " << endl;
}
#endif /*MATCHTREENODE_H*/
