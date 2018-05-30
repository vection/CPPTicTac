
#include <fstream>
#include <cmath>
#include <chrono>
#include <thread>
#include "Board.h"
using namespace cv;

typedef unsigned char uint8_t;

struct RGB {
	uint8_t red, green, blue;
public:
	RGB() : red(255), green(255), blue(255) {}
	RGB(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}
};

class Image {
public:
	RGB * colors;
	Mat image;
	int mypixels;
	int current_pixel;
	int pixel_per_object;

	void draw(Board& board);
	void drawX();
	void drawO();
	void check(int n);

	Image() {
		mypixels = 0;
		current_pixel = 0;
		pixel_per_object = 0;
	}
	Image(int pixels) {
		colors = new RGB[pixels*pixels];
		mypixels = pixels;
		current_pixel = 0;
		image = Mat(cvSize(pixels, pixels), CV_8UC1);
	}
};