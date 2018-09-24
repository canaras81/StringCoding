/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <climits>

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
                cout << str1 << " and " << str2 << " ARE rotations of each other." << endl;
                return;
            }
        }
    }
    cout << str1 << " and " << str2 << " ARE NOT rotations of each other." << endl;
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

void printStrPermutations(string str){
    // Using sets instead of stacks here would make this much faster as the 
    // number of repeating characters in the input string increased. 
    stack<string> str_stack;
    stack<string> str_stack_2;
    ///
    char elem = str[str.size()-1];
    str.pop_back();
    string curr_str;
    curr_str.push_back(elem);
    str_stack.push(curr_str);
    while(str.size() > 0){
        char elem = str[str.size()-1];
        str.pop_back();
        while(str_stack.empty() == false){
            string main_str;
            main_str.assign(str_stack.top());
            str_stack.pop();
            for(int i=0; i < main_str.size(); i++){
                string curr_str;
                curr_str.assign(main_str);
                curr_str.insert(i, 1, elem);
                str_stack_2.push(curr_str);
            }
            string curr_str;
            curr_str.assign(main_str);
            curr_str.push_back(elem);
            str_stack_2.push(curr_str);
        }
        while(str_stack_2.empty() == false){
            string curr_str;
            curr_str.assign(str_stack_2.top());
            str_stack_2.pop();
            str_stack.push(curr_str);
        }
    }
    int stack_size = str_stack.size();
    set<string> str_set;
    while(str_stack.empty() == false){
        str_set.insert(str_stack.top());
        str_stack.pop();
    }
    for(set<string>::iterator it = str_set.begin(); it != str_set.end(); it++){
        cout << (*it) << ",";
    }
    cout << endl << stack_size << "," << str_set.size() << endl;
}

void findFirstNonRepeating(string str){
    map<char,int> numchars_map;
    createCharCountMapForString(numchars_map, str);
    int strsize = str.size();
    for(int i=0; i<strsize; i++){
        char c = str[i];
        if(numchars_map.find(c)->second == 1){
            cout << "First non-repeating character in " << str << " is " << c << endl;
            return;
        }
    }
    cout << "There are no non-repeating characters in " << str << endl;
}

void reverseWord(vector<string> word){
    int vecsize = word.size();
    for(int i=vecsize-1; i>-1; i--){
        cout << word[i] << " ";
    }
    cout << endl;
}

bool smallestSubstringMapChecker(map<char, int> &walk_map, map<char, int> &find_map){
    for(map_it iter = find_map.begin(); iter != find_map.end(); iter++){
        map_it iter2 = walk_map.find(iter->first);
        if(iter2 == walk_map.end())
            return false;
        else if(iter2->second < iter->second)
            return false;
        else
            continue;
    }
    return true;
}

void findSmallestSubstringInString(string str_find, string str_in){
    if(str_find.size() > str_in.size()){
        cout << "The string to find is longer than the string to search in." << endl;
    }
    else{
        int min = INT_MAX;
        int min_left = 0;
        int min_right = str_find.size()-1;
        int left = 0;
        int right = 0;
        map<char, int> walkMap;
        map<char, int> findMap;
        createCharCountMapForString(findMap, str_find);
        for(int i=0; i<str_in.size(); i++){
            char c = str_in[i];
            map_it iter = walkMap.find(c);
            if(iter == walkMap.end())
                walkMap.insert(pair<char,int>(c,1));
            else
                iter->second++;
            if(smallestSubstringMapChecker(walkMap, findMap) == true)
            {
                while(1){
                    char c = str_in[left];
                    left++;
                    map_it iter = walkMap.find(c);
                    iter->second--;
                    if(smallestSubstringMapChecker(walkMap, findMap) == false)
                        break;
                }
                right = i;
                if(right - left + 1 < min){
                    //cout << right << " " << left << " " << right - left + 1 << endl;
                    min = right - left + 1;
                    min_left = left;
                    min_right = right;
                }
            }
        }
        for(int i=min_left-1; i<=min_right; i++){
            cout << str_in[i];
        }
        cout << endl;
    }
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
    // boolRotationStrings("hallelujah", "elujahhall");
    
    // 6/7) Reverse a string recursively and non-recursively
    // reverseStringRecursive(str_in_1);
    // reverseStringIterative(str_in_2);
    // str_in_1.assign(argv[1]);
    // str_in_2.assign(argv[2]);
    
    // 8) How to print all permutation of a String?
    // printStrPermutations(str_in_1);
    
    // 9) How to find the first non-repeating character in a given String?
    // findFirstNonRepeating(str_in_1);
    // findFirstNonRepeating(str_in_2);
    
    // 10) How to reverse the words in a given String sentence?
    // read the word
    // vector<string> word; for(int i=1; i<argc; i++) word.push_back(argv[i]);
    // for(int i=0; i<word.size(); i++) cout << word[i] << " ";
    // reverseWord(word);
    
    // 11) How to find the smallest substring in a given string containing all characters of another string?
    findSmallestSubstringInString("tist", "this is a test string");

    return 0;
}
