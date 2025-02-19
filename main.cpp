#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Saad's Window");

    // storing all particles inside of a vector
	std::vector<sf::RectangleShape> particles;

    while (window.isOpen())
    {
        // event handling
        while (const std::optional<sf::Event> event = window.pollEvent())
        {   
            // check for mouse pressed events
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    // create new particle
                    sf::RectangleShape particle;

                    // particle properties
                    particle.setSize({ 50.f, 50.f });
                    particle.setFillColor(sf::Color::White);
                    particle.setPosition(
                        sf::Vector2f(static_cast<float>(mouseButtonPressed->position.x) - 25.f,
                        static_cast<float>(mouseButtonPressed->position.y) - 25.f));

                    particles.push_back(particle);
                }
            }

            // check for keyboard pressed events
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

                // if R is pressed
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                    particles.clear();
                }

                // if escape is pressed
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                    window.close();
                }
            }
            // if the window is closed normally
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // clear the window
        window.clear();

        // draw all particles
        for (const auto& particle : particles) {
            window.draw(particle);
        }

        // display the window
        window.display();
    }

    return 0;
}