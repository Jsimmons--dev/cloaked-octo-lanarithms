#include <iostream>
#include <string>
#include <vector>
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
            if(problemLine[i] == keyword[0])
            {
                int x = itPos;
                int y = i;
                MatchTree* newMatchTree = new MatchTree(x,y, keyword[0], keyword[1]);
                cout << problemLine[i] << endl;
                matches.push_back(newMatchTree);
            }

       }
       itPos++;
    }
    for(int i = 0;i<matches.size();i++)
    {
        matches[i]->getRoot()->printNode();
    }
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
