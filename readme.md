# Tween+

A basic tween class for tweening.

# Linear tween demo

![demo.cpp](linear_demo.gif)

# Info

### Create a tween:
```cpp
auto* tween = new Tween(); // Tween* tween = new Tween();
```

### Transition types:
```
Linear
Sine
Cubic
Quint
Circ
Elastic
Quad
Quart
Expo
Back
Bounce
```

### Ease types:
```
In
Out
In out
Out in
```

# Example

### Text example:
```cpp
#include <iostream>
#include "tween.hpp"
#include "easing.hpp"

int main()
{
    {
        bool loop = true;
        float a = 27;
        float b = 68;

        auto* tween = new Tween();

        tween->tween(&a, 100.0f, 2.0f);
        tween->interval(1.0f);
        tween->tween(&b, -200.0f, 0.75f, TransitionType::Back, EaseType::OutIn);
        tween->interval(2.5f);
        tween->callback([&]() -> void
        {
            loop = false;
        });
        tween->start();

        while (loop)
        {
            std::cout << "a: " << a << " b: " << b << std::endl;
        }

        std::cout << "a: " << a << " b: " << b << std::endl;
    }

    {
        bool loop = true;
        float a = -34;
        float b = -5097;

        auto* tween = new Tween();

        tween->tween(&a, -100, 1.95f, TransitionType::Elastic, EaseType::Out);
        tween->tween(&b, 0.0f, 5.0f);
        tween->callback([&]() -> void
        {
            loop = false;
        });
        tween->start(true);

        while (loop)
        {
            std::cout << "a: " << a << " b: " << b << std::endl;
        }

        std::cout << "a: " << a << " b: " << b << std::endl;
    }

    return 0;
}
```

### Visual example:
```cpp
#include <SFML/Graphics.hpp>
#include "tween.hpp"
#include "easing.hpp"

void tween(sf::Vector2f& from, const sf::Vector2f& to, float duration, bool& finished)
{
    auto* tween = new Tween();

    tween->tween(&from.x, to.x, duration);
    tween->tween(&from.y, to.y, duration);
    tween->callback([&]() -> void
    {
        finished = true;
    });
    tween->start(true);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(680, 320), "Tween Demo");
    window.setFramerateLimit(60);

    sf::RectangleShape shape;
    shape.setSize({20.0f, 20.0f});
    shape.setOrigin({10.0f, 10.0f});

    bool finished_to = false;
    bool finished_from = true;
    sf::Vector2f position {150, 75};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (finished_from)
        {
            finished_from = false;
            tween(position, {450, 225}, 1.0f, finished_to);
        }

        if (finished_to)
        {
            finished_to = false;
            tween(position, {150, 75}, 1.0f, finished_from);
        }

        shape.setPosition(position);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return EXIT_SUCCESS;
}
```

# Reference

- https://easings.net/
- http://robertpenner.com/easing/
- https://github.com/nicolausYes/easing-functions
- https://blog.w3cub.com/easing/
- https://github.com/nobrelli/tweener
