#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
int main()
{
    float radius = 0;
    int x = 0, y = 0, pol;
    cin >> radius >> pol >> x >> y;

    RenderWindow window(VideoMode(800, 800), "SFMLworks");

    CircleShape circ(radius, pol);
    circ.setPosition(x, y);
    circ.setFillColor(Color::Blue);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(circ);
        window.display();
    }

    return 0;
}
