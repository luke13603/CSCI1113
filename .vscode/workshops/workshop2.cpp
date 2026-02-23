/*
* Name: Gabriel Garso
*
* Workshop 2: Mystery Nested Loops
* This program is supposed to make a multiplication table.
* but it has 6 bugs that you need to find and fix.
* You will also need to make some "style" fixes
* to match good code hygiene.
*
* Bug types hidden in this code:
* 1 Compiler Error
* 1 Runtime Error
* 4 Logic Errors (two are very sneaky!)
*/

/*
* what comments do we want to see?
* a statment at the top about what the program is trying to do
* who created it, when, contact info, (also at the top)
* comments describing each variable - placed when we declare them
* Example of results (at the bottom)
* in-line coments explaing any particularly important of confusing steps in the code.
*/

/*
Debugging tools:
"look at it" - staitc analysis
"code tracing" - on paper we can write down what the ecxpect each step 
of the program to do
run the program - look at the output for compile or runtime errors
make small changes and see the effect
diagnostic prints- cout
debugger built into the IDE
*/
#include <iostream>
using namespace std;
int main(){
    const int SIZE = 5;
    int sum = 0;
    cout << "Multiplication Table:" << endl;
    
    for (int i = 1; i <= SIZE; i++){
        
        for (int j = 1; j <= SIZE; j++){
            int result = i * j;
            int temp = temp + result;
            sum += result;
            cout << result << " ";
        }
        cout << endl;
    }
    
    cout << "\nTotal sum: " << sum << endl;
    
    if (sum == 225){
        cout << "Perfect! The sum is correct." << endl;
    }
    else{
        cout << "Something is wrong! Expected 225 but got " << sum << endl;
    }
    return 0;
}