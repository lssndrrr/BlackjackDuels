//#include "game.hpp"
//
//
//void game::updateMouse(){
//    this->mousePosW = Mouse::getPosition(*this->window);
//    this->mousePosV = this->window->mapPixelToCoords((this->mousePosW));
//}
//
//void game::updateMainMenu(){
//    while (this->window->pollEvent(this->event)) {
//        switch (this->event.type){
//            case Event::Closed:
//                window->close();
//                break;
//            case Event::KeyPressed:
//                if(this->event.key.code == Keyboard::Escape)
//                    window->close();
//                break;
//            case Event::Resized:
//                aspectRatio = static_cast<float>(event.size.width) / event.size.height;
//                viewWidth, viewHeight;
//                if(aspectRatio > 16.f / 9.f){
//                    viewHeight = static_cast<float>(event.size.height);
//                    viewWidth = viewHeight * (16.f / 9.f);
//                } else{
//                    viewWidth = static_cast<float>(event.size.width);
//                    viewHeight = viewWidth / (16.f / 9.f);
//                }
//                this->view.setSize(viewWidth, viewHeight);
//                window->setSize(Vector2u(viewWidth, viewHeight));
//                break;
//            case Event::MouseMoved:
//                if (playButton.isMouseOver(*window)){
//                    playButton.setTextColor(Color::Green);
//                } else {
//                    playButton.setTextColor(Color::Black);
//                }
//                if (tutorialButton.isMouseOver(*window)){
//                    tutorialButton.setTextColor(Color::Green);
//                } else {
//                    tutorialButton.setTextColor(Color::Black);
//                }
//                break;
//
//            case Event::MouseButtonPressed:
//                if (this->event.mouseButton.button == Mouse::Left && playButton.isMouseOver(*window)){
//                    state = chooseNumPlayersScreen;
//                } else if(this->event.mouseButton.button == Mouse::Left && tutorialButton.isMouseOver(*window)){
//                    state = tutorialScreen;
//                }
//                break;
//
//            default:
//                break;
//        }
//    }
//}
//
//void game::updateTutorial(){
//    while (this->window->pollEvent(this->event)) {
//        switch (this->event.type){
//            case Event::Closed:
//                window->close();
//                break;
//            case Event::KeyPressed:
//                if(this->event.key.code == Keyboard::Escape)
//                    window->close();
//                break;
//            case Event::Resized:
//                aspectRatio = static_cast<float>(event.size.width) / event.size.height;
//                viewWidth, viewHeight;
//                if(aspectRatio > 16.f / 9.f){
//                    viewHeight = static_cast<float>(event.size.height);
//                    viewWidth = viewHeight * (16.f / 9.f);
//                } else{
//                    viewWidth = static_cast<float>(event.size.width);
//                    viewHeight = viewWidth / (16.f / 9.f);
//                }
//                this->view.setSize(viewWidth, viewHeight);
//                window->setSize(Vector2u(viewWidth, viewHeight));
//                break;
//            case Event::MouseMoved:
//                if (backButton.isMouseOver(*window)){
//                    backButton.setTextColor(Color::Green);
//                } else {
//                    backButton.setTextColor(Color::Black);
//                }
//                break;
//
//            case Event::MouseButtonPressed:
//                if (this->event.mouseButton.button == Mouse::Left && backButton.isMouseOver(*window)){
//                    state = mainMenu;
//                }
//                break;
//
//            default:
//                break;
//        }
//    }
//}
//
//void game::updateChooseNumPlayers() {
//    while (this->window->pollEvent(this->event)) {
//        if (this->event.type == Event::Closed) {
//            window->close();
//        }
//        else if (this->event.type == Event::KeyPressed) {
//            if (this->event.key.code == Keyboard::Escape) {
//                window->close();
//            }
//        }
//        else if (this->event.type == Event::Resized) {
//            aspectRatio = static_cast<float>(event.size.width) / event.size.height;
//            viewWidth, viewHeight;
//            if (aspectRatio > 16.f / 9.f) {
//                viewHeight = static_cast<float>(event.size.height);
//                viewWidth = viewHeight * (16.f / 9.f);
//            }
//            else {
//                viewWidth = static_cast<float>(event.size.width);
//                viewHeight = viewWidth / (16.f / 9.f);
//            }
//            this->view.setSize(viewWidth, viewHeight);
//            window->setSize(Vector2u(viewWidth, viewHeight));
//        }
//        else if (this->event.type == Event::MouseMoved) {
//            if(numPlayers != 0){
//                if(nextButton.isMouseOver(*window)){
//                    nextButton.setTextColor(Color::Green);
//                }
//                else{
//                    nextButton.setTextColor(Color::Black);
//                }
//            }
//            else{
//                if(nextButton.isMouseOver(*window)){
//                    nextButton.setTextColor(Color::Yellow);
//                }
//                else{
//                    nextButton.setTextColor(Color::Black);
//                }
//            }
//
//            if (twoP.isMouseOver(*window)) {
//                threeP.btn.setOutlineColor(sf::Color::Transparent);
//                fourP.btn.setOutlineColor(sf::Color::Transparent);
//                twoP.btn.setOutlineThickness(2.f);
//                twoP.btn.setOutlineColor(sf::Color::Red);
//            } else if (threeP.isMouseOver(*window)){
//                twoP.btn.setOutlineColor(sf::Color::Transparent);
//                fourP.btn.setOutlineColor(sf::Color::Transparent);
//                threeP.btn.setOutlineThickness(2.f);
//                threeP.btn.setOutlineColor(sf::Color::Red);
//            } else if (fourP.isMouseOver(*window)) {
//                twoP.btn.setOutlineColor(sf::Color::Transparent);
//                threeP.btn.setOutlineColor(sf::Color::Transparent);
//                fourP.btn.setOutlineThickness(2.f);
//                fourP.btn.setOutlineColor(sf::Color::Red);
//            }
//            else {
//                twoP.btn.setOutlineColor(sf::Color::Transparent);
//                threeP.btn.setOutlineColor(sf::Color::Transparent);
//                fourP.btn.setOutlineColor(sf::Color::Transparent);
//            }
//
//
//            if (numPlayers == 2) {
//                twoP.btn.setOutlineColor(sf::Color::Green);
//            }
//            else if (numPlayers == 3) {
//                threeP.btn.setOutlineColor(sf::Color::Green);
//            }
//            else if (numPlayers == 4) {
//                fourP.btn.setOutlineColor(sf::Color::Green);
//            }
//        }
//        else if (this->event.type == Event::MouseButtonPressed) {
//            if (this->event.mouseButton.button == Mouse::Left){
//                if (twoP.isMouseOver(*window)) {
//                    numPlayers = 2;
//                } else if (threeP.isMouseOver(*window)) {
//                    numPlayers = 3;
//                } else if (fourP.isMouseOver(*window)) {
//                    numPlayers = 4;
//                }
//                if (numPlayers != 0 && this->event.mouseButton.button == Mouse::Left) {
//                    if (nextButton.isMouseOver(*window)){
//                        gameDeck.gameDeck();
//                        gameDeck.shuffle();
//                        players.addPlayers(numPlayers);
//                        current = players.playerlist.begin();
//                        state = gameState::chooseCharScreen;
//                    }
//                }
//            }
//        }
//    }
//}
//
//void game::updateChooseCharScreen() {
//    while(this->window->pollEvent(this->event)) {
//        if (this->event.type == Event::Closed) {
//                window->close();
//        }
//        else if (this->event.type == Event::KeyPressed) {
//            if (this->event.key.code == Keyboard::Escape) {
//                window->close();
//            }
//        }
//        else if (this->event.type == Event::Resized) {
//            aspectRatio = static_cast<float>(event.size.width) / event.size.height;
//            viewWidth, viewHeight;
//            if (aspectRatio > 16.f / 9.f) {
//                viewHeight = static_cast<float>(event.size.height);
//                viewWidth = viewHeight * (16.f / 9.f);
//            }
//            else {
//                viewWidth = static_cast<float>(event.size.width);
//                viewHeight = viewWidth / (16.f / 9.f);
//            }
//            this->view.setSize(viewWidth, viewHeight);
//            window->setSize(Vector2u(viewWidth, viewHeight));
//        }
//        else if(this->event.type == Event::MouseMoved) {
//            if(current->c.type == charType::jackChar || current->c.type == charType::jacksonChar || current->c.type == charType::jadeChar || current->c.type == charType::jakeChar) {
//                if(nextButton.isMouseOver(*window)) {
//                    nextButton.setTextColor(Color::Green);
//                }
//                else {
//                    nextButton.setTextColor(Color::Black);
//                }
//            }
//            else {
//                if(nextButton.isMouseOver(*window)) {
//                    nextButton.setTextColor(Color::Yellow);
//                }
//                else {
//                    nextButton.setTextColor(Color::Black);
//                }
//            }
//            
//
//            if(jack.isMouseOver(*window) && !jackFlag) {
//                jake.btn.setOutlineColor(Color::Transparent);
//                jackson.btn.setOutlineColor(Color::Transparent);
//                jade.btn.setOutlineColor(Color::Transparent);
//                jack.btn.setOutlineThickness(2.f);
//                jack.btn.setOutlineColor(Color::Red);
//            }
//            else if(jake.isMouseOver(*window) && !jakeFlag) {
//                jack.btn.setOutlineColor(Color::Transparent);
//                jackson.btn.setOutlineColor(Color::Transparent);
//                jade.btn.setOutlineColor(Color::Transparent);
//                jake.btn.setOutlineThickness(2.f);
//                jake.btn.setOutlineColor(Color::Red);
//            }
//            else if(jackson.isMouseOver(*window) && !jacksonFlag) {
//                jack.btn.setOutlineColor(Color::Transparent);
//                jake.btn.setOutlineColor(Color::Transparent);
//                jade.btn.setOutlineColor(Color::Transparent);
//                jackson.btn.setOutlineThickness(2.f);
//                jackson.btn.setOutlineColor(Color::Red);
//            }
//            else if(jade.isMouseOver(*window) && !jadeFlag) {
//                jack.btn.setOutlineColor(Color::Transparent);
//                jake.btn.setOutlineColor(Color::Transparent);
//                jackson.btn.setOutlineColor(Color::Transparent);
//                jade.btn.setOutlineThickness(2.f);
//                jade.btn.setOutlineColor(Color::Red);
//            }
//            else {
//                jack.btn.setOutlineColor(Color::Transparent);
//                jake.btn.setOutlineColor(Color::Transparent);
//                jackson.btn.setOutlineColor(Color::Transparent);
//                jade.btn.setOutlineColor(Color::Transparent);
//            }
//
//            if(current->c.type == charType::jackChar) {
//                jack.btn.setOutlineThickness(2.f);
//                jack.btn.setOutlineColor(Color::Green);
//            }
//            if(current->c.type == charType::jakeChar) {
//                jake.btn.setOutlineThickness(2.f);
//                jake.btn.setOutlineColor(Color::Green);
//            }
//            if(current->c.type == charType::jacksonChar) {
//                jackson.btn.setOutlineThickness(2.f);
//                jackson.btn.setOutlineColor(Color::Green);
//            }
//            if(current->c.type == charType::jadeChar) {
//                jade.btn.setOutlineThickness(2.f);
//                jade.btn.setOutlineColor(Color::Green);
//            }
//        }
//        else if(this->event.type == Event::MouseButtonPressed) {
//            if(event.mouseButton.button == Mouse::Left) {
//                if(jack.isMouseOver(*window) && !jackFlag) {
//                    current->c.type = charType::jackChar;
//                    jack.btn.setOutlineThickness(2.f);
//                    jack.btn.setOutlineColor(sf::Color::Green);
//                }
//                else if(jake.isMouseOver(*window) && !jakeFlag) {
//                    current->c.type = charType::jakeChar;
//                    jake.btn.setOutlineColor(sf::Color::Green);
//                }
//                else if(jackson.isMouseOver(*window) && !jacksonFlag) {
//                    current->c.type = charType::jacksonChar;
//                    jackson.btn.setOutlineColor(sf::Color::Green);
//                }
//                else if(jade.isMouseOver(*window) && !jadeFlag) {
//                    current->c.type = charType::jadeChar;
//                    jade.btn.setOutlineColor(sf::Color::Green);
//                }
//
//                if(nextButton.isMouseOver(*window) && (current->c.type == charType::jackChar || current->c.type == charType::jacksonChar || current->c.type == charType::jadeChar || current->c.type == charType::jakeChar)) {                  
//                    if(current->c.type == charType::jackChar) {
//                        current->c.charSprite = &jackSprite;
//                        current->c.name = "Jack Black";
//                        jackFlag = 1;
//                    }
//                    else if(current->c.type == charType::jakeChar) {
//                        current->c.charSprite = &jakeSprite;
//                        current->c.name = "Jake Blake";
//                        jakeFlag = 1;
//                    }
//                    else if(current->c.type == charType::jacksonChar) {
//                        current->c.charSprite = &jacksonSprite;
//                        current->c.name = "Jackson Blackson";
//                        jacksonFlag = 1;
//                    }
//                    else if(current->c.type == charType::jadeChar) {
//                        current->c.charSprite = &jadeSprite;
//                        current->c.name = "Jade Blade";
//                        jadeFlag = 1;
//                    }
//                    cout << "Player " << current->position << ": " << current->c.name << endl;
//                    current++;
//                    i++;
//                }
//            }
//        }
//    }
//}
//
//void game::updateGameEvent() {
//    while (window->pollEvent(event)) {
//        if (event.type == Event::Closed) {
//            window->close();
//        } else if (event.type == Event::KeyPressed) {
//            if (event.key.code == Keyboard::Escape) {
//                window->close();
//            }
//        } else if (event.type == Event::Resized) {
//            aspectRatio = static_cast<float>(event.size.width) / event.size.height;
//            viewWidth, viewHeight;
//            if (aspectRatio > 16.f / 9.f) {
//                viewHeight = static_cast<float>(event.size.height);
//                viewWidth = viewHeight * (16.f / 9.f);
//            } else {
//                viewWidth = static_cast<float>(event.size.width);
//                viewHeight = viewWidth / (16.f / 9.f);
//            }
//            this->view.setSize(viewWidth, viewHeight);
//            window->setSize(Vector2u(viewWidth, viewHeight));
//        } else if (event.type == Event::MouseMoved) {
//            if (hitButton.isMouseOver(*window)) {
//                hitButton.setTextColor(Color::Green);
//            } 
//            else if(standButton.isMouseOver(*window)) {
//                standButton.setTextColor(Color::Green);
//            }
//            else {
//                standButton.setTextColor(Color::Black);
//                hitButton.setTextColor(Color::Black);
//            }
//        } else if (event.type == Event::MouseButtonPressed) {
//            if (event.mouseButton.button == Mouse::Left) {
//                if (hitButton.isMouseOver(*window)) {
//                    if (current->d.overallValue < 22) {
//                        gameDeck.hitDeck(&(current->d));
//                        current->d.findOverallValue();
//                    } 
//                    else {
//                        lose = true;
//                    }
//                    cout << endl;
//                    current->d.displayDeck();
//                    cout << endl;
//                    cout << "Overall value: " << current->d.overallValue << endl;
//                    updateOverallValue();
//                } else if (standButton.isMouseOver(*window)) {
//                    cout << "Your current overall value is " << current->d.overallValue << "! Next player!" << endl;
//                    cout << endl;
//                    stand = true;
//                }
//            }
//        }
//    }
//}
//
//void game::updateOverallValue() {
//    std::stringstream ss;
//
//    ss << "Overall Value: " << current->d.overallValue;
//
//    overallValue.setString(ss.str());
//}
//
//void game::updatePauseScreen(){
//    while (this->window->pollEvent(this->event)) {
//        renderMainGame();
//        switch (this->event.type){
//            case Event::Closed:
//                window->close();
//                break;
//            case Event::KeyPressed:
//                if(this->event.key.code == Keyboard::Escape)
//                    window->close();
//                break;
//            case Event::Resized:
//                aspectRatio = static_cast<float>(event.size.width) / event.size.height;
//                viewWidth, viewHeight;
//                if(aspectRatio > 16.f / 9.f){
//                    viewHeight = static_cast<float>(event.size.height);
//                    viewWidth = viewHeight * (16.f / 9.f);
//                } else{
//                    viewWidth = static_cast<float>(event.size.width);
//                    viewHeight = viewWidth / (16.f / 9.f);
//                }
//                this->view.setSize(viewWidth, viewHeight);
//                window->setSize(Vector2u(viewWidth, viewHeight));
//                break;
//            case Event::MouseMoved:
//                if(startButton.isMouseOver(*window)){
//                    startButton.setTextColor(Color::Green);
//                } else {
//                    startButton.setTextColor(Color::Black);
//                }
//                break;
//
//            case Event::MouseButtonPressed:
//                if (this->event.mouseButton.button == Mouse::Left && startButton.isMouseOver(*window)){
//                    state = mainGameScreen;
//                }
//                break;
//
//            default:
//                break;
//        }
//    }
//}
//
//void game::updateWinScreen(){
//    while (this->window->pollEvent(this->event)) {
//        switch (this->event.type){
//            case Event::Closed:
//                window->close();
//                break;
//            case Event::KeyPressed:
//                if(this->event.key.code == Keyboard::Escape)
//                    window->close();
//                break;
//            case Event::Resized:
//                aspectRatio = static_cast<float>(event.size.width) / event.size.height;
//                viewWidth, viewHeight;
//                if(aspectRatio > 16.f / 9.f){
//                    viewHeight = static_cast<float>(event.size.height);
//                    viewWidth = viewHeight * (16.f / 9.f);
//                } else{
//                    viewWidth = static_cast<float>(event.size.width);
//                    viewHeight = viewWidth / (16.f / 9.f);
//                }
//                this->view.setSize(viewWidth, viewHeight);
//                window->setSize(Vector2u(viewWidth, viewHeight));
//                break;
//
//            default:
//                break;
//        }
//    }
//}
//
//void game::renderMainMenu(){
//    window->draw(mainMenuBG);
//    window->draw(Death);
//    window->draw(Title);
//    playButton.drawButton(*window);
//    tutorialButton.drawButton(*window);
//}
//
//void game::renderChooseNum(){
//    window->draw(mainMenuBG);
//    twoP.drawButton(*window);
//    threeP.drawButton(*window);
//    fourP.drawButton(*window);
//    // startButton.drawButton(*window);
//    nextButton.drawButton(*window);
//    window->draw(numHeader);
//}
//
//void game::renderChooseChar(){
//    window->clear();
//    window->draw(mainMenuBG);
//    window->draw(charHeader);
//    window->draw(num);
//    jack.drawButton(*window);
//    jake.drawButton(*window);
//    jackson.drawButton(*window);
//    jade.drawButton(*window);
//    nextButton.drawButton(*window);
//}
//
//void game::renderBust() {
//    window->clear();
//    window->draw(bustText);
//    window->display();
//}
//
//void game::renderMainGame(){
//    window->clear();
//    window->draw(mainGameBGTop);
//    window->draw(deathIdle);
//    window->draw(mainGameBGBottom);
//    window->draw(candle1);
//    window->draw(candle2);
//    window->draw(p);
//    playerDashboard.drawDashboard(*window);
//    hitButton.drawButton(*window);
//    standButton.drawButton(*window);
//
//    for(int x = 0; x < 10; x++) 
//        window->draw(deaths[x]);
//
//    int temp = current->health / 10;
//    // cout << "temp; " << temp << endl;
//    for(int x = 0; x < temp; x++)
//        window->draw(lives[x]);
//
//    renderDeck();
//    
//    window->draw(overallValue);
//
//    window->display();
//}
//
//void game::renderDeck(){
//    const float cardWidth = C0Sprite.getGlobalBounds().width;
//    const float cardHeight = C0Sprite.getGlobalBounds().height;
//
//    const float spacing = C0Sprite.getGlobalBounds().width + 5.f;
//    const float marginLeft = jackSprite.getGlobalBounds().width + 125.f;
//    const float marginTop = window->getSize().y - (playerDashboard.charContainer.getGlobalBounds().height - 2.f);
//
//    if(current->d.cards.size() > 0) {
//        for (int i = 0; i < current->d.cards.size(); i++) {
//            float posX = marginLeft + ((cardWidth + spacing) * i);
//            float posY = marginTop;
//
//            renderCard(current->d.cards[i], posX, posY);
//        }
//    }
//}
//
//void game::renderCard(const card& card, float posX, float posY){
//    card.cardSprite->setPosition(posX, posY);
//    card.cardSprite->setScale(1.8f, 1.8f);
//    window->draw(*(card.cardSprite));
//}