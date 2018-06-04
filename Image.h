#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned char uint8_t;


struct RGB {
	uint8_t red, green, blue;
public:
	RGB() : red(255), green(255), blue(255) {}
	RGB(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}
};

class Image {
public:
	int pixels;
	RGB* colors;
	void Xpaint(int row, int col, int pixels);
	void Opaint(int row, int col, int pixels);
	void saveImage(string file);

	Image(int n);
	~Image();
	string createImage(char* board, int size);
	void createCanvas(int size);

	void paintPixelInRed(RGB *rgb);
	void paintPixelInGreen(RGB *rgb);
	void paintPixelInBlue(RGB *rgb);
	void paintPixelInBlack(RGB *rgb);
};