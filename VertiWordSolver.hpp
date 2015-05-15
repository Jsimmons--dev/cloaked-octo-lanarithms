#ifndef VERTIWORDSOLVER_H
#define VERTIWORDSOLVER_H
#include <vector>
#include <string>
using namespace std;
namespace VertiWord{

class MatchBox {
    bool valid = true;
    vector<vector< int > > box;
    public:
        MatchBox(vector<string> &problem,int startLine);
};

class sol
{
    public:
        sol(MatchBox*);
        bool operator>(sol* rhs);
};


class VertiWordSolver {
    sol* bestSol;
    vector<MatchBox*> boxes;
    public:
        VertiWordSolver(vector<vector< string > > &input);
        void solve(vector<string>,size_t);
        void printSol(sol*);
};

}
#endif /*VERTIWORDSOLVER_H*/
