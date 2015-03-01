#include <SDL.h>
#include <iostream>
#include <cmath>

class Rasterizer
{
private:

	SDL_Window * window;
	SDL_Renderer * renderer;

	void init();
	
public:
	Rasterizer(int screen_width, int screen_height);
	~Rasterizer();
	void setPixel(int x, int y, SDL_Color &color);
	void drawLine(int x1, int y1, int x2, int y2, SDL_Color &color);
	void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, SDL_Color &color);
	void Rasterizer::drawQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, SDL_Color &color);
	void clearScreen(SDL_Color &color);
	void update();

};

/*
TODO
----------------------
Make Own Struct For <-Dont do
COLORS
POINTS
TRIANGLES
RECTS

Actually make own struct for vectors and matracies like glm:http://glm.g-truc.net/0.9.6/index.html
For Example vec2,vec3,vec4, mat2, mat3, and mat4

Actually find a math library like Eigen:http://eigen.tuxfamily.org/index.php?title=Main_Page
More info:http://scicomp.stackexchange.com/questions/351/recommendations-for-a-usable-fast-c-matrix-library

NOTE
-----------------------
3D may be done with matricies, more specifficaly the perspectie projection matrix.
The three matricies are model, view and (perspective) projection matricies.
Here is a link: http://learnopengl.com/#!Getting-started/Coordinate-Systems

*/