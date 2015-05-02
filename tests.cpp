#include <iostream>
#include <fstream>
#include <string>
#include "vertiWords.cpp"
#include <gtest/gtest.h>
using namespace std;

TEST(VertiWordTest, SingleInput) {
	string solString = "";
	string line;
	ifstream solFile ("testFiles/test1_sol.txt");
	while (getline(solFile, line)) {
		solString += line;
	}
	EXPECT_EQ(solString, vertiSolve("testFiles/test1.txt"));
}

TEST(VertiWordTest, MultiInput) {
	string solString = "";
	string line;
	ifstream solFile ("testFiles/test2_sol.txt");
	while (getline(solFile, line)) {
		solString += line;
	}
	EXPECT_EQ(solString, vertiSolve("testFiles/test2.txt"));
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
