#include "Turtle.h"
#include <stdexcept>

#define radian2degree(a) (a * 57.295779513082) // need these for Turtle::forward
#define degree2radian(a) (a * 0.017453292519)


Turtle::Turtle() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		throw std::runtime_error("SDL_Init(SDL_INIT_VIDEO)");
}

Turtle::~Turtle() { // Destroys the drawing window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Turtle::windowMake(int windowWidth, int windowHeight) {
	SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS, &window, &renderer);
	SDL_SetWindowPosition(window, 65, 126);
}

void Turtle::forward(double value) {
	auto nx = x + value * cos(degree2radian(a));
	auto ny = y + value * sin(degree2radian(a));
	SDL_RenderDrawLine(renderer, x, y, nx, ny);
	x = nx;
	y = ny;
}

void Turtle::left(double value) {
	a -= value;
}

void Turtle::right(double value) {
	a += value;
}

void Turtle::move(double value, double value2, double value3) {
	x = value;
	y = value2;
	a = value3;
}

void Turtle::clear() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Turtle::flush() {
	SDL_RenderPresent(renderer);
}