/*
 * ====================================
 * = A Simple SFML snake game
 * = Author; Zadock Maloba.
 * = Email: zadockmaloba@outlook.com
 *===================================== 
 */

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

//declarations

class Grfx
{
private:
    sf::Vector2f pixSize;
    sf::RectangleShape pixBox;
public://vars
    
public:// functions
    Grfx();
    ~Grfx();
    sf::RectangleShape getRectAt(sf::Vector2f Loc, bool snColor);
};

class RandomEngine
{
    RandomEngine();
    ~RandomEngine();
};

class Snek
{
private:
    int segNum;
    const bool snkHeadColor = true, snkBodyColor = false;
    sf::Vector2f beginPos;
    Grfx grz;
    
public://vars
    std::vector<sf::RectangleShape> snekSegs;
    std::vector<sf::Vector2f> snekSegLoc;
    
public:// functions
    Snek(sf::RenderWindow *snWin, sf::Vector2f innitLoc);
    ~Snek();
    void moveSnek(sf::Vector2f dirvec);
    
private:
    sf::RenderWindow* xsnWin;
    void innitSnek();
    void drawBody();
    void growSnek();
};


//=================================================================================
//class implementations go here...
Grfx::Grfx() : pixSize({20,20})
{
    pixBox.setSize(pixSize);
}
Grfx::~Grfx()
{
    
}
sf::RectangleShape Grfx::getRectAt(sf::Vector2f Loc, bool snColor)
{
    if(snColor) pixBox.setFillColor(sf::Color::Yellow);
    else pixBox.setFillColor(sf::Color::Green);
    pixBox.setPosition(Loc);
    return pixBox;
}

//constructor of snek class
Snek::Snek(sf::RenderWindow *snWin, sf::Vector2f innitLoc) 
    :beginPos(innitLoc), segNum(4)
{
    
}
Snek::~Snek() //destructor of snek class
{
    
}
void Snek::innitSnek()
{
    for(int i=0; i<segNum; i++)// populate location vector
    {
        
    }
    
    for(int i=0; i<segNum; i++)// populate rectangle shape vector
    {
        
    }
}

//=================================================================================

void gameLoop(sf::RenderWindow* buff);

//implementations

//Entry point..
int main(int argc, char **argv) {
    
    sf::RenderWindow xWin(sf::VideoMode({400,400}), "SNek Game", sf::Style::Close);
    
    gameLoop(&xWin);
    
    return 0;
}

//gameloop finction
void gameLoop(sf::RenderWindow* buff)
{
    Grfx grx;
    while(buff->isOpen())
    {
        sf::Event evnts;
        buff->clear();
        while(buff->pollEvent(evnts))
        {
            if( evnts.type == sf::Event::Closed ) buff->close();
        }
        buff->draw(grx.getRectAt({20,20}, 1));
        buff->display();
        //std::cout<<sf::err()<<std::endl;
    }
}
