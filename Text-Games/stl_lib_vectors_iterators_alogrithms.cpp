#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> words;

void printWords(){
    if (words.empty()) cout<< "Word list is empty!" << endl;
    else {
        cout << "List of words are: " << endl;
        for (int i = 0; i < words.size(); i++){
            cout << i+1 << ": "<< words[i] << " -> contains " << words[i].size()<< " letters."<< endl;
        }
    }
}

void printWords_using_Iterators(){
    if (words.empty()) cout<< "Word list is empty!" << endl;
    else {
        vector<string>::const_iterator iter; // using const_iterator so not to accidently change the element's value.
        cout << "List of words are: " << endl;
        for (iter = words.begin(); iter !=words.end(); ++iter){
            cout << iter - words.begin() + 1 << ": "<< *iter << " -> contains " << (*iter).size()<< " letters."<<endl;
            // we can also use "iter->size()" instead of "(*iter).size()"
        }
    }
}

int main (){
//  -------- Vectors and Iterators basics ------------

    words.push_back("sword");
    words.push_back("armor");
    words.push_back("shield");

    cout << "No of words: "<< words.size()<< endl;
    // printWords();
    printWords_using_Iterators();

    cout << endl <<"the word sword is changed with the word battle axe.";
    // words[0] = "battle axe";
    // printWords();
    vector<string>::iterator my_iterator;
    my_iterator = words.begin();
    *my_iterator = "battle axe";
    printWords_using_Iterators();

    cout << "\nYou recover a crossbow from a slain enemy.";
    // words.push_back("crossbow");
    // printWords();
    words.insert(words.begin(), "crossbow");
    printWords_using_Iterators();

    // cout << "\nYour shield is destroyed in a fierce battle.";
    // words.pop_back();
    // printWords();
    cout << "\nYour armor is destroyed in a fierce battle.";
    words.erase(words.begin()+2);
    printWords_using_Iterators();

    cout << endl << "You were robbed of all of your possessions by a thief." << endl;
    // words.clear();
    // printWords();
    words.clear();
    printWords_using_Iterators();

// ---------- Alogrithms ----------
    vector<int>::const_iterator iter;
    cout << "Creating a list of scores.";
    vector<int> scores; 
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);

    cout << "\nHigh Scores: \n";
    for (iter=scores.begin(); iter!=scores.end(); ++iter){
        cout << *iter << endl;
    }
    
    cout << "\nFinding score:";
    int score;
    cout << "\nEnter score:";
    cin >> score;
    iter = find(scores.begin(), scores.end(), score);
    if (iter != scores.end()) cout << "Score found. \n";
    else cout << "Score not found. \n";

    cout << "\nRandomizing score:";
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(scores.begin(), scores.end());
    cout << "\nHigh Scores: \n";
    for (iter=scores.begin(); iter!=scores.end(); ++iter){
        cout << *iter << endl;
    }

    cout << "\nSorting scores:";
    sort(scores.begin(), scores.end());
    cout << "\nHigh Scores: \n";
    for (iter=scores.begin(); iter!=scores.end(); ++iter){
        cout << *iter << endl;
    }

// ------- Capacity and Reserve ------
    vector<int>numbers(2, 0);
    cout << "\n List of numbers are: " << endl;
        for (int i = 0; i < numbers.size(); i++){
            cout << i+1 << ": "<< numbers[i] << endl;}
    cout << "vector capacity before allocation:" << numbers.capacity() << endl;

    numbers.push_back(1);
    cout << "\nList of numbers are: " << endl;
    for (int i = 0; i < numbers.size(); i++){
        cout << i+1 << ": "<< numbers[i] << endl;}
    cout << "vector capacity after reallocation:" <<
     numbers.capacity() << endl;
    cout << "you can see that the capacity doubles after memory reallocation" << endl;
    
    numbers.reserve(5);
    cout << "\nvector capacity after reserve member func with 10 as arg: " << numbers.capacity() << endl;
    cout << "List of numbers are: " << endl;
    for (int i = 0; i < numbers.size(); i++){
        cout << i+1 << ": "<< numbers[i] << endl;}
    cout << "vector capacity before reallocation:" <<
    numbers.capacity() << endl;

    numbers.push_back(1);
    numbers.push_back(1);  
    numbers.push_back(1);
    cout << "\nList of numbers are: " << endl;
    for (int i = 0; i < numbers.size(); i++){
        cout << i+1 << ": "<< numbers[i] << endl;}
    cout << "vector capacity after reallocation:" <<
    numbers.capacity() << endl;
    return 0;
}