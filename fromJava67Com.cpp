/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
typedef map<char,int>::iterator map_it;

void printCharacterCountMap(map<char,int> &m){
    map_it iter = m.begin();
    while(iter != m.end()){
        cout << iter->first << ":" << iter->second << endl;
        iter++;
    }
}

void createCharCountMapForString(map<char,int> &m, string str){
    int strsize = str.size();
    // Count the characters
    for(int i=0; i < strsize; i++){
        char c = str[i];
        map_it iter = m.find(c);
        if(iter == m.end())
            m.insert(m.begin(), pair<char,int>(c,1));
        else
            iter->second++;
    }
}

void findMaxOccurringChar(string str){
    map<char, int> numchars_map;
    int strsize = str.size();
    createCharCountMapForString(numchars_map, str);
    // Find the maximum number of occurences
    int maxOccur = 0;
    for(map_it iter = numchars_map.begin(); iter != numchars_map.end(); iter++){
        if(maxOccur < iter->second)
            maxOccur = iter->second;
    }
    // Print those characters
    cout << "Max occurring character(s) in the word \"" << str <<  "\" is(are): ";
    for(map_it iter = numchars_map.begin(); iter != numchars_map.end(); iter++){
        if(maxOccur == iter->second)
            cout << iter->first << " ";
    }
    cout << "(" << maxOccur << " times)" << endl;
}

int main(int argc, char *argv[])
{
    string str_in_1, str_in_2;
    str_in_1.assign(argv[1]);
    str_in_2.assign(argv[2]);
    
    cout << str_in_1;
    cout << str_in_2;
    cout << endl;
    
    transform(str_in_1.begin(), str_in_1.end(), str_in_1.begin(), ::tolower);
    
    // 1) How to find the maximum occurring character in given String?
    findMaxOccurringChar(str_in_1);

    return 0;
}
