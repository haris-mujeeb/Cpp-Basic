#include <SFML/Graphics.hpp>
#include <iostream>



int main(){

    const unsigned int SCREEN_WIDTH = 256;
    const unsigned int SCREEN_HEIGHT = 256;
    const int BLOCK_WIDTH = 64;
    const int BLOCK_HEIGHT = 64;
    sf::RenderWindow app(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "15-Puzzle");
    app.setFramerateLimit(60);
// import texture
    sf::Texture texture;
    texture.loadFromFile("images/15.png");
// designate sprites
    int grid[16];
    int emptyBlockSpriteValue = 16;
    sf::Sprite sprites[16];
    for (int y=0; y<4; y++){
        for(int x=0; x <4; x++){
            sprites[y*4 + x].setTexture(texture);
            sprites[y*4 + x].setTextureRect(sf::IntRect(x*BLOCK_WIDTH, y*BLOCK_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT));
            grid[y*4 + x] = y*4 + x + 1;
        }
    }
//  randomize the grid.
    // std::srand(std::time(nullptr)); // use current time as seed.
    // for(int i = 0; i<16; i++){
    //     int n = std::rand()%16;
    //     int temp = grid[i];
    //     grid[i] = grid[n];
    //     grid[n] = temp; 
    // }
    grid[14] = 16;
    grid[15] = 15;
    bool continueGame = true;
    // intialize window
    while(app.isOpen() && continueGame){
        // Rendering
        app.clear(sf::Color::White);
        for(int i = 0; i < 16; i++){
            int n = grid[i];
            // darwing n numbered sprite on the screen.
            sprites[n-1].setPosition((i%4)*BLOCK_WIDTH, (i/4)*BLOCK_WIDTH);
            app.draw(sprites[i]);
        }
        app.display();

        // Checking for input.
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
        // check win condition.
        int count =0;
        for(int i = 0; i<16; i++) 
            if(grid[i] == i+1) 
                count++;
        if(count == 16) continueGame = false;
    }

    sf::Texture youWinBanner;
    youWinBanner.loadFromFile("images/winner.png");
    sf::Sprite winner(youWinBanner, sf::IntRect(0, 0, 255, 255));
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
    return 0;
}