#include "Image.h"
#include <iostream>
#include <string>
using namespace std;


void Image::check(int n) {
	Mat img = Mat(cvSize(n,n), CV_8UC1);
	int x = current_pixel;
	pixel_per_object = 38;
	
	current_pixel += pixel_per_object;
	imshow("Image", img);
	imwrite("image.png", img);
}
void Image::draw(Board& board) {

	pixel_per_object = mypixels / (board.size()*board.size());
	Coordinate temp{ 0,0 };


	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			temp.setx(i);
			temp.sety(j);
			if (board[temp] == 'X') {
				drawX();
			}
			else if (board[temp] == 'O') {
				drawO();
			}
		}
	}
	imshow("Image", image);
	imwrite("image.png", image);
}

void Image::drawX() {
	int x = current_pixel;
	line(image, cvPoint(x, x), cvPoint(x + pixel_per_object, x + pixel_per_object), Scalar(0, 0, 0), 2, 8, 0);
	line(image, cvPoint(x, pixel_per_object), cvPoint(pixel_per_object, x), Scalar(0, 0, 0), 2, 8, 0);
	current_pixel += pixel_per_object;
}
void Image::drawO() {
	int middle = (current_pixel + pixel_per_object) / 2;
	circle(image, Point(middle, middle), middle, Scalar(0, 0, 0), 2, 8, 0);
	current_pixel += pixel_per_object;
}
