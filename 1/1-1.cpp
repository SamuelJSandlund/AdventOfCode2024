#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //we prepare a vector for each list in the input
    vector<int> list1, list2;

    //open the input file and read contents into the lists
    ifstream inputFile("input.txt");
    int temp;

    //first number on each row goes into list1 second into list2
    bool toggle = true;
    while(inputFile >> temp){
        if(toggle){
            list1.push_back(temp);
        }
        else{
            list2.push_back(temp);
        }
        toggle = !toggle;
    }

    inputFile.close();
    //sort the vectors smallest first
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    //calculate and summarize differences
    int total = 0;
    for(size_t i = 0 ; i < list1.size() ; ++i){
        total = total + abs(list1[i] - list2[i]);
    }

    //print result
    cout << total;

    return 0;
}