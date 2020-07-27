//Created by Christopher Wright
//Date Created 1/20/2018
//Last edited 1/30/2018
// This program, given a list of words, separates anagrams into equivalence classes and lists the classes that have the greatest number of members in lexicographical order. The input conists of 2 integers 'n' and 'm' both greater than 0 on the first line separated by a single space. 'n' is number of words being inputted and 'm' is the number of classes you want to be printed. Next, input your words one word per line. The program will group together the anagrams then output m classes from largest class to smallest class. 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//preconditoin: vectors are not sorted
//postcondition: vectors will be sorted by size from largest to smallest and lexicogrphically
bool sizeSort(vector<string> vec1, vector<string> vec2)
{
    if(vec1.size() > vec2.size())
    {
        
        return true;
    }
    if(vec1.size() < vec2.size())
    {
        return false;
    }
    
    return vec1[0] < vec2[0];
}

class EquiClasses{
    
private:
    vector<vector<string>> classes;

public:
    
    //precondition: string1 and string2 need to be compared
    //postcondition: returns true if string1 and string2 are anagrams
    bool anagramComp(string string1, string string2)
    {
        sort(string1.begin(), string1.end());
        sort(string2.begin(), string2.end());
        if( string1 == string2)
        {
            return true;
        }
        
        return 0;
    }
    //precondition: string1 and string2 need to be compared
    //postcondition: returns true if string1 and string2 are the same word
    bool sameString(string string1, string string2)
    {
        if(string1 == string2)
        {
            return true;
        }
        return false;
    }
    
    //precondition: string 'words' is not in a class
    //postcondition: either string 'words' was added to the appropriate class or a new class was created and 'words' was put into the new class.
    void add(string words)
    {
        vector<string> temp;
        bool needNew = false ;
        
        for(int i = 0; i < classes.size() && !needNew ; i++)
        {
            for(int j = 0; j < classes[i].size() && !needNew ; j++)
            {
                if(sameString(words, classes[i][j]) == true)
                {
                    needNew = true;
                }
            }
        }
        
        
        for(int i = 0; i < classes.size() && !needNew ; i++)
        {
            
            if(anagramComp(words, classes[i][0]) == true)
            {
                classes[i].push_back(words);
                needNew = true;
                   
            }
        }
        
       if(needNew == false)
        {
            temp.push_back(words);
            classes.push_back(temp);
            temp.clear();
        }
    }
   //precondition: vectors and words in the vectors are not sorted
    //postcondition: vectors will be sorted by size from largest to smallest and lexicogrphically and the words in the individual vectors will be sorted lexicographically
    void sortClasses()
    {
        for(int i = 0; i < classes.size(); i++)
        {
            sort(classes[i].begin(), classes[i].end());
        }
        
        sort(classes.begin(), classes.end(), sizeSort);
    }
    
    //postcondition: object is initialized
    EquiClasses()
    {
    }
    
    //postcondition: all vectors are printed
    void printClasses(int numClasses)
    {
        
        for(int i = 0; i < numClasses; i++)
        {
            cout << "Class of size " << classes[i].size() << ": " ;
            
            for(int j = 0; j < classes[i].size(); j++)
            {
              cout << classes[i][j]<< " " ;
            }
            cout << ".";
            cout << endl;
        }
    }
    
    //precondition: classes needs empty vectors
    //postcondition: an empty vector is pushed to the end of classes
    void add0()
    {
        vector<string> temp;
        classes.push_back(temp);
    }
    
    //precondition: size is not initialized
    //postcondition: size of class is returned to main function
    double vecSize()
    {
        double temp = classes.size();
        return temp;
    }
    
    
    
};

//postcondition: program ends
int main ()
{
    string words;
    int numClasses = 0, numWords = 0;
    cin >> numWords >> numClasses;
    EquiClasses anagrams;
    
    for(int i = 0; i < numWords ; i++)
        {
            cin >> words;
            anagrams.add(words);
            
        }
    
    anagrams.sortClasses();
    
    double size = anagrams.vecSize();
    
    if(size < numClasses)
    {
        size = numClasses - size;
        for(double i = 0; i < size; i++ )
        {
            anagrams.add0();
        }
        
    }
    
    anagrams.printClasses(numClasses);
    
    
    return 0;
    
}
