/*
 Вариант 3.
Создайте 3 прямоугольника разных цветов и размеров.
Перемещайте их из исходного положения влево до конца
экрана с разной скорость. При достижении конца экрана
остановите фигуры.
 */

#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1280), L"Летающие прямоугольники! Вау!");

    int x_1 = window.getSize().x, x_2 = window.getSize().x, x_3 = window.getSize().x;

    //прямоугольник первый
    sf::RectangleShape rectangle1(sf::Vector2f(300.f, 150.f));
    rectangle1.setFillColor(sf::Color::Yellow);
    rectangle1.setOrigin(rectangle1.getSize().x/2,rectangle1.getSize().y/2);
    rectangle1.setPosition(x_1,300);

    //прямоугольник второй
    sf::RectangleShape rectangle2(sf::Vector2f(400.f, 200.f));
    rectangle2.setFillColor(sf::Color::Red);
    rectangle2.setOrigin(rectangle2.getSize().x/2,rectangle2.getSize().y/2);
    rectangle2.setPosition(x_2,600);

    //прямоугольник третий
    sf::RectangleShape rectangle3(sf::Vector2f(500.f, 250.f));
    rectangle3.setFillColor(sf::Color::Green);
    rectangle3.setOrigin(rectangle3.getSize().x/2,rectangle3.getSize().y/2);
    rectangle3.setPosition(x_3,900);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(x_1 > 0) // Если нам нужно движение слева направо, то вместо >0 можно написать < window.getSize().x
                    // Сначала я сделал так, поэтому решил поделиться
            x_1-=1;
        rectangle1.setPosition(x_1,300);

        if(x_2 > 0)
            x_2-=2;
        rectangle2.setPosition(x_2,600);

        if(x_3 > 0)
            x_3-=3;
        rectangle3.setPosition(x_3,900);

        window.clear();
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.display();

        std::this_thread::sleep_for(10ms);
    }

    return 0;
}