#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){

    srand(static_cast<unsigned int>(time(0)));

// Computer guesses your number!
    cout << "welcome to computer's guessing game!" << endl;
    int secret_number = rand() % 5 +1;
    int tries = 0;
    int range = 100;
    int guess, lower_limit_guess = 0, upper_limit_guess = range;
    
    cout << "Enter a secret number ... i am not looking ^_- ... i promise! : ";
    cin >> secret_number;
    cout << "\n\n Guessing a number between 1 - "<< range << " : ";
    guess = rand() % 5 +1;
    tries ++;
    cout << "\n my first guess is "<< guess;

    while(!(guess==secret_number)) {
        tries++;
        cout << "\n Trying again!";
        if (guess<secret_number) {
            lower_limit_guess = guess;
            
            cout<<"\n Guessing higher!";
        }
        else if (guess>secret_number) {
            upper_limit_guess = guess;
            cout<<"\n Guessing lower!"<< guess;
        }
        else cout << "\n my brain hurts!!!---!!!";
        guess = upper_limit_guess+lower_limit_guess;
        guess/=2;
        cout << "\n New guess is :"<< guess;
    }
    cout<<"\n I WON after " << tries << " tries! \n"; 

// User guesses computer's number
    cout << "\n Welcome to my guessing game!" << endl;
    secret_number = rand()%5 +1;
    tries = 0;
    do {
        tries++;
        cout << "\n Guess a number between 1 - 5: " ;
        cin>> guess;
        cout << endl;
        if (guess<secret_number) cout<<"\n Guess higher!";
        else if (guess>secret_number) cout<<"\n Guess lower!";
        else cout<<"\n You WON after " << tries << " tries!"; 
    }while(!(guess==secret_number));
    return 0;
}