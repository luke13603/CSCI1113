#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main(){
  cout << "enter a word" << endl;
  string secret;
  string letter;
  string guessed;
  string hidden;
  int count = 0;
  int wrong = 0;
  int a = 0;
  int b = 0;
  int why = 0;
  string s;
  bool done{false};
  getline(cin, secret);
  hidden = secret;
  
  for(int a = 0; a < secret.size(); a++){
    hidden = hidden.replace(b, b, "~" );
    b++;
  }
  
  string hangman0 = "\t  +---+\n\t  |   |\n\t      |\n\t      |\n\t      |\n\t      |\n\t=========\n";
  string hangman1 = "\t  +---+\n\t  |   |\n\t  o   |\n\t      |\n\t      |\n\t      |\n\t=========\n";
  string hangman2 = "\t  +---+\n\t  |   |\n\t  o   |\n\t  |   |\n\t      |\n\t      |\n\t=========\n";
  string hangman3 = "\t  +---+\n\t  |   |\n\t  o   |\n\t  |   |\n\t  |   |\n\t      |\n\t=========\n";
  string hangman4 = "\t  +---+\n\t  |   |\n\t  o   |\n\t /|   |\n\t  |   |\n\t      |\n\t=========\n";
  string hangman5 = "\t  +---+\n\t  |   |\n\t  o   |\n\t /|\\  |\n\t  |   |\n\t      |\n\t=========\n";
  string hangman6 = "\t  +---+\n\t  |   |\n\t  o   |\n\t /|\\  |\n\t  |   |\n\t /    |\n\t=========\n";
  string hangman7 = "\t  +---+\n\t  |   |\n\t  o   |\n\t /|\\  |\n\t  |   |\n\t / \\  |\n\t=========\n";
  
  while(true){
    cout << secret << endl;
    cout << "word so far: " << hidden << endl;
    if(hidden == secret){
    break;
    }
    if(wrong > 7){
      cout << "game over";
    break;
    }
    cout << "guessess so far: " << guessed << endl;
    cout << "guess" << endl;
    cin >> letter;
    
    for(int i = 0; i < secret.size(); i++){
      if(secret.at(i) == letter.at(0)){
        count++;
      }
    }
    
    if(count > 0){
      guessed += letter;
      
      for(int j = 0; j < secret.size(); j++){
        if(secret.at(j) == letter.at(0)){
          hidden = hidden.replace(j, j, letter);
        }
      }
      
      count = 0;
    }
    else{
      guessed += letter;
      cout << "not the right letter" << endl;
      wrong++;
      count = 0;
    }
    
    
    switch(wrong){
      case 0:
        cout << hangman0 << endl;
        break;
      case 1:
        cout << hangman1 << endl;
        break;
      case 2:
        cout << hangman2 << endl;
        break;
      case 3:
        cout << hangman3 << endl;
        break;
      case 4:
        cout << hangman4 << endl;
        break;
      case 5:
        cout << hangman5 << endl;
        break;
      case 6:
        cout << hangman6 << endl;
        break;
      case 7:
        cout << hangman7 << endl;
        break;
    }
  }
}