#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool reportIsSafe(vector<int>);

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
        //if report is safe increase number of safe reports
        if(reportIsSafe(report)){
            safeReports++;
        }
        else{
            //check if "problem dampener" can fix the report
            for(size_t i = 0 ; i < report.size() ; ++i){
                //make a new report by removing one level at a time
                vector<int> newReport;
                for(size_t j = 0; j < report.size() ; ++j){
                    if(j != i){
                        newReport.push_back(report[j]);
                    }
                }
                //if one of the new reports are safe increment safe reports and stop looking
                if(reportIsSafe(newReport)){
                    safeReports++;
                    break;
                }
            }
        }
    }

    input.close();

    cout << safeReports;

    return 0;
}

bool reportIsSafe(vector<int> report){
    //first check case if the first two numbers are the same
    if(report[1] == report[0]){
        return false;
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
            return false;
        }
    }
    //if the report passes
    return true;
}