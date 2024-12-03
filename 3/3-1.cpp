#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ifstream input("input.txt");
    string line;
    int total = 0;
    size_t mul, comma, end;
    while(getline(input, line)){
        mul = line.find("mul(");
        while(mul != string::npos){
            comma = line.find(",", (mul));
            if(comma != string::npos){
                if(comma-(mul+4) > 3){
                    //look for next mul
                    mul = line.find("mul(", (mul+4));
                    continue;
                }
            }
            end = line.find(")", comma);
            if(end != string::npos){
                if(end-comma-1 > 3){
                    mul = line.find("mul(", (mul+4));
                    continue;
                }
            }

            //if correct format has been confirmed parse out numbers
            int num1, num2;
            num1 = stoi(line.substr(mul+4,(comma-(mul+4))));
            num2 = stoi(line.substr(comma+1, (end-comma-1)));

            //look for next mul
            mul = line.find("mul(", end);
            total = total + (num1*num2);
        }
        cout << '\n';
    }
    cout << total;
    return 0;
}