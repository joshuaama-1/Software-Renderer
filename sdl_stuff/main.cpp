#pragma once
#include "rasterizer.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[])
{
	SDL_Color black = { 0, 0, 0, 0xFF };
	SDL_Color green = { 0, 0xFF, 0, 0xFF };
	Rasterizer * mRasterizer = new Rasterizer(SCREEN_WIDTH, SCREEN_HEIGHT);

	mRasterizer->clearScreen(black);
	/*Test functions*/
	//mRasterizer->drawLine(0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2, red);
	//mRasterizer->drawLine(50, 100 , 80, 500, green);

	/*Real Functions*/
	//mRasterizer->setPixel(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, green);
	//mRasterizer->drawLine(50, 50, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50, green);
	//mRasterizer->drawTriangle(100, 100, 400, 100, 250, 300, green);
	mRasterizer->drawQuad(100, 100, 500, 100, 100, 400, 100, 400, 500, 400, 500, 100, green);

	mRasterizer->update();
	

	SDL_Delay(5000);

	if (mRasterizer != NULL)
	{
		delete mRasterizer;
		mRasterizer = NULL;
	}
	return 0;
}
