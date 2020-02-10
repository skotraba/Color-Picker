#include <SFML/Graphics.hpp>
#include <iostream>


//TODO Check if the color clicked is on the color triangle
bool isValidColor(sf::Vector2i location)
{
	if (location.x >= 20 && location.x <= 200 && location.y >= 20 && location.y <= 200)
	{
		return true;
	}
	else
		return false;
}

//Set current color to current color clicked
sf::Color getColor(int a, int g, int b)
{
	sf::Color color(a, g, b);
	return color;
}


int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default);
	sf::Texture texture;

	//Create text
	sf::Text text;
	sf::Font font;
	text.setFont(font);
	font.loadFromFile("pixelFont");
	if (!font.loadFromFile("Font\\pixelFont.ttf"))
	{
		std::cout << "Font not loaded";
	}

	sf::Text title;
	title.setString("Welcome to Color Picker!");
	title.setCharacterSize(40);
	title.setFont(font);
	title.setPosition(100.f, 20.f);


	text.setString("Your choosen color!");
	text.setCharacterSize(24);
	text.setPosition(400.f, 200.f);
	
	
	
	//Create the current color choosen, default white
	sf::RectangleShape rectangle;
	rectangle.setPosition(400.f, 250.f);
	rectangle.setSize(sf::Vector2f(40.f, 40.f));
	
	
	//Triangle color picker
	sf::VertexArray triangle(sf::Triangles, 3);

	triangle[0].position = sf::Vector2f(100.f, 350.f);
	triangle[1].position = sf::Vector2f(350.f, 100.f);
	triangle[2].position = sf::Vector2f(350.f, 350.f);
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;


	// run the program as long as the window is open
	while (window.isOpen())
	{
		
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);
				std::cout << position.x << "," << position.y << "\n" ;
				//std::cout << isValidColor(position) << "\n";
				auto image = texture.copyToImage();
				auto colorPoint = image.getPixel(position.x, position.y);
				std::cout << (int)colorPoint.r << " " << (int)colorPoint.g << " " << (int)colorPoint.b << "\n";
				rectangle.setFillColor(getColor(colorPoint.r, colorPoint.g, colorPoint.b));
			}

			
		}

		// clear the window with black color
		sf::Color backgroundColor(100, 100, 100);
		window.clear(backgroundColor);

		// draw everything here...
		// window.draw(...);
		window.draw(triangle);
		texture.create(800, 600);
		texture.update(window);
		window.draw(rectangle);
		window.draw(title);
		window.draw(text);

		// end the current frame
		window.display();

	}

	return 0;
}