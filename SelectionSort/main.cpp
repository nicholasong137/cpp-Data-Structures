#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    // if(index >= vals.size()) {
    //     throw out_of_range("min_index: out of range exception occured");
    // }
    int n = vals.size();

    int min_idx = index;

    for(int i = index + 1; i < n; i++) {
        if(vals.at(i) < vals.at(min_idx)) {
            min_idx = i;
        }
    }
    return min_idx;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    int n = vals.size();
    for(int j = 0; j < n - 1; j++) {
        int minIndex = min_index(vals, j);
        swap(vals.at(j), vals.at(minIndex));
    }
    return;
}

template<typename T>
T getElement(vector<T> vals, int index) {
    // try {
    //     return vals.at(index);
    // }
    // catch (out_of_range& excpt) {
    //     cout << "out of range exception occured" << endl;
    //     return 0;
    // }
    return vals.at(index);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){

    // Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        try {
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        } catch (out_of_range& excpt) {
            cout << "out of range exception occured" << endl;
        }        
    }

    return 0;
}