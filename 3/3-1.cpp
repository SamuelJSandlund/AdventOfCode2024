#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ifstream input("input.txt");
    string line;
    size_t mul, comma, end;
    while(getline(input, line)){
        //size_t lineLength = line.size();
        mul = line.find("mul(");
        while(mul != string::npos){
            cout << line.substr(mul, 4) << "[AT: " << mul << "]";
            comma = line.find(",", (mul));
            if(comma != string::npos){

                cout << line.substr(mul+4,3);
            }
            end = line.find(")", comma);
            if(end != string::npos){
                cout << line.at(end) << " ";
            }
            mul = line.find("mul(", end);
        }
        cout << '\n';
    }
    return 0;
}