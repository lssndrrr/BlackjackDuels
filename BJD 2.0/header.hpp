#pragma once
#ifndef HEADER_HPP
#define HEADER_HPP

/*
In the previous edition of the project, everything was here. for a bit more structure, it is now split into separate header files and this is where we find the includes.
*/

#include <iostream>
#include <random>
#include <vector>
#include <memory>
#include <bitset>
#include <array>
#include <deque>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include "SDL.h"
#include "SDL_image.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::stack;
using std::deque;
using std::list;


//class playerList;
//
//// deck
//enum suit{
//    clubs,
//    diamonds,
//    hearts,
//    spades
//};
//
//enum rank{
//    ace,
//    jack,
//    two,
//    three,
//    four,
//    five,
//    six,
//    seven, 
//    eight,
//    nine,
//    ten,
//    queen,
//    king
//};
//
//class card{
//    suit s;
//    rank r;
//    int value;
//    Sprite *cardSprite;
//public:
//    friend class deck;
//    friend class game;
//};
//
//class deck{
//    deque <card> cards;
//    int overallValue;
//public:
//    deck(); 
//    void gameDeck();
//    int cardValue(rank);
//    void findOverallValue();
//    void hitDeck(deck*);
//    void shuffle();
//    void dealCards(playerList*); 
//    string getSuit(suit);
//    string getRank(rank);
//    void displayDeck();
//    friend class game;
//};
//
////character
//enum charType {
//    jackChar,
//    jakeChar,
//    jacksonChar,
//    jadeChar,
//    none
//};
//
//class character {
//    public:
//        charType type = none;
//        Sprite *charSprite;
//        string name;
//};
//
//
//// player
//class player{
//    int health, mana, position;
//    bool flag;
//    deck d;
//    character c;
//public:
//    player *prev, *next;
//    player(int);
//    friend class playerList;
//    friend class deck;
//    friend class game;
//};
//
//class playerList{
//    list<player> playerlist;
//public:
//    playerList(); 
//    void addPlayers(int);
//    void transferPlayer(const list<player>::iterator&, playerList*);
//    int getHealth(player*);
//    int getMana(player*);
//    int getPosition(player*);
//    void displayPlayers();
//    friend class game;
//    friend class deck;
//};
//
#endif