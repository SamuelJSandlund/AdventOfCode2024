#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void reset(int* dontMeter, int* mulMeter, int* num1, int* num2){
    *dontMeter = 0;
    *mulMeter = 0;
    *num1 = 0;
    *num2 = 0;                    
}

int main(){
    ifstream input("input.txt");
    char c;
    bool readDisabled = false;
    int total = 0;
    int num1 = 0, num2 = 0;
    int doMeter = 0, dontMeter = 0, mulMeter = 0, numSizeTracker = 0;
    while(input.get(c)){
        if(readDisabled){
            //only look for do() instruction
            switch(c){
                case 'd':
                    doMeter = 1;
                    break;
                case 'o':
                    if(doMeter == 1){
                        doMeter++;
                    }
                    else{
                        doMeter = 0;
                    }
                    break;
                case '(':
                    if(doMeter == 2){
                        doMeter++;
                    }
                    else{
                        doMeter = 0;
                    }
                    break;
                case ')':
                    if(doMeter == 3){
                        doMeter = 0;
                        readDisabled = false;
                    }
                    else{
                        doMeter = 0;
                    }
                    break;
                default:
                    doMeter = 0;
                    continue;
            }
        }
        else{
            //look for both mul() and don't() instructions
            switch(c){
                case 'm':
                    mulMeter = 1;
                    dontMeter = 0;
                    num1 = 0;
                    num2 = 0;
                    numSizeTracker = 0;
                    break;
                case 'u':
                    if(mulMeter == 1){
                        mulMeter++;
                    }
                    else{
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                    }
                    numSizeTracker = 0;
                    break;
                case 'l':
                    if(mulMeter == 2){
                        mulMeter++;
                    }
                    else{
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                    }
                    numSizeTracker = 0;
                    break;
                case 'd':
                    dontMeter = 1;
                    mulMeter = 0;
                    num1 = 0;
                    num2 = 0;
                    numSizeTracker = 0;
                    break;
                case 'o':
                    if(dontMeter == 1){
                        dontMeter++;
                    }
                    else{
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                    }
                    numSizeTracker = 0;
                    break;

                case 'n':
                    if(dontMeter == 2){
                        dontMeter++;
                    }
                    else{
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                    }
                    numSizeTracker = 0;
                    break;

                case '\'':
                    if(dontMeter == 3){
                        dontMeter++;
                    }
                    else{
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                    }
                    numSizeTracker = 0;
                    break;

                case 't':
                    if(dontMeter == 4){
                        dontMeter++;
                    }
                    else{
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                    }
                    numSizeTracker = 0;
                    break;

                case '(':
                    if(mulMeter == 3){
                        mulMeter++;
                    }
                    else if(dontMeter == 5){
                        dontMeter++;
                    }
                    else{
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                    }
                    numSizeTracker = 0;
                    break;

                case ',':
                    if(mulMeter != 4 || numSizeTracker < 1){
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                    }
                    else{
                        mulMeter++;
                        numSizeTracker = 0;
                    }
                    numSizeTracker = 0;
                    break;

                case ')':
                    if(dontMeter == 6){
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                        readDisabled = true;
                    }
                    else if(mulMeter == 5 && numSizeTracker > 0){
                        total = total + (num1 * num2);
                    }
                    else{
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                    }
                    numSizeTracker = 0;
                    break;

                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
                    if(numSizeTracker > 2){
                        reset(&dontMeter, &mulMeter, &num1, &num2);
                        numSizeTracker = 0;
                        continue;
                    }
                    else if(mulMeter == 4){
                        num1 = (num1 * 10) + (c - '0');
                        numSizeTracker++;
                    }
                    else if(mulMeter == 5){
                        num2 = (num2 * 10) + (c - '0');
                        numSizeTracker++;
                    }
                    break;
                default:
                    reset(&dontMeter, &mulMeter, &num1, &num2);
                    numSizeTracker = 0;
                    continue;
            }
        }
    }
    cout << total;
}