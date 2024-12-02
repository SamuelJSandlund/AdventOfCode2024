#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    //keep track of number of safe reports
    int safeReports = 0;

    //open file and read line by line
    ifstream input("input.txt");

    string line;
    int n;
    while(getline(input, line)){
        //read line into vector
        istringstream stream(line);
        vector<int> report;
        while(stream >> n){
            report.push_back(n);
        }
        //assume line is safe until proven otherwise
        bool safe = true;
        //first check case if the first two numbers are the same
        if(report[1] == report[0]){
            continue;
        }
        //check if first two numbers are ascending or descending
        bool ascending = report[1] > report[0] ? true : false;
        //loop through report and check for safety violations
        for(size_t i = 1 ; i < report.size() ; ++i){
            int difference = report[i] - report[i-1];
            //break if difference is too big, difference is 0, or direction changes
            if( abs(difference) > 3 
                || difference == 0 || 
                (difference > 0) != ascending
            ){
                safe = false;
                break;
            }
        }
        //if report is not proven unsafe increment number of safe reports
        if(safe){
            safeReports++;
        }
    }

    input.close();

    cout << safeReports;

    return 0;
}