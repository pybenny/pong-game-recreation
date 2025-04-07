#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace std;
using namespace sf;
using namespace Keyboard;





int main()
{

    // Create the main window
    RenderWindow window(VideoMode({ 1000, 500 }), "Pong Game");
    Vector2u windowSize = window.getSize();

// RECTANGLES | Players ------------------------------------------------

    // Player 1 | Rectangle 1 Left
    RectangleShape playerOne; // player 1 rectangle
    playerOne.setSize(Vector2f(15.f, 80.f)); // dimensions of P1
    playerOne.setFillColor(Color::Blue); // color of P1
    playerOne.setPosition(Vector2f(0, 200)); // start position of P1

    // Player 2 | Rectangle 2 Right
    RectangleShape playerTwo; // player 2 rectangle
    playerTwo.setSize(Vector2f(15.f, 80.f)); // dimensions of P2
    playerTwo.setFillColor(Color::Red); // color of P2
    playerTwo.setPosition(Vector2f(985, 200)); // start position of P2

// FONT ---------------------------------------------------------

    // graphical text to display
    const Font font("GameBubble.ttf"); // imported font
    Text text(font, "Pong Game", 25); // text size and title
    text.setFillColor(Color::White); // font color
    text.setPosition(Vector2f(440, 0)); // position of text

// GAME INTERFACE ----------------------------------------------

    // graphical display of the pong game
    RectangleShape midCourtLine; // defining the mid court line
    ////int midPoint = Vector2f(windowSize.x - 2);
    midCourtLine.setSize(Vector2f(5.f, windowSize.y));
    midCourtLine.setFillColor(Color::White);
    midCourtLine.setPosition(Vector2f(windowSize.x / 2.f, 0.f));



// MUSIC -------------------------------------------------------

    // Background Music
    Music music("jazz_music.mp3"); // imported jazz mp3
    music.setVolume(10); // volume set to 10/100
    music.play(); // Play the music

// AUDIO ------------------------------------------------------




    // Game Loop
    while (window.isOpen())
    {
        // Process events
        while (const optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<Event::Closed>())
                window.close();
        }



        // Left player rectangle movement W/A Keys
        if (Keyboard::isKeyPressed(Keyboard::Key::W))
        {
            playerOne.move(Vector2f(0.f, -0.12f)); // moves up
        }
        else if (Keyboard::isKeyPressed(Keyboard::Key::S))
        {
            playerOne .move(Vector2f(0.f, 0.12f)); // moves down
        }

        // Right player rectangle movement Up/Down Keys
        if (Keyboard::isKeyPressed(Keyboard::Key::Up))
        {
            playerTwo.move(Vector2f(0.f, -0.12f)); // moves up
        }
        else if (Keyboard::isKeyPressed(Keyboard::Key::Down))
        {
            playerTwo.move(Vector2f(0.f, 0.12f)); // moves down
        }



        // parameter boundaries for playerOne rectangle
        if (playerOne.getPosition().y < 0.f) {
            playerOne.setPosition(Vector2f(playerOne.getPosition().x, 0.f));
        }
        else if (playerOne.getPosition().y + playerOne.getSize().y > windowSize.y) {
            playerOne.setPosition(Vector2f(playerOne.getPosition().x, windowSize.y - playerOne.getSize().y));
        }

        // parameter boundaries for playerTwo rectangle
        if (playerTwo.getPosition().y < 0.f) {
            playerTwo.setPosition(Vector2f(playerTwo.getPosition().x, 0.f));
        }
        else if (playerTwo.getPosition().y + playerTwo.getSize().y > windowSize.y) {
            playerTwo.setPosition(Vector2f(playerTwo.getPosition().x, windowSize.y - playerTwo.getSize().y));
        }



        // Clear screen
        window.clear();

        // Draw the mid court line
        window.draw(midCourtLine);

        // Draw the pongs/player rectangles
        window.draw(playerOne);
        window.draw(playerTwo);

        // Draw the text
        window.draw(text);

        // Update the window
        window.display();
    }
    return 0;
}