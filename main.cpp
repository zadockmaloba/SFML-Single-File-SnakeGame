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

class Snek
{
private:
    int segNum;
    const bool snkHeadColor = true, snkBodyColor = false;
    sf::Vector2f beginPos;
    
public://vars
    std::vector<sf::RectangleShape> snekSegs;
    std::vector<sf::Vector2f> snekSegLoc;
    
public:// functions
    Snek(sf::RenderWindow *snWin, sf::Vector2f innitLoc);
    ~Snek();
    void moveSnek(sf::Vector2f dirvec);
    
private:
    void innitSnek();
    void drawBody();
    void growSnek();
};

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

//=================================================================================

void gameLoop(sf::RenderWindow* buff);

//implementations

int main(int argc, char **argv) {
    
    sf::RenderWindow xWin(sf::VideoMode({400,400}), "SNek Game", sf::Style::Close);
    
    gameLoop(&xWin);
    
    return 0;
}

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
