#include <iostream>
#include <string>
#include <vector>
using namespace std;


void readRows(vector<vector<string> > &rows)
{
    int i = 0;
    string current = " ";
    while(current.compare("END") != 0)
    {
        //vector<vector<string> > currentProblem;
        //rows.insert(i,currentProblem);
        while(current.compare("") != 0)
        {
        rows.at(i).push_back(current);
        getline(cin,current);
        }
        i++;
    }
}

int main()
{
    vector<vector<string> > rows;
    readRows(rows);
    //for(vector<string>::const_iterator i = rows.begin(); i != rows.end();++i)
    //{
    //    cout<<*i<<endl;
    //}
}
