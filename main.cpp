#include <iostream>
#include <string>
#include <vector>
#define INPUT_ROWS 20
using namespace std;

struct matchTreeNode {
struct matchTreeNode *child;
struct matchTreeNode *parent;
};


void readIn(string (&rows)[INPUT_ROWS])
{
    string current = " ";
    for(size_t i = 0;i<INPUT_ROWS && current.compare("END") != 0; ++i)
    {
        getline(cin,current);
        rows[i] = current;
    }
}
void printInput(string (&rows)[INPUT_ROWS])
{
    for(size_t i = 0;i<INPUT_ROWS;++i)
    {
    cout << rows[i]  << endl;
    }
}

vector<string> extract(string (&rows)[INPUT_ROWS],size_t &start)
{
    vector<string> problem;
    string current = " ";
    for(size_t i = start; i < INPUT_ROWS && rows[i] != ""; ++i)
    {
        problem.push_back(rows[i]);
        start++;
    }
    start++;
    return problem;
}

vector<string> printProb(vector<string> problem)
{
    for(vector<string>::iterator it = problem.begin();it != problem.end();++it)
    {
        cout << *it << endl;
    }
    cout << endl;
    return problem;
}


bool ending(vector<string> problem)
{
    return (problem.at(0).compare("END") == 0) ? true : false;
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

int main()
{
    string rows[INPUT_ROWS];
    readIn(rows);
    size_t pos = 0;
    do
    {
        printProb(solve(extract(rows,pos)));
    } while (!ending(printProb(solve(extract(rows,pos)))));

}
