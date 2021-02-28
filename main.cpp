/*
 * ====================================
 * = A Simple SFML snake game
 * = Author; Zadock Maloba.
 * = Email: zadockmaloba@outlook.com
 *===================================== 
 */

#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <random>
#include <SFML/Graphics.hpp>


//declarations

struct VectCalc //a container to hold vector calculation functions
{
    static sf::Vector2f translateVector(sf::Vector2f a, sf::Vector2f b);
    static sf::Vector2f rotateVector(sf::Vector2f a, int xtheta);
    static sf::Vector2f dotProduct(sf::Vector2f a, sf::Vector2f b);
    static sf::Vector2f scalarProduct(sf::Vector2f a, int scal);
};

struct CollisionPhx //computations for collision detection
{
    static bool rectCollision(sf::RectangleShape* rA, sf::RectangleShape* rB);
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
    int segNum , gameTik;
    const bool snkHeadColor = true, snkBodyColor = false;
    sf::Vector2f beginPos;
    Grfx grz;
    sf::Clock snclock;
    
public://vars
    std::vector<sf::RectangleShape> snekSegs;
    std::vector<sf::Vector2f> snekSegLoc;
    
public:// functions
    Snek(sf::RenderWindow *snWin, sf::Vector2f innitLoc);
    ~Snek();
    void moveSnek(sf::Vector2f dirvec);
    sf::RectangleShape* ptrSnkHead();
    
private:
    sf::RenderWindow* xsnWin;
    void innitSnek();
    void drawBody();
    void growSnek();
    void snakeOffMap();
};

class Food : public sf::RectangleShape
{
private:
    sf::Color foodCol;
    sf::Vector2f foodLoc;
    sf::RenderWindow* xfnWin;
public:
    void drawFood();
    
public:
    Food(sf::RenderWindow* fnWin, sf::Vector2f innitPos);
    ~Food();
    
public:
    void innitFood();
    void nextFoodLoc();
    sf::Vector2f currentFoodLoc();
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

bool CollisionPhx::rectCollision(sf::RectangleShape* rA, sf::RectangleShape* rB) //implement collisin detection here
{
    sf::Vector2f raPos = rA->getPosition(), rbPos = rB->getPosition();
    if((std::abs(rbPos.x - raPos.x) < 10) && std::abs(raPos.y - rbPos.y) < 10)
    {
        std::cout<<"Collision X-axis ID :: "<<rand()<<std::endl;
        return true;
    }
    else if((std::abs(rbPos.y - raPos.y) < 10) && std::abs(raPos.x - rbPos.x) < 10)
    {
        std::cout<<"Collision Y-axis ID :: "<<rand()<<std::endl;
        return true;
    }
    
    return false;
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
    :xsnWin(snWin),beginPos(innitLoc), segNum(4), gameTik(100)
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
        snekSegLoc.push_back(VectCalc::translateVector(beginPos, VectCalc::dotProduct(this->grz.getPixSize(), {(float)i, 0})));
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

void Snek::moveSnek(sf::Vector2f dirvec)
{   
    this->gameTik += 1;
    
    if (gameTik % 320 == 0){
        for(int i=snekSegLoc.size()-1; i>0; i--)
        {
    //         snekSegLoc[i] = VectCalc::translateVector(snekSegLoc[i], VectCalc::dotProduct({0.08,0.08}, dirvec)); //remember to replace with var
            snekSegLoc[i] = snekSegLoc[i-1];
            snekSegs[i] = grz.getRectAt(snekSegLoc[i], 1);
            //sleep(0.001);
        }
        gameTik =100;
    }
    snekSegLoc[0] = VectCalc::translateVector(snekSegLoc[0], VectCalc::dotProduct({0.1,0.1}, dirvec));
    snekSegs[0] = grz.getRectAt(snekSegLoc[0], 0);
    this->snakeOffMap();
    this->drawBody();
    //snclock.restart();
}

sf::RectangleShape* Snek::ptrSnkHead() 
{
    return &snekSegs[0];
}

void Snek::snakeOffMap() //remember to replace consts with vars
{
    if(snekSegLoc[0].x < 0)//off to the left of screen
    {
        snekSegLoc[0].x = 400;
    }
    else if(snekSegLoc[0].x > 400)
    {
        snekSegLoc[0].x = 0;
    }
    else if(snekSegLoc[0].y < 0)//off to the left of screen
    {
        snekSegLoc[0].y = 400;
    }
    else if(snekSegLoc[0].y > 400)
    {
        snekSegLoc[0].y = 0;
    }
}

Food::Food(sf::RenderWindow* fnWin, sf::Vector2f innitPos) 
: xfnWin(fnWin),foodLoc(innitPos)
{
    this->setFillColor(sf::Color::Red);
    this->setSize({10,10});
    this->setPosition(foodLoc);
}

Food::~Food() 
{
    
}

void Food::innitFood() 
{
    
}

void Food::nextFoodLoc() 
{
    
}

sf::Vector2f Food::currentFoodLoc() 
{
    return this->foodLoc;
}

void Food::drawFood() 
{
    this->xfnWin->draw(*this);
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
    Snek snk(buff, {80,80});
    Food xfd(buff, {100,100});
    sf::Clock xclock;
    //std::cout<<VectCalc::translateVector({2,3},{4,1}).x; test code...
    sf::Vector2f playerDir = {-1,0};
    xclock.restart();

    while(buff->isOpen())
    {
        
        sf::Event evnts;
        buff->clear();
        while(buff->pollEvent(evnts)) 
        {
            if( evnts.type == sf::Event::Closed ) buff->close();
            if( evnts.type==sf::Event::KeyPressed)
            {
                if(evnts.key.code == sf::Keyboard::Left && playerDir.x != 1 ) playerDir = {-1, 0};
                else if(evnts.key.code == sf::Keyboard::Right && playerDir.x!=-1) playerDir = {1, 0};
                else if(evnts.key.code == sf::Keyboard::Up && playerDir.y != 1) playerDir = {0, -1};
                else if(evnts.key.code == sf::Keyboard::Down &&playerDir.y !=-1) playerDir = {0, 1};
            }
        }
        //if (tvar.asMilliseconds() % 100 == 0){
        snk.moveSnek(playerDir);
        xfd.drawFood();
        CollisionPhx::rectCollision(&xfd, snk.ptrSnkHead());
        //}
        buff->display();
        //xclock.restart();
    }
}
//for the love of science
