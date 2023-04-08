#include <SFML/Graphics.hpp>
#include <iostream>

class Puzzle{
    unsigned int SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT;
    int BLOCK_WIDTH;
    int BLOCK_HEIGHT;
    int grid[16];
    int emptyBlockSpriteValue;
    sf::Sprite sprites[16];
    sf::Sprite winner;
    sf::Texture texture;
    sf::Texture youWinBanner;
    sf::RenderWindow app;
    bool continueGame;

    void SpritesInit();
    void RandomizeGrid();
    void UpdateScreen();
    void CheckInput();
    void CheckWin();
    void Init();

public:
    Puzzle(){}
    void Play();
};

void Puzzle::SpritesInit(){
    for (int y=0; y<4; y++){
        for(int x=0; x <4; x++){
            sprites[y*4 + x].setTexture(texture);
            sprites[y*4 + x].setTextureRect(sf::IntRect(x*BLOCK_WIDTH, y*BLOCK_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT));
            grid[y*4 + x] = y*4 + x + 1;
        }
    }
}

void Puzzle::RandomizeGrid(){
// Randomize the grid.
    // std::srand(std::time(nullptr)); // use current time as seed.
    // for(int i = 0; i<16; i++){
    //     int n = std::rand()%16;
    //     int temp = grid[i];
    //     grid[i] = grid[n];
    //     grid[n] = temp; 
    // }
    grid[14] = 16;
    grid[15] = 15;
}

void Puzzle::UpdateScreen(){
// Clear Screen
    app.clear(sf::Color::White);
// setPostion and Draw Sprites
    for(int i = 0; i < 16; i++){
        int n = grid[i];
        // darwing n numbered sprite on the screen.
        sprites[n-1].setPosition((i%4)*BLOCK_WIDTH, (i/4)*BLOCK_WIDTH);
        app.draw(sprites[i]);
    }
    app.display();
}

void Puzzle::CheckInput(){
    sf::Event event;
    while (app.pollEvent(event))
    {
        if(event.type == sf::Event::Closed) app.close();
        if(event.type == sf::Event::MouseButtonPressed){
            if(event.key.code == sf::Mouse::Left){
                sf::Vector2i pos = sf::Mouse::getPosition(app);
                int x = pos.x/BLOCK_WIDTH;
                int y = pos.y/BLOCK_HEIGHT;
                std::cout << std::endl << "x: "<< x << " y: " << y;
                std::cout << std::endl << "block: "<< x+ y*4;
                // if selected block have on adjacent side an emptyBlock, 
                // then swap it with current block.
                int selectedGrid = x + y*4 ; // starting from 0 till 15.
                int temp;
                if (selectedGrid < 15)
                if(grid[selectedGrid+1] == emptyBlockSpriteValue) {
                    temp = grid[selectedGrid]; 
                    grid[selectedGrid] = emptyBlockSpriteValue;   // if true emptyBlockLocation  = selectedBlock +1.
                    grid[selectedGrid + 1] = temp;
                    }
                if(selectedGrid > 0) 
                if(grid[selectedGrid-1] == emptyBlockSpriteValue){
                    temp = grid[selectedGrid]; 
                    grid[selectedGrid] = emptyBlockSpriteValue;   // if true emptyBlockLocation  = selectedBlock +1.
                    grid[selectedGrid -1] = temp;
                }
                if(selectedGrid > 3) 
                if(grid[selectedGrid-4] == emptyBlockSpriteValue){
                    temp = grid[selectedGrid]; 
                    grid[selectedGrid] = emptyBlockSpriteValue;   // if true emptyBlockLocation  = selectedBlock +1.
                    grid[selectedGrid -4] = temp;
                }
                if(selectedGrid < 12)
                if(grid[selectedGrid+4] == emptyBlockSpriteValue){
                    temp = grid[selectedGrid]; 
                    grid[selectedGrid] = emptyBlockSpriteValue;   // if true emptyBlockLocation  = selectedBlock +1.
                    grid[selectedGrid +4] = temp;
                }
            }
        }
    }
}

void Puzzle::CheckWin(){
    int count =0;
    for(int i = 0; i<16; i++) 
        if(grid[i] == i+1) 
            count++;
    if(count == 16) continueGame = false;

}

void Puzzle::Init(){
    SCREEN_WIDTH = 256;
    SCREEN_HEIGHT = 256;
    BLOCK_WIDTH = 64;
    BLOCK_HEIGHT = 64;
// import texture for block sprites.
    texture.loadFromFile("images/15.png");
    emptyBlockSpriteValue = 16;

// Intialize window.
    sf::Vector2u sizeVec (SCREEN_WIDTH, SCREEN_HEIGHT);
    app.setSize(sizeVec);
    // app. , "15-Puzzle";
    app.setFramerateLimit(60);    

// import texture for win banner.
    youWinBanner.loadFromFile("images/winner.png");
    winner.setTexture(youWinBanner);
    // winner.set sf::IntRect(0, 0, 255, 255));
    
// Define Sprite array.
    SpritesInit();

// Randomizing grid.
    RandomizeGrid();
};

void Puzzle::Play(){
// --- Initialization ---
    Init();
    
// Start Game
    continueGame = true;

// Display Screen
    app.clear();
    app.display();    
    while(app.isOpen() && continueGame){
        UpdateScreen();
        CheckInput();
        CheckWin();
    }

    // if win then show banner and end game
    app.draw(winner);
    app.display();
    std::cout << std::endl << "You won!";
    while(app.isOpen()){
        sf::Event event;
        while (app.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) app.close();
        }
    } 
}

int main(){
    Puzzle game;
    game.Play();
    return 0;
}