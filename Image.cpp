#include <iostream>
#include <string>
#include "Image.h"
using namespace std;


Image::Image(int n) {
	colors = new RGB[n*n];
	pixels = n;
}

Image::~Image() {
	delete [] colors;
}

string Image::createImage(char* board, int bsize) {
	int size = pixels / bsize;
	for (int i = 0; i < bsize; i++)
	{
		for (int j = 0; j < bsize; j++)
		{
			if (board[i*bsize + j] == 'X')
			{
				Xpaint(i, j, size);
			}
			else if (board[i*bsize + j] == 'O')
			{
				Opaint(i, j, size);
			}
		}
	}
	createCanvas(bsize);

	string filename = "board.ppm";
	saveImage(filename);
	return filename;
}

void Image::createCanvas(int size) {
	int cell_pixels = pixels / size;
	for (int j = 0; j < pixels; j++) {
		for (int i = 1; i < size; i++) {
			RGB *rgb = &colors[i*pixels*cell_pixels + j];
			paintPixelInBlack(rgb);
		}

		for (int i = 1; i < size; i++) {
			RGB *rgb = &colors[i*cell_pixels + j*pixels];
			paintPixelInBlack(rgb);
		}
	}

}

void Image::Xpaint(int row, int col, int size) {
	int c_row = row * size;
	int c_col;
	for (int i = 0; i < size; i++) {
		c_col = col * size;
		for (int j = 0; j < size; j++) {
			if (i == j || i + j == size)
			{
				RGB *rgb = &colors[c_row*pixels + c_col];
				paintPixelInBlue(rgb);
			}
			c_col++;
		}
		c_row++;
	}
}


void Image::Opaint(int row, int col, int size) {
	int midx = size / 2;
	int midy = size / 2;
	int rad = size / 2;
	int c_row = row * size, c_col;
	for (int i = 0; i < size; i++) {
		c_col = col * size;
		for (int j = 0; j < size; j++) {

			const double x_diff = j - midx;
			const double y_diff = i - midy;
			double distance = sqrt(x_diff * x_diff + y_diff * y_diff);

			if (distance >= rad - 1 && distance <= rad + 1)
			{
				RGB *rgb = &colors[c_row*pixels + c_col];
				paintPixelInGreen(rgb);
			}
			c_col++;
		}
		c_row++;
	}
}

void Image::saveImage(string filename)
{
	ofstream imageFile(filename, ios::out | ios::binary);
	imageFile << "P6" << endl << pixels << " " << pixels << endl << 255 << endl;
	imageFile.write(reinterpret_cast<char*>(colors), sizeof(RGB) * pixels*pixels);
	imageFile.close();
}

void Image::paintPixelInRed(RGB *rgb) {
	rgb->red = 255;
	rgb->green = 0;
	rgb->blue = 0;
}

void Image::paintPixelInGreen(RGB *rgb) {
	rgb->red = 0;
	rgb->green = 255;
	rgb->blue = 0;
}

void Image::paintPixelInBlue(RGB *rgb) {
	rgb->red = 0;
	rgb->green = 0;
	rgb->blue = 255;
}

void Image::paintPixelInBlack(RGB *rgb) {
	rgb->red = 0;
	rgb->green = 0;
	rgb->blue = 0;
}