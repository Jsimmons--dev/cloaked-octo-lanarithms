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

    foreach(vector<MatchTree> problemMatches : matchTrees)
    {
        foreach(MatchTree tree : problemMathes)
   
        {
       
            rightMost = findRightMost(tree);
       
            match = shift(rightMost);
        
            getOptimizationNumbers(match);
    

  
            solution;
   
            paraWidthTies = getparaWidthTies(matchTrees);

    
            if(resolveparaTies(paraWidthTies) != empty)
    
            {
        
                spaceInsTies = getspaceInsTies(paraWidthTies);
        
                if(resolveInsTies(spaceInsTies) != empty)
                {
                    topTies = getTopTies(spaceInsTies);
                     if(resolveTopTies(topTies) != empty)
                     {
                        solution = resolveLeftTies(topTies);
                     } else{solution = topTies}
                } else{solution = spaceInsTies}
            } else{solution = paraWidthTies}
       
       printSolution();

       }
    }
}   

void findMatches(vector<vector<MatchTree> > matchTrees,
        vector<vector<string> > problemSet)
{
    int problemIndex;
    foreach(vector<string> problem : problemSet)
    {
        int lineIndex;
        target = problem.pop();
       foreach(string line : problem)
       {
           int charIndex;
            foreach(char c : line)
            {
                if(c == target.0)
                {
                matchTrees.get(i).push(new MatchTree(charIndex,lineIndex);
                }
                foreach(MatchTree match : matchTrees.get(problemIndex);
                {
                    if(match.needed() == c)
                    {
                        match.point(match.levelUp,c);
                    }
                }
                if(c == '\n')
                {
                //removes if match was found to be invalid
                match.validate();
                }
                charIndex++;
            }
            lineIndex++;
       }
       problemIndex++;
    }
}
