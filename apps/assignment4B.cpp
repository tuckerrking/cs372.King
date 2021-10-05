#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

list<string> wordlist;

void readWords() 
{
    ifstream in ( "test.txt" );
    string word;
    if ( !in )   return;
    while ( in>> word )
        wordlist.push_back ( word );
}

void getKeyTexts() 
{

}

int main () 
{
    // input --> list of words
    readWords();
    

    return 0;
}
