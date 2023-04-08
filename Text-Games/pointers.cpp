#include<iostream>
#include<string>

// -----------------------------------------------------------------------------------
// Write C++ program to copy one string to another string using pointer

void stringCopy(char *p_dest,char *p_sorc){
    while(*p_sorc != '\0'){
        *p_dest = *p_sorc;
        p_sorc++; p_dest++;
    }

// alternative of way of wrtiting above code
    // while(*p_dest++ = *p_sorc++);
} 

// ----------------------------------------------------------------------------------
//Write C++ program to concatenate two strings using pointer
char * stringConcat(char *p_sorc1, char *p_sorc2){
    int8_t len_sorc1 =0, len_sorc2 = 0;
    while(*p_sorc1 != '\0'){
        p_sorc1++; 
        len_sorc1++;
    }
    p_sorc1 = p_sorc1-len_sorc1; // resetting the pointer to start point
    
    while(*p_sorc2 != '\0'){
        p_sorc2++;
        len_sorc2++;
    }
    p_sorc2 = p_sorc2-len_sorc2; // resetting the pointer to start point

    int8_t len_dest = len_sorc1 + len_sorc2;
    char *p_dest = new char[len_dest];

    while(*p_sorc1 != '\0'){
        *p_dest = *p_sorc1;
        p_dest++; p_sorc1++;
    }

    while(*p_sorc2 != '\0'){
        *p_dest = *p_sorc2;
        p_dest++; p_sorc2++;
    }
    *p_dest = '\0'; // adding  NULL character in the end. 

    p_dest = p_dest-len_dest; // resetting the pointer to start point
    return p_dest;
}

// ----------------------------------------------------------------------------------
// Write C++ program to print the elements of the array in reverse order using a pointer
char * reverseOrder(char *p_sorc){
    size_t len_sorc = 0;
    while (*p_sorc != '\0'){
        p_sorc++; len_sorc++;
    }
    
    p_sorc = p_sorc - len_sorc;

    char * p_dest = new char[len_sorc];
    p_dest += (len_sorc);
    *p_dest = '\0';
    p_dest--;
    while (*p_sorc != '\0'){
       *p_dest = *p_sorc;
        p_dest--; p_sorc++;
    }
    p_dest++; 
    return p_dest;
}

int main(){
    char str1[] = "ABC";
    char str2[] = "DEF";
    stringCopy(str1, str2); // str1 and str2 are pointers
    std::cout << str1 << std::endl <<  str2 << std::endl;
    
    char * str12 = stringConcat(str1, str2);
    std::cout << str12 << std::endl;

    char * str21 = reverseOrder(str12);
    std::cout << str21 << std::endl;
    return 0;
}