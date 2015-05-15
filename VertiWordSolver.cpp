#include "VertiWordSolver.hpp"
#include <vector>

using namespace VertiWord;
VertiWordSolver::VertiWordSolver(vector<vector< string > >&problems)
{
    size_t i = 0;
    for(vector<vector<string> >::iterator it = problems.begin();it != problems.end(); ++it)
    {
        solve(*it,i);
        i++;
        printSol(this->bestSol);
    }
}

void VertiWordSolver::solve(vector<string> problem, size_t i)
{
    string keyword = problem[0];
    for(size_t i = 1;i+keyword.length()<problem.size();i++)
    {
        MatchBox* newMatchBox = new MatchBox(problem,i);
        sol* newSol = new sol(newMatchBox);
        if(newSol > bestSol) bestSol = newSol;
    }
}

MatchBox::MatchBox(vector<string> &problem,int startLine)
{
    for(size_t i = 1; i<problem[0].length();i++)
    {
        vector<int> newLine;
        for(size_t j = 0;j<problem[i].length()-1;i++)
        {
            if(problem[i][j] == problem[0][i])
            {
                if(newLine.size() != 0)
                {
                    newLine.push_back(j);
                }
                else
                {
                    valid = false;
                }
            }
        }
        newLine.push_back(problem[i].length());
        this->box.push_back(newLine);
    }
}

sol::sol(MatchBox*)
{

    

}
