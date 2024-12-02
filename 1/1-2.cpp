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

    //cycle through list1 and look for matches in list2
    int similarityScore = 0;
    size_t start = 0;
    for(size_t i = 0 ; i < list1.size() ; ++i){
        int matches = 0;
        for(size_t j = start ; j < list2.size() ; ++j){
            if(list1[i] == list2[j]){
                matches++;
            }
            //move on after all potential matches have been passed
            else if(list1[i] < list2[j]){
                start = j;
                break;
            }
        }
        //increase total similarity score
        similarityScore = similarityScore + (list1[i] * matches);
    }

    //print result
    cout << similarityScore;

    return 0;
}