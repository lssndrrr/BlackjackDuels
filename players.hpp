#pragma once
#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "header.hpp"
#include "deck.hpp"

class player {
    int health, mana, position, points;
    bool flag = false;
    deck d;
    character c;
    string username;
public:
    player *prev, *next;
    player() {}
    player(int);
    int getPoints();
    string getUsername();
    void setUsername(string);
    friend class playerList;
    friend class deck;
    friend class game;
};

class playerList {
    list<player> playerlist;
public:
    playerList() {}
    void addPlayers(int);
    void transferPlayer(const list<player>::iterator &, playerList *);
    int getHealth(player *);
    int getMana(player *);
    int getPosition(player *);
    int size();
    void displayPlayers();
    friend class game;
    friend class deck;
};

// Record for each player (node)
class Record {
public:
    // Attributes
    string username;
    int points;
    Record *next;

    // Constructor
    Record();
    Record(string, int);
    string getUsername();
    string getPoints();
};

#endif // !PLAYERS_HPP
