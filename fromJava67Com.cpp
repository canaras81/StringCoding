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

void findMaxOccurringCharInString(string str){
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

void removeDupesFromString(string &str){
    map<char, int> numchars_map;
    int strsize = str.size();
    createCharCountMapForString(numchars_map, str);
    // If the number of occurences in the map is greater than 1, erase the character
    for(string::iterator it = str.begin(); it != str.end(); 1){
        if(numchars_map.find(*it)->second != 1){
            it = str.erase(it);
        }
        else
            it++;
    }
    cout << "String after the removal of duplicate characters: \"" << str << "\"" << endl;
}

void findDupesInString(string str){
    map<char, int> numchars_map;
    int strsize = str.size();
    createCharCountMapForString(numchars_map, str);
    cout << "Duplicated characters are: ";
    // If the number of occurences in the map is greater than 1, print the character
    for(map_it it = numchars_map.begin(); it != numchars_map.end(); it++){
        if(it->second != 1)
            cout << "'" << it->first << "' ";
    }
    cout << endl;
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
    //findMaxOccurringCharInString(str_in_1);
    // 2) Remove duplicates (characters that show up 2 or more times)
    // removeDupesFromString(str_in_1);
    // 3) Find the duplicate characters in a string
    //findDupesInString(str_in_1);

    return 0;
}
