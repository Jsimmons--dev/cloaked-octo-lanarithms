#include <iostream>
#include <fstream>
#include <string>
#include <gtest/gtest.h>
#include <vector>
#include "MatchTreeNode.hpp"
#include "MatchTree.hpp"

using namespace std;
TEST(VertiWordTest,MatchTreePlaceNFind)
{
    char c  = 'c';
    MatchTree tree = MatchTree(1,5,c,c);
    MatchTreeNode* node = tree.getRoot();
    MatchTreeNode  nodeC = MatchTreeNode(2,6,c,c,tree.getLeaves());
    node->addChild(&nodeC);
    MatchTreeNode nodeC2  = MatchTreeNode(2,5,c,c,tree.getLeaves());
    node->addChild(&nodeC2);
    MatchTreeNode nodeCC = MatchTreeNode(3,1,c,c,tree.getLeaves());
    node->getChild(0)->addChild(&nodeCC);
    MatchTreeNode* childOfNode = node->getChild(0);

    EXPECT_EQ(2,node->getChild(0)->getX());
    EXPECT_EQ(6,node->getChild(0)->getY());
    EXPECT_EQ(2,node->getChild(1)->getX());
    EXPECT_EQ(3,nodeC.getChild(0)->getX());
    EXPECT_EQ(3,childOfNode->getChild(0)->getX());
    EXPECT_EQ(1,node->getChild(0)->getChild(0)->getY());
}

TEST(VertiWordTest,testBasicMatchtree)
{
    char c  = 'c';
    MatchTree tree = MatchTree(2,5,c,c);
    MatchTreeNode* node = tree.getRoot();
    MatchTreeNode nodeOther = MatchTreeNode(2,6,c,c,tree.getLeaves());

    EXPECT_EQ(false,node->equals(&nodeOther));

    MatchTreeNode nodeSame = MatchTreeNode(2,5,c,c,tree.getLeaves());

    EXPECT_EQ(true,node->equals(&nodeSame));

    MatchTree tree1 = MatchTree(2,5,c,c);
    MatchTreeNode* root1 = tree1.getRoot();
    MatchTreeNode child1_1 = MatchTreeNode(3,4,c,c,tree1.getLeaves());
    root1->addChild(&child1_1);

    MatchTree tree2 = MatchTree(2,5,c,c);
    MatchTreeNode* root2 = tree2.getRoot();
    MatchTreeNode child2_1 = MatchTreeNode(3,4,c,c,tree2.getLeaves());
    root2->addChild(&child2_1);

    MatchTree tree3 = MatchTree(2,5,c,c);
    MatchTreeNode* root3 = tree3.getRoot();
    MatchTreeNode child3_1 = MatchTreeNode(3,5,c,c,tree3.getLeaves());
    root3->addChild(&child3_1);

    EXPECT_EQ(true, root1->equals(root2)) << "trees should be equal with eql vals";
    EXPECT_EQ(true,root2->equals(root1)) << "equals should be the same both ways";
    EXPECT_EQ(false,root1->equals(root3));

    MatchTreeNode child2_2 = MatchTreeNode(4,5,c,c,tree2.getLeaves());
    root2->addChild(&child2_2);

    EXPECT_EQ(false,root1->equals(root2));

}

TEST(VertiWordTest,extractMatch)
{
    char c  = 'c';

    MatchTree tree = MatchTree(0,0,c,c);
    MatchTreeNode* rootSol = tree.getRoot();
    MatchTreeNode child1 = MatchTreeNode(1,0,c,c,tree.getLeaves());
    MatchTreeNode child1_1 = MatchTreeNode(2,0,c,c,tree.getLeaves());

    rootSol->addChild(&child1);
    child1.addChild(&child1_1);

//    string rows[20];
//    readIn(rows);
//    vector<vector< string > > problems = extractProblems(rows);
//    vector<MatchTreeNode*> matches = extractMatches(problems[0]);
//    MatchTreeNode* firstMatch = matches[0];
//
//    EXPECT_EQ(true,rootSol.equals(firstMatch));
}
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
