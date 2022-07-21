#pragma once
#include <SDL.h>

class Turtle
{
public:
	Turtle(); // Constructor
	~Turtle(); // Destructor
	void forward(double);
	void left(double);
	void right(double);
	void clear();
	void flush();
	void move(double x, double y, double a);
	void windowMake(int, int);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	double x = windowHeight / 2;
	double y = windowWidth / 2;
	double a = 0;
	int windowWidth;
	int windowHeight;
};


