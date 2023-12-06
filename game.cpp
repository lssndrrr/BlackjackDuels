#include "game.hpp"

game::game(){
    this->intWin();
    this->intTex();
    this->intVar(); 
}

game::~game()
{
    delete window;
}

void game::intVar(){
    this->state = gameState::mainMenu;
    this->numPlayers = 0;
    this->lose = false;
    this->stand = false;
    this->i = 1;
    this->jackFlag = 0;
    this->jakeFlag = 0;
    this->jacksonFlag = 0;
    this->jadeFlag = 0;
    this->paused = false;

    Vector2f heartSize = dead.getGlobalBounds().getSize();
    float initPos = jackSprite.getGlobalBounds().width + 125.f;

    for(int x = 0; x < 10; x++) {
        deaths.push_back(dead);
        deaths[x].setPosition(initPos + ((heartSize.x + 10.f) * x), window->getSize().y - heartSize.y - 40.f);

        lives.push_back(life);
        lives[x].setPosition(initPos + ((heartSize.x + 10.f) * x), window->getSize().y - heartSize.y - 40.f);
    }

    pauseText.setFont(font);
    pauseText.setString("PAUSED");
    pauseText.setFillColor(Color::Red);
    pauseText.setCharacterSize(100);
    pauseText.setPosition((window->getSize().x / 2) - (pauseText.getGlobalBounds().width / 2), (window->getSize().y / 2) - (pauseText.getGlobalBounds().height / 2 + 25.f));
    
    bustText.setFont(font);
    bustText.setString("BUST!");
    bustText.setFillColor(Color::Red);
    bustText.setCharacterSize(100);
    bustText.setPosition((window->getSize().x / 2) - (bustText.getGlobalBounds().width / 2), (window->getSize().y / 2) - (bustText.getGlobalBounds().height / 2));

    loseText.setFont(font);
    loseText.setString("BUST!");
    loseText.setFillColor(Color::Red);
    loseText.setCharacterSize(100);
    loseText.setPosition((window->getSize().x / 2) - (bustText.getGlobalBounds().width / 2), (window->getSize().y / 2) - (bustText.getGlobalBounds().height / 2));

    winner.setFont(font);
    winner.setFillColor(Color::White);
    winner.setCharacterSize(100);
}

void game::intWin(){
    this->window = NULL;

    this->video.height = 720;
    this->video.width = 1280;
    this->window = new RenderWindow(this->video, "Blackjack Duels!", Style::Default);
    this->view = View(FloatRect(0.f, 0.f, 1280.f, 720.f));
    this->window->setVerticalSyncEnabled(false);
}

const bool game::running() const{
    return this->window->isOpen();
}

void game::run(){
    while (running()){
        update();
        render();
    }
}


void game::update(){
    if (state == gameState::mainMenu) {
        updateMainMenu();
    }
    else if(state == tutorialScreen){
        updateTutorial();
    }
    else if (state == gameState::chooseNumPlayersScreen) {
        updateChooseNumPlayers();
    }
    else if(state == gameState::chooseCharScreen) {
        updateChooseCharScreen();

        if(i == 2)
            num.setString("PLAYER 2");
        else if(i == 3)
            num.setString("PLAYER 3");
        else if(i == 4)
            num.setString("PLAYER 4");

        num.setPosition(((float)window->getSize().x - num.getGlobalBounds().width)/2, 140.f);

        if(i == numPlayers) {
            nextButton.text.setString("Start!");
            float NBtextPosX = (window->getSize().x - nextButton.btn.getLocalBounds().width) / 2 + (nextButton.btn.getLocalBounds().width / 2.f) - (nextButton.text.getLocalBounds().width / 2.f);
            float NBtextPosY = (window->getSize().y - nextButton.btn.getLocalBounds().height) / 2 + 250.5f + (nextButton.btn.getLocalBounds().height / 2.f) - (nextButton.text.getLocalBounds().height / 2.f + 17.0f);
            nextButton.text.setPosition(NBtextPosX, NBtextPosY);
        }

        if(current == players.playerlist.end())
            state = gameState::mainGameScreen;
    }
    else if (state == gameState::mainGameScreen){
        while(players.playerlist.size() > 1){
            intCardSprites();
            current = players.playerlist.begin();
            highestValue = 0;
            gameDeck.dealCards(&players);

            while(current != players.playerlist.end()){
                cout << "Player " << current->position << endl;
                current->d.displayDeck();
                current->d.findOverallValue();
                cout << "Overall value: " <<current->d.overallValue << endl;
                current->flag = false;

                updateOverallValue();
                updatePlayerNum();

                while(stand == false && lose == false){
                    setDeathIdle();
                    setCandle(); //found in textures.cpp
                    setDashboard();
                    updateGameEvent();

                    if(this->paused) {
                        this->state = gameState::pauseScreen;
                        while(this->paused) {
                            updatePauseScreen();
                            renderPauseScreen();
                        }
                    }
                    else
                        renderMainGame();

                    if(current->d.overallValue > 21){
                        cout << "Bust!" << endl;
                        lose = true;
                        current->flag = true;

                        bust.restart();
                        while(bust.getElapsedTime().asMilliseconds() < 500)
                            renderBust();
                    }

                    if(lose){
                        if(current->health > 10) {
                            current->health = current->health - 10;
                        } 
                        else {
                            players.transferPlayer(current, &defeated);
                        }
                    }
                }

                stand = lose = false;

                if(highestValue < current->d.overallValue && current->d.overallValue < 22){
                    highestValue = current->d.overallValue;
                }

                current++;
            }

            current = players.playerlist.begin();
            while(current != players.playerlist.end()){
                if(highestValue > current->d.overallValue && current->flag != true){
                    if(current->health > 10){
                        current->health -= 10;
                    } 
                    else{
                        players.transferPlayer(current, &defeated);
                    }
                } else{
                    current->flag = false;
                }
                current->d.cards.clear();
                ++current;
            }
            cout << "Current standing:" << endl;
            players.displayPlayers();
            cout << endl;
        }
        
        if(players.playerlist.size() == 1)
            state = gameState::winScreen;
        else if(players.playerlist.size() == 0)
            state = gameState::loseScreen;

        //if playerlist.getSize == 1 -> state = winScreen
        //if playerlist.getSize == 0 -> state = loseScreen
    }
    else if (state == gameState::winScreen) {
        std::stringstream winText;

        winText << "PLAYER " << players.playerlist.front().position << " WINS!";

        winner.setString(winText.str());
        winner.setPosition((window->getSize().x / 2) - (bustText.getGlobalBounds().width / 2), (window->getSize().y / 2) - (bustText.getGlobalBounds().height / 2));
        
    }
    else if(state == gameState::loseScreen) {

    }
}

void game::render(){
    this->window->clear();
    if (state == gameState::mainMenu) {
        renderMainMenu();
    } else if(state == tutorialScreen){
        window->draw(mainMenuBG);
        backButton.drawButton(*window);
        window->draw(Tutorial);
    }
    else if (state == gameState::chooseNumPlayersScreen) {
        renderChooseNum();
    }
    else if(state == gameState::chooseCharScreen) {
        renderChooseChar();
    }
    else if (state == gameState::pauseScreen) {
        renderPauseScreen();
    }
    else if (state == gameState::winScreen) {
        window->draw(winner);
    }
    else if(state == gameState::loseScreen) {
        window->draw(loseText);
    }

    this->window->display();
}