using namespace std;
#include <iostream>

// function using STRUCT return type
auto get_student_struct(int roll_number){
    struct StudentDetails{ double gpa; char grade; std::string name;};
    if (roll_number == 0) 
        return StudentDetails{3.8, 'A', "Lisa Simpson"}; 
    if (roll_number == 1) 
        return StudentDetails{2.9, 'C', "Milhouse Van Houten"};
    if (roll_number == 2) 
        return StudentDetails{1.7, 'D', "Ralph Wiggum"};
    throw std::invalid_argument("id");
}

// function using TUPLE return type
// for C++17
#include <tuple>
std::tuple<double, char, std::string> get_student_tuple(int roll_number){
        if (roll_number == 0) 
        return {3.8, 'A', "Lisa Simpson"}; 
    if (roll_number == 1) 
        return {2.9, 'C', "Milhouse Van Houten"};
    if (roll_number == 2) 
        return {1.7, 'D', "Ralph Wiggum"};
    throw std::invalid_argument("id");
}




int main(){
    //using struct
    auto student0 = get_student_struct(0);
    std::cout << "ID:0, "<< "CGPA: " << student0.gpa << "," 
                << " grade: " << student0.grade << ","
                << " name: " << student0.name << endl;

    //or 
    auto [gpa1, grade1, name1] = get_student_struct(1); // using struct to recieve multiple return values
    std::cout << "ID:1, "<< "CGPA: " << gpa1 << "," 
                << " grade: " << grade1 << ","
                << " name: " << name1 << endl;

    // using tuple
    auto [gpa2, grade2, name2] = get_student_tuple(2);
    std::cout << "ID:3, "<< "CGPA: " << gpa2 << "," 
                << " grade: " << grade2 << ","
                << " name: " << name2 << endl;
}