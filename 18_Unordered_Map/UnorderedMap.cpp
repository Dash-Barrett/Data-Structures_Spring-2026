#include <iostream>
#include <unordered_map> // Hash Table
#include <vector>
#include <string>
using namespace std;


class HashExamples{
private:

public:
    template <typename T>
    static void countFrequency(const vector<T>& v){
        unordered_map<T, int> freq;
        for (const T& i : v){
            freq[i]++;
        }
        for(const auto& f : freq){
            cout << f.first << " : " << f.second << endl;
        }
    }

    template <typename T>
    static bool hasDuplicates(const vector<T>& v){
        unordered_map<T, int> freq;
        for (const T& i : v){
            freq[i]++;
        }
        for(const auto& f : freq){
            if(f.second > 1){
                return true;
            }
        }
        return false;
    }

    static char firstNonRepeatingChar(const string& s){

    }

    static void groupStrings(const vector<string>& strings){
        /*
        <first_letter> : strings
        */
    }

};

int main(void){
    unordered_map<string, int> grades;

    // Insert
    grades["Michael"] = 90;
    grades["Anna"] = 95;
    grades["John"] = 76;

    // Iteratre through the table
    for(const auto& g : grades){
        cout << g.first << " : " << g.second << endl;
    }

    // Search
    auto it = grades.find("John");
    if(it == grades.end()){
        cout << "Not found" << endl;
    }
    else{
        cout << "Found\n";
        cout << it->first << " : " << it->second << endl;
    }

    cout << "Count Frequency...\n";
    vector<int> v1 = {1, 2, 3, 4, 1, 2, 2, 2, 5, 5, 12};
    HashExamples::countFrequency(v1);

    cout << "Check Duplicates...\n";
    vector<string> v2 = {"hello", "apple", "banana", "hey", "ban", "apple"};
    cout << HashExamples::hasDuplicates(v2) << endl;

    return 0;
}