#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "MatchTree.hpp"
#include "MatchTreeNode.hpp"

#define INPUT_ROWS 20
using namespace std;


void readIn(string (&rows)[INPUT_ROWS])
{
  string current = " ";
  for(size_t i = 0;i<INPUT_ROWS && current.compare("END") != 0; ++i)
  {
    getline(cin,current);
    rows[i] = current;
  }
}

bool ending(vector<string> end)
{
  return (end.at(0).compare("END") == 0) ? true : false;
}

vector<string> solve(vector<string> problem)
{
  for(vector<string>::iterator it = problem.begin(); it != problem.end();++it)
  {
    if(it == problem.begin()) it = problem.erase(it);
    string line = *it;
    if(line.compare("END") == 0) it = problem.erase(it);
    *it = "solved";
  }
  return problem;
}

vector<vector < string > > extractProblems(string (&rows)[INPUT_ROWS])
{
  size_t start = 0;
  vector<vector< string > > problems;
  bool ender = false;
  while(!ender)
  {
    vector<string> problem;
    for(size_t i = start; i < INPUT_ROWS && rows[i] != ""; ++i)
    {
      problem.push_back(rows[i]);
      start++;
    }
    start++;
    problems.push_back(problem);
    ender = ending(problem);
  }
  return problems;
}

void solveProblem(vector<string> &problem)
{
  problem.erase (problem.begin());
  for(vector<string>::iterator it = problem.begin();it != problem.end();++it)
  {
    *it = "solved";
  }
}

void subtract_vector(vector<MatchTreeNode*>* a, const vector<MatchTreeNode*> b)
{
  cout << "0";
  vector<MatchTreeNode*>::iterator       it = a->begin();
  vector<MatchTreeNode*>::const_iterator it2 = b.begin();
  vector<MatchTreeNode*>::iterator       end = a->end();
  vector<MatchTreeNode*>::const_iterator end2 = b.end();
  cout << "1" << endl;
  while (it != end)
  {
    cout << "2" << endl;
    while (it2 != end2)
    {
      cout << "3" << endl;
      if (*it == *it2)
      {
        cout << "4" << endl;
        cout << a->size() << endl;
        it = a->erase(it);
        cout << "5" << endl;
        cout << a->size() << endl;
        end = a->end();
        cout << "6" << endl;
        it2 = b.begin();
      }
      else{
        cout << "7" << endl;
        ++it2;
        cout << "8" << endl;
      }
    }
    cout << "9" << endl;
    ++it;
    cout << "10" << endl;
    it2 = b.begin();
    cout << "11" << endl;
  }
}

