/*
 * variant2.cc
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

class square {
public:
	int get_width() {
		return width;
	}

	void set_width(int width_) {
		width = width_;
	}

protected:
	int width = 0;

};

class rectangle: public square {
public:
	int get_height() {
		return height;
	}

	void set_height(int height_) {
		height = height_;
	}

protected:
	int height = 0;

};
