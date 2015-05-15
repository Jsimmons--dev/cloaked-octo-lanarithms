#include "MatchTreeNode.hpp"


using namespace std;
MatchTreeNode::MatchTreeNode(int initX, int initY, int kwi, char thisc, char nextc, vector<MatchTreeNode*> leaves)
{
    x = initX;
    y = initY;
    keywordIndex = kwi;
    thisChar = thisc;
    nextChar = nextc;
    leaves.push_back(this);
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

bool MatchTreeNode::equals(MatchTreeNode* other)
{
    bool thisSame;
    if(x==other->getX()&&y==other->getY())
    {
        thisSame = true;
    }
    else
    {
        thisSame = false;
    }
    //thisSame = x == other->x && y == other->y;
    bool result = true;
    if(children.size() != other->getChildren().size()) return false;
    vector<bool> results(children.size());
    int i = 0;
    for(int i = 0;i<children.size();i++)
    {
        results[i] = getChild(i)->equals(other->getChild(i));
    }
    for(int i = 0; i<results.size();i++) result = result && results[i];
    return thisSame && result;
}

int MatchTreeNode::getX()
{
return x;
}

int MatchTreeNode::getY()
{
return y;
}

int MatchTreeNode::getKeywordIndex()
{
return keywordIndex;
}

char MatchTreeNode::getChar() {
  return thisChar;
}

char MatchTreeNode::getNextChar() {
  return nextChar;
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
    cout << thisChar << " at (" << x << "," << y <<  ") "  << " next: " << nextChar << endl;
}
