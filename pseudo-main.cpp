/*
 * This class outlines the algorithms used for project 2
 */

int main(){
    //this vector holds elements which are vectors of each problem to optimize
    //each element is a vector of lines of the problem
    vector<vector<string> > problemSet;

    //read file into problem set
    readFile(problemSet);

    //This vector stores the match trees for each problem
    //match trees are something we haven't quite worked out yet
    vector<vector<MatchTree> > matchTrees;

    //read all of the matches into a structure and place it in the matchTrees
    //vector
    findMatches(matchTrees,problemSet);




    
}
