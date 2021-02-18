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

struct VectCalc //a container to hold vector calculation functions
{
    static sf::Vector2f translateVector(sf::Vector2f a, sf::Vector2f b);
    static sf::Vector2f rotateVector(sf::Vector2f a, int xtheta);
    static sf::Vector2f dotProduct(sf::Vector2f a, sf::Vector2f b);
    static sf::Vector2f scalarProduct(sf::Vector2f a, int scal);
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
    sf::Vector2f getPixSize();
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
sf::Vector2f VectCalc::translateVector(sf::Vector2f a, sf::Vector2f b)
{
    a = { a.x + b.x, a.y + b.y};
    return a;
}
sf::Vector2f VectCalc::rotateVector(sf::Vector2f a, int xtheta)
{
    //placeholder
    return sf::Vector2f();
}
sf::Vector2f VectCalc::dotProduct(sf::Vector2f a, sf::Vector2f b)
{
    a = { a.x * b.x, a.y * b.y};
    return a;
}
sf::Vector2f VectCalc::scalarProduct(sf::Vector2f a, int scal)
{
    a = {a.x * scal, a.y * scal};
    return a;
}

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

sf::Vector2f Grfx::getPixSize()
{
    return pixSize;
}

//constructor of snek class
Snek::Snek(sf::RenderWindow *snWin, sf::Vector2f innitLoc) 
    :xsnWin(snWin),beginPos(innitLoc), segNum(4)
{
    this->innitSnek();
}
Snek::~Snek() //destructor of snek class
{
    
}
void Snek::innitSnek()
{
    //snekSegLoc.push_back(beginPos);
    for(int i=0; i<segNum; i++)// populate location vector
    {
        snekSegLoc.push_back(VectCalc::dotProduct(beginPos, {(float)i, 0}));
    }
    
    for(int i=0; i<snekSegLoc.size(); i++)// populate rectangle shape vector
    {
        snekSegs.push_back(grz.getRectAt(snekSegLoc[i], 1));
    }
    drawBody();
}

void Snek::drawBody()
{
    for(int i=0; i<snekSegs.size(); i++)
    {
        xsnWin->draw(snekSegs[i]);
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
    //std::cout<<VectCalc::translateVector({2,3},{4,1}).x; test code...
    while(buff->isOpen())
    {
        sf::Event evnts;
        buff->clear();
        while(buff->pollEvent(evnts)) 
        {
            if( evnts.type == sf::Event::Closed ) buff->close();
        }
        //buff->draw(grx.getRectAt({20,20}, 1)); test code
        Snek snk(buff, {80,80});
        buff->display();
        //std::cout<<sf::err()<<std::endl;
    }
}
