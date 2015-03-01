#include "rasterizer.h"

Rasterizer::Rasterizer(int screen_width, int screen_height)
{
	init();

	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Color black = { 0, 0, 0, 0xFF };
	clearScreen(black);
}

Rasterizer::~Rasterizer()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = NULL;
	renderer = NULL;
	SDL_Quit();
}

void Rasterizer::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("SDL could not initialize! SDL_Error %s\n", SDL_GetError());
}

void Rasterizer::setPixel(int x, int y, SDL_Color &color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer, x, y);
}

void Rasterizer::drawLine(int x1, int y1, int x2, int y2, SDL_Color &color)
{
	int dy = y2 - y1;
	int dx = x2 - x1;
	

	if (dx == 0 && dy == 0) //????
	{
		setPixel(x1, y1, color);
		return;
	}
		

	
	if (abs(dx) > abs(dy)) //Why this line
	{
		int xmin, xmax;

		if (x1 < x2)
		{
			xmin = x1;
			xmax = x2;
		}

		else
		{
			xmin = x2;
			xmax = x1;
		}

		float m = (float)dy / (float)dx;
		for (int x = xmin; x <= xmax; x++)
		{
			float y = y1 + (m*(x - x1)); //why x - x1? point slope?
			setPixel(x, round(y), color);
		}

	}

	else
	{
		int ymin, ymax;

		if (y1 < y2) {
			ymin = y1;
			ymax = y2;
		}

		else 
		{
			ymin = y2;
			ymax = y1;
		}

		float mReciprocal = (float)dx / (float)dy;
		for (int y = ymin; y < ymax; y++)
		{
			float x = x1 + ((y - y1) * mReciprocal); //Explain and why recipricol?
			setPixel(round(x), y, color);
		}
	}
}

void Rasterizer::drawTriangle(int x1, int y1, 
							  int x2, int y2, 
							  int x3, int y3, SDL_Color &color) //Draw Triangle
{
	drawLine(x1, y1, x2, y2, color);
	drawLine(x2, y2, x3, y3, color);
	drawLine(x3, y3, x1, y1, color);
	
	/*setPixel(x1, y1, color);
	setPixel(x2, y2, color);
	setPixel(x3, y3, color);*/
	
}
void Rasterizer::drawQuad(int x1, int y1,
						  int x2, int y2,
					      int x3, int y3, 
						  int x4, int y4,
						  int x5, int y5,
						  int x6, int y6,
						  SDL_Color &color)
{
	drawTriangle(x1, y1, x2, y2, x3, y3, color);
	drawTriangle(x4, y4, x5, y5, x6, y6, color);
}
void Rasterizer::clearScreen(SDL_Color &color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);
}

void Rasterizer::update()
{
	SDL_RenderPresent(renderer);
}

