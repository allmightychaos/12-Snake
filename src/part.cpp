#include <iostream>

#include "part.h"

using namespace std;

std::string Part::unicode_letters[26] = {"🅐", "🅑", "🅒", "🅓", "🅔", "🅕", "🅖", "🅗", "🅘", "🅙", "🅚", "🅛", "🅜", "🅝", "🅞", "🅟", "🅠", "🅡", "🅢", "🅣", "🅤", "🅥", "🅦", "🅧", "🅨", "🅩"};
    
Part::Part(int x, int y, std::string d, int value)
{
    this->x = x;
    this->y = y;
    this->data = d;
    this->value = value;
    if(value < 0 || value > 25)
    {
        value = 0;
    }
}

void Part::eat()
{
    x = 0;
    y = 0;
    this->data = unicode_letters[value];
}

Part::~Part()
{
    delete next;
}
    
void Part::draw()
{
    if(x != 0 && y != 0)
    {
        cout << "\033[" << y << ";" << x << "H" << data;
    }
    if(next)
    {
        next->draw();
    }
}

void Part::move(int x, int y)
{
    this->x = x;
    this->y = y;
    if(next)
    {
        next->move(this->x, this->y);
    }
}

bool Part::contains(int x, int y)
{
    if(this->x == x && this->y == y)
    {
        return true;
    }
    return false;
}

Part *Part::add(Part *p)
{
    if(!next)
    {
        next = p;
    }
    else
    {
        next->add(p);
    }
    return this;
    return this;
}

Part *Part::get(int x, int y)
{
    if(this->x == x && this->y == y)
    {
        return this;
    }
    return nullptr;
}

Part *Part::remove(int x, int y)
{
    if(this->x == x && this->y == y)
    {
        return next;
    }
    return nullptr;
}