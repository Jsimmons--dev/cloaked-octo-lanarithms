#include <iostream>
#include <fstream>
#include <string>
#include <gtest/gtest.h>
#include <vector>
#include "MatchTreeNode.hpp"
using namespace std;

//TEST(VertiWordTest, SingleInput) {
//	string solString = "";
//	string line;
//	ifstream solFile ("testFiles/test1_sol.txt");
//	while (getline(solFile, line)) {
//		solString += line;
//	}
//	EXPECT_EQ(solString, vertiSolve("testFiles/test1.txt"));
//}
//
//TEST(VertiWordTest, MultiInput) {
//	string solString = "";
//	string line;
//	ifstream solFile ("testFiles/test2_sol.txt");
//	while (getline(solFile, line)) {
//		solString += line;
//	}
//	EXPECT_EQ(solString, vertiSolve("testFiles/test2.txt"));
//}
TEST(VertiWordTest,MatchTreePlaceNFind)
{
    MatchTreeNode node = MatchTreeNode(1,5);
    MatchTreeNode  nodeC = MatchTreeNode(2,6);
    node.addChild(&nodeC);
    EXPECT_EQ(2,node.getChild(0)->getX());
    EXPECT_EQ(6,node.getChild(0)->getY());
    MatchTreeNode nodeC2  = MatchTreeNode(2,5);
    node.addChild(&nodeC2);
    MatchTreeNode nodeCC = MatchTreeNode(3,1);
    node.getChild(0)->addChild(&nodeCC);

    //node.getChild(0)->printChildren();
    EXPECT_EQ(2,node.getChild(1)->getX());
    EXPECT_EQ(3,nodeC.getChild(0)->getX());
    MatchTreeNode* childOfNode = node.getChild(0);
    EXPECT_EQ(3,childOfNode->getChild(0)->getX());
    EXPECT_EQ(1,node.getChild(0)->getChild(0)->getY());
}

TEST(VertWordTest,testBasicMatchTree)
{
    
}
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
