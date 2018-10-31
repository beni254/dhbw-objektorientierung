#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Planet.h"
#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	double x = 0;
	double rot = 0.0;
	double mouse_x;
	double mouse_y;
	Gosu::Image hintergrundbild;
	Gosu::Image rakete;

	GameWindow()
		: Window(800, 600)
		, hintergrundbild(
			"hintergrundbild.png"
		)
		, rakete(
			"rakete.png"
		)
		
	{
		set_caption("Super Smash Bros");


	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		graphics().draw_quad(
		300, 200, Gosu::Color::BLUE, 500, 200, Gosu::Color::BLUE, 500, 250, Gosu::Color::BLUE, 300, 250, Gosu::Color::BLUE, 0
		);
		graphics().draw_quad(
			100, 400, Gosu::Color::BLUE, 300, 400, Gosu::Color::BLUE, 300, 450, Gosu::Color::BLUE, 100, 450, Gosu::Color::BLUE, 0
		); 
		graphics().draw_quad(
			500, 400, Gosu::Color::BLUE, 700, 400, Gosu::Color::BLUE, 700, 450, Gosu::Color::BLUE, 500, 450, Gosu::Color::BLUE, 0
		);


		/*graphics().draw_line(
			mouse_x, mouse_y, Gosu::Color::FUCHSIA,
			mouse_x + 10, mouse_y + 10, Gosu::Color::RED,
			0.0
		);
		graphics().draw_triangle(
			mouse_x - 10, mouse_y - 10, Gosu::Color::BLUE,
			mouse_x - 5, mouse_y + 5, Gosu::Color::YELLOW,
			mouse_x + 5, mouse_y - 5, Gosu::Color::GREEN,
			0.0
		);*/

		hintergrundbild.draw(0, 0, -9999999, 1.2, 1.2);
		rakete.draw_rot(x, 600, 0, 0, 0.5, 0.5, 1.5, 1.5);
	}



	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		mouse_x = input().mouse_x();
		mouse_y = input().mouse_y();
		if (input().down(Gosu::KB_RIGHT))
		{
			x = x + 10;
		}
		else if (input().down(Gosu::KB_LEFT))
		{
			x = x - 10;
		}
	};

};
// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}