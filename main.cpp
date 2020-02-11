#include <SFML/Graphics.hpp>
#include <iostream>

#include "Text.h"


/******************Need to add user instructions and Shader Option***********/


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
	//sf::Color color(a, g, b);
	return sf::Color(a, g, b);
}

sf::Color getColorFirst(int a, int g, int b)
{
	return sf::Color(g, b, a);

}

sf::Color getColorSecond(int a, int g, int b)
{
	return sf::Color(a, a, g);
}


int main()
{


	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Color Picker", sf::Style::Close);
	
	//Create texture
	sf::Texture texture;
	texture.create(800, 600);

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
	title.setFillColor(sf::Color::Black);
	title.setFont(font);
	title.setPosition(100.f, 20.f);

	//Labels
	text.setString("Your choosen color!");
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(24);
	text.setPosition(400.f, 100.f);

	sf::Text label2;
	label2.setFont(font);
	label2.setString("Additional Color");
	label2.setFillColor(sf::Color::Black);
	label2.setCharacterSize(24);
	label2.setPosition(400.f, 200.f);

	sf::Text label3;
	label3.setFont(font);
	label3.setString("Additional Color");
	label3.setFillColor(sf::Color::Black);
	label3.setCharacterSize(24);
	label3.setPosition(400.f, 300.f);
	

	
	
	
	//Create the current color choosen, default white
	sf::RectangleShape rectangleMain;
	rectangleMain.setPosition(400.f, 150.f);
	rectangleMain.setSize(sf::Vector2f(40.f, 40.f));

	//Additional color rectangle
	sf::RectangleShape rectangle2;
	rectangle2.setPosition(400.f, 250.f);
	rectangle2.setSize(sf::Vector2f(40.f, 40.f));

	//Additional color rectangle
	sf::RectangleShape rectangle3;
	rectangle3.setPosition(400.f, 350.f);
	rectangle3.setSize(sf::Vector2f(40.f, 40.f));



	sf::CircleShape circle(100);
	circle.setPosition(50.f, 200.f);
	sf::Texture circleTex;
	circleTex.loadFromFile("image\\circleColor.png");
	circle.setTexture(&circleTex);
	/*circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(1);
	*/



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
				rectangleMain.setFillColor(getColor(colorPoint.r, colorPoint.g, colorPoint.b));
				rectangle2.setFillColor(getColorFirst(colorPoint.r, colorPoint.g, colorPoint.b));
				rectangle3.setFillColor(getColorSecond(colorPoint.r, colorPoint.g, colorPoint.b));
			}

			
		}

		// clear the window with black color
		sf::Color backgroundColor(100, 100, 100);
		window.clear(backgroundColor);

		// draw everything here...
		// window.draw(...);
		window.draw(circle);
		
		texture.update(window);
		window.draw(rectangleMain);
		window.draw(title);
		window.draw(text);
		window.draw(label2);
		window.draw(label3);
		window.draw(rectangle2);
		window.draw(rectangle3);

		// end the current frame
		window.display();

	}

	return 0;
}