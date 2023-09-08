#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "linkedList.hpp"

#define WIDTH 50
#define HEIGHT 25

enum direction {STOP = 0, UP, DOWN, RIGHT, LEFT};

struct position {  // x, y position
    int x;
    int y;
};

bool operator==(const position& lhs, const position& rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}

// x is the column, y is the row. The origin (0,0) is top-left.
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}


position randPos(){
     std::srand(std::time(nullptr)); // use current time as seed for random generator
    return {(std::rand()%(WIDTH-2))+1, (std::rand()%(HEIGHT-2))+1};
}


// return -1 means that fruit location is same as snake body
int drawFruit(linkedList<position>& bodySnake, position pos) {
    Node<position>* nodePtr = bodySnake.m_head;
    for (unsigned int i =0; i < bodySnake.length; i++) {
        if(nodePtr->data == pos) 
        return -1;
        nodePtr = nodePtr->next;
    }
    setCursorPosition(pos.x, pos.y);
    std::cout << 'F';
    return 0;
}


void initGame(linkedList<position>& bodySnake, position& fruitPos){
    // drawing boundary
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(j == 0 || j == WIDTH-1 || i == 0 || i == HEIGHT-1) std::cout << '#';
            else std::cout << ' ';
        }
        std::cout << std::endl;
    }

    // drawing snake
    setCursorPosition(bodySnake.getTailData().x, bodySnake.getTailData().y);    // head of the snake
    std::cout << '0';
    for (int i = 1; i < 4; i++) {
        bodySnake.append_back( {(WIDTH/2) + i, HEIGHT/2} );
        setCursorPosition(bodySnake.getTailData().x, bodySnake.getTailData().y);    // head of the snake
        std::cout << '0';
    }

    // drawing fruit
    fruitPos = randPos();
    while(drawFruit(bodySnake, fruitPos)){}
}


void changeDir(direction &dir){
    switch (_getch())
    {
    case 'a':
        dir = LEFT;
        break;
    case 'd':
        dir = RIGHT;
        break;
    case 's':
        dir = DOWN;
        break;
    case 'w':
        dir = UP;
        break;
    default:
        break;
    }
}


void moveSnake_checkFruit(linkedList<position>& bodySnake, const direction dir, position& fruitPos){
    // moving 1 step in given direction
    // updating list
    position temp = bodySnake.getHeadData();
    switch (dir) {
        case(RIGHT): {
            temp.x = temp.x + 1;
            break;
        }
        case(LEFT): {
            temp.x = temp.x - 1;
            break;
        }
        case(UP): {
            temp.y = temp.y - 1;
            break;
        }
        case(DOWN): {
            temp.y = temp.y + 1;
            break;
        }
        default:
            break;
    }
    bodySnake.push_front({temp.x, temp.y}); // adding new head
    // printing new head and removing tail

    setCursorPosition(bodySnake.getHeadData().x, bodySnake.getHeadData().y);  // tail of the snake
    std::cout << '0';
    if(fruitPos == temp){
        fruitPos = randPos();
        while(drawFruit(bodySnake, fruitPos)){};
    } else {
        setCursorPosition(bodySnake.getTailData().x, bodySnake.getTailData().y);    // head of the snake
        std::cout << ' ';
        bodySnake.pop_back();  // removing the tail from memory
    }
}


int stopGame(linkedList<position>& bodySnake){
    // check if snake hits the boundary
    if( bodySnake.getHeadData().x == 0 ||
        bodySnake.getHeadData().y == 0 ||
        bodySnake.getHeadData().x == WIDTH-1 ||
        bodySnake.getHeadData().y == HEIGHT-1
    ) return -1; // stop game
    
    // check if snake eats itself
    Node<position>* nodePtr = bodySnake.m_head->next;
    position headPos = bodySnake.m_head->data;
    for (unsigned int i =0; i < (bodySnake.length -1); i++) {
        if(nodePtr->data == headPos) return -1; // stop game
        nodePtr = nodePtr->next;
    }

    return 0;  // continue game
}

int main() {
    // intial snake body
    linkedList<position> bodySnake({WIDTH/2,HEIGHT/2}); // initializing snake at following position
    direction dir = LEFT; // default 
    position fruitPos = randPos();
    initGame(bodySnake, fruitPos);

    while(!stopGame(bodySnake)){
        Sleep(100);
        moveSnake_checkFruit(bodySnake, dir, fruitPos);
        if(_kbhit()){
            changeDir(dir);
        }
    }
    return 0;
}