vector<MatchTree*> extractMatches(vector<string> &problem)
{
  vector<MatchTree*> matches;
  string keyword = problem[0];
  int itPos = 0;
  for(vector<string>::iterator it = problem.begin()+1; it!=problem.end(); ++it)
  {
    string problemLine = *it;
    for(int i = 0; i<problemLine.length();i++)
    {
      size_t found = keyword.find(problemLine[i]);
      if(found!=string::npos ){
        // cout << "Possible match: " << problemLine[i] << endl;

        if(problemLine[i] == keyword[0])
        {
          int x = itPos;
          int y = i;
          MatchTree* newMatchTree = new MatchTree(x,y, keyword[0], keyword[1]);
          // cout << problemLine[i] << endl;
          matches.push_back(newMatchTree);
        }
        //scan all leaves of all trees for nextChar match with problemLine[i]
        //if match, add child Node to that leaf with thisChar = problemLine[i], nextChar = keyword[leaf.getKeywordIndex + 1]
        //and pop that leaf of leaves vector
        for(int treeIndex = 0; treeIndex < matches.size(); treeIndex++)
        {
          MatchTree* tree = matches[treeIndex];
          vector<MatchTreeNode*>* leaves = tree->getLeaves();
          vector<MatchTreeNode*> newLeaves;
          vector<MatchTreeNode*> oldLeaves;
          for(int leafIndex = 0; leafIndex < leaves->size(); leafIndex++)
          {
            MatchTreeNode* leaf = leaves->at(leafIndex);
            // cout << "Leaf " << leaf->getChar() << " needs " << leaf->getNextChar() << endl;
            if(problemLine[i] == leaf->getNextChar())
            {

              // cout << "Leaf match found! " <<  problemLine[i] << endl;
              int leafKWI = leaf->getKeywordIndex();
              MatchTreeNode* newNode = new MatchTreeNode(itPos, i, leafKWI +1,leaf->getNextChar(), keyword[leafKWI + 2], leaves);
              leaf->addChild(newNode);
              newNode->setParent(leaf);
              newLeaves.push_back(newNode);
              oldLeaves.push_back(leaf);
              leafIndex++;
              // vector<MatchTreeNode*>::iterator toErase = leaves->begin()+leafIndex;
              // MatchTreeNode* leafToErase = leaves->at(leafIndex);
              // leafToErase->printNode();
              // leaves->erase(toErase);
            }
          }
          // leaves->insert(leaves->end(), newLeaves.begin(), newLeaves.end());
          // if (oldLeaves.size() > 0 && leaves->size() > 0){
          //   leaves->at(0)->printNode();
          //   oldLeaves.at(0)->printNode();
          //   subtract_vector(leaves, oldLeaves);
          // }
          std::sort(leaves->begin(), leaves->end());
          std::sort(oldLeaves.begin(), oldLeaves.end());
          std::vector<MatchTreeNode*> difference;
          std::set_difference(
            leaves->begin(), leaves->end(),
            oldLeaves.begin(), oldLeaves.end(),
            std::back_inserter( difference )
          );
        }
      }
    }
    itPos++;
  }
  // MatchTreeNode* endChar = NULL;
  // int i = 0;
  vector<MatchTreeNode*> solution;
  if (matches.size() > 0){
    MatchTree* matchTree = matches.at(0);
    std::vector<MatchTreeNode*>::iterator it;
    vector<MatchTreeNode*>* leaves = matchTree->getLeaves();

    it = find_if(leaves->begin(), leaves->end(), [keyword](MatchTreeNode* node) { return node->getChar() == keyword[keyword.length() - 1];} );
    MatchTreeNode* endChar = *it;
    // cout << endChar->getChar() << endl;
    int i = 0;
    solution.push_back(endChar);
    MatchTreeNode* parent = endChar->getParent();
    while (i < keyword.length() && parent != NULL){
      solution.insert(solution.begin(), parent);
      parent = parent->getParent();
    }
    cout << "Match!" << endl;
    for (int j = 0; j < solution.size(); j++){
      solution.at(j)->printNode();
    }



  }
  // vector<MatchTreeNode*>* leaves = matchTree->getLeaves();
  // while (endChar == NULL && i < matchTree->getLeaves()->size()){
  //   cout << "asd" << endl;
  //   if ((matchTree->getLeaves()->at(i)->getChar() ) == keyword[keyword.length() - 1]){
  //     endChar = matchTree->getLeaves()->at(i);
  //     break;
  //   }
  //   i++;
  // }
  // std::vector<MatchTreeNode*>::iterator it;
  // it = find_if(leaves->begin(), leaves->end(), [keyword](MatchTreeNode* node) { return node->getChar() == keyword[keyword.length() - 1];} );
  // vector<MatchTreeNode*>* solution = NULL;
  // while (solution->size() < keyword.length()){
  //
  // }

  return matches;
}





int main()
{
  string rows[INPUT_ROWS];
  readIn(rows);
  size_t pos = 0;
  bool finished = false;
  vector<vector< string > > problems =  extractProblems(rows);
  for (vector<string> &v : problems)
  {
    extractMatches(v);
  }
  //    for (const vector<string> &v : problems)
  //    {
  //        for (string problemLine : v)
  //        {
  //            cout << problemLine << endl;
  //        }
  //        cout << endl;
  //    }
}
