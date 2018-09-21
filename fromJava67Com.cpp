/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <stack>

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
    createCharCountMapForString(numchars_map, str);
    cout << "Duplicated characters are: ";
    // If the number of occurences in the map is greater than 1, print the character
    for(map_it it = numchars_map.begin(); it != numchars_map.end(); it++){
        if(it->second != 1)
            cout << "'" << it->first << "' ";
    }
    cout << endl;
}

void removeString2CharsFromString1(string &str1, string &str2)
{
    // create a map for str2
    // for every character in str1, check if it exists in the map
    // remove if it does
    
    map<char,int> numchars_map_2;
    createCharCountMapForString(numchars_map_2, str2);
    printCharacterCountMap(numchars_map_2);
    for(string::iterator it=str1.begin(); it != str1.end(); 1){
        if(numchars_map_2.find(*it) == numchars_map_2.end())
            it++;
        else
            it = str1.erase(it);
    }
    cout << "LHString after the removal of characters of RHString: " << str1 << endl;
}

void boolRotationStrings(string str1, string str2){
    // take the first letter from the first string
    // for every character found in str2, create a new string in which
    // the found character is the first character of the new string and
    // once the end of the second string is reached, wrap to the start
    // and add the remaining characters
    // then compare with str1
    char c = str1[0];
    int strlen_2 = str2.size();
    for(int i=0; i<strlen_2; i++){
        if(c == str2[i]){
            // create the new string here
            string str_help;
            str_help.assign(str2, i, strlen_2-i);
            str_help.append(str2, 0, i-1);
            int is_rotation = str1.compare(str_help);
            if(is_rotation == 1){
                cout << "The strings ARE rotations of each other." << endl;
                return;
            }
        }
    }
    cout << "The strings ARE NOT rotations of each other." << endl;
}

void reverseStringRecursiveHelper(string str, stringstream &ss){
    if(str.size() == 0)
        return;
    else
    {
        ss << str[str.size()-1];
        str.pop_back();
        reverseStringRecursiveHelper(str, ss);
    }
}

void reverseStringRecursive(string &str){
    cout << "Reverse of " << str << " is ";
    stringstream ss(str);
    reverseStringRecursiveHelper(str, ss);
    str.assign(ss.str());
    cout << str << endl;
}

void reverseStringIterative(string &str){
    cout << "Reverse of " << str << " is ";
    stack<char> char_stack;
    int strsize = str.size();
    for(int i=0; i < strsize; i++){
        char_stack.push(str[i]);
    }
    str.clear();
    while(char_stack.empty() == false){
        str.append(1, char_stack.top());
        char_stack.pop();
    }
    cout << str << endl;
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
    transform(str_in_2.begin(), str_in_2.end(), str_in_2.begin(), ::tolower);
    
    // Questions and answers are also here:
    // http://www.java67.com/2018/04/21-string-programming-and-coding-interview-questions-answers.html
    //
    // 1) How to find the maximum occurring character in given String?
    // findMaxOccurringCharInString(str_in_1);
    
    // 2) How to remove all duplicates from a given string? (characters that show up 2 or more times)
    // removeDupesFromString(str_in_1);
    // str_in_1.assign(argv[1]);
    
    // 3) How to print the duplicate characters from given String?
    // findDupesInString(str_in_1);
    
    // 4) How to remove characters from the first String which are present in the second String?
    // removeString2CharsFromString1(str_in_1, str_in_2);
    // str_in_1.assign(argv[1]);
    
    // 5) How to check if two strings are rotations of each other?
    // boolRotationStrings(str_in_1, str_in_2);
    
    // 6/7) Reverse a string recursively and non-recursively
    // reverseStringRecursive(str_in_1);
    // reverseStringIterative(str_in_2);
    // str_in_1.assign(argv[1]);
    // str_in_2.assign(argv[2]);

    return 0;
}
