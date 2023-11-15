#include <iostream>
#include <SFML/Graphics.hpp>
#include <filesystem>

sf::RenderWindow window;
sf::Event windowevents;
sf::Sprite background;
sf::Sprite flappy;
sf::Texture background_texture;
sf::Texture flappy_texture;
sf::Color windowColor(100, 155, 200);
int main()
{
    if(!background_texture.loadFromFile("sprite_textures/flappy_background.png"))
    {
        std::cout << "wrong file location bro" << std::endl;
        return 1;
    }
    if(!flappy_texture.loadFromFile("sprite_textures/flappy_bird_model.png"))
    {
        std::cout << "wrong file location bro" << std::endl;
        return 1;
    }
    window.create(sf::VideoMode(900, 504), "My Window",sf::Style::Close);

    background.setTextureRect(sf::IntRect(0,0,900,504));
    background.setTexture(background_texture);
    background.setColor(sf::Color(255, 255, 255, 200));
    background.setPosition(0,0);

    flappy.setTexture(flappy_texture);
    flappy.setPosition(0,0);
    flappy.setTextureRect(sf::IntRect(0,0,1600,815));
    flappy.setColor(sf::Color(255, 255, 255, 255));
    flappy.setPosition(0,0);
    flappy.setScale(0.07f,0.07f);


    while(window.isOpen())
    {
        while (window.pollEvent(windowevents))
        if(windowevents.type == sf::Event::Closed)
        {
            window.close();
        }
        window.draw(background);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            flappy.move(0,-0.01f);
        }
        flappy.move(0,0.001f);
        window.draw(flappy);
        window.display();
    }
    return 0;
}