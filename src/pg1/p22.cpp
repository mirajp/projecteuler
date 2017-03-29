/*
Names scores
Problem 22
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 
For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938  53 = 49714.
 
What is the total of all the name scores in the file?
*/
 
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
void replace(string &str, const string &from, const string &to) {
    size_t start_pos = str.find(from);
    while (start_pos != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos = str.find(from);
    }
    return;
}
 
int main() {
    string name;
    unsigned long totalNamesScore = 0;
    vector<string> namesList;
       
    ifstream namesFile("../lib/names.txt");
    if (namesFile.is_open()) {
        while (getline(namesFile, name, ',')) {
            replace(name, "\"", "");
            namesList.push_back(name);
        }
        namesFile.close();
         
        replace(namesList[namesList.size()-1], "\n", "");
        
        sort(namesList.begin(), namesList.end());
           
        for (int i = 0; i < namesList.size(); i++) {
            string name = namesList[i];
            for (int j = 0; j < name.length(); j++) {
                totalNamesScore += ((name[j] - 'A' + 1)*(i+1));
            }
        }
           
        cout << "Total names score for the " << namesList.size() << " names = " << totalNamesScore << endl;
        
        return 0;
    }
    else {
        cout << "Unable to open file." << endl;
        return 1;
    }
}

