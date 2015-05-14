#include <iostream>
#include <fstream>
#include <string>
#include <gtest/gtest.h>
#include <vector>
#include "MatchTreeNode.hpp"
using namespace std;
TEST(VertiWordTest,MatchTreePlaceNFind)
{
    MatchTreeNode node = MatchTreeNode(1,5);
    MatchTreeNode  nodeC = MatchTreeNode(2,6);
    node.addChild(&nodeC);
    MatchTreeNode nodeC2  = MatchTreeNode(2,5);
    node.addChild(&nodeC2);
    MatchTreeNode nodeCC = MatchTreeNode(3,1);
    node.getChild(0)->addChild(&nodeCC);
    MatchTreeNode* childOfNode = node.getChild(0);
    
    EXPECT_EQ(2,node.getChild(0)->getX());
    EXPECT_EQ(6,node.getChild(0)->getY());
    EXPECT_EQ(2,node.getChild(1)->getX());
    EXPECT_EQ(3,nodeC.getChild(0)->getX());
    EXPECT_EQ(3,childOfNode->getChild(0)->getX());
    EXPECT_EQ(1,node.getChild(0)->getChild(0)->getY());
}

TEST(VertiWordTest,testBasicMatchTree)
{
    MatchTreeNode node = MatchTreeNode(2,5);
    MatchTreeNode nodeOther = MatchTreeNode(2,6);

    EXPECT_EQ(false,node.equals(&nodeOther));

    MatchTreeNode nodeSame = MatchTreeNode(2,5);

    EXPECT_EQ(true,node.equals(&nodeSame));

    MatchTreeNode root1 = MatchTreeNode(1,2);
    MatchTreeNode child1_1 = MatchTreeNode(3,4);
    root1.addChild(&child1_1);

    MatchTreeNode root2 = MatchTreeNode(1,2);
    MatchTreeNode child2_1 = MatchTreeNode(3,4);
    root2.addChild(&child2_1);

    MatchTreeNode root3 = MatchTreeNode(1,2);
    MatchTreeNode child3_1 = MatchTreeNode(3,5);
    root3.addChild(&child3_1);

    EXPECT_EQ(true, root1.equals(&root2)) << "trees should be equal with eql vals";
    EXPECT_EQ(true,root2.equals(&root1)) << "equals should be the same both ways";
    EXPECT_EQ(false,root1.equals(&root3));
    
    MatchTreeNode child2_2 = MatchTreeNode(4,5);
    root2.addChild(&child2_2);

    EXPECT_EQ(false,root1.equals(&root2));

}

TEST(VertiWordTest,extractMatch)
{
    MatchTreeNode rootSol = MatchTreeNode(0,0);
    MatchTreeNode child1 = MatchTreeNode(1,0);
    MatchTreeNode child1_1 = MatchTreeNode(2,0);
    
    rootSol.addChild(&child1);
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
