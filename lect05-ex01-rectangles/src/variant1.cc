/*
 * variant1.cc
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

class rectangle {
public:

	virtual ~rectangle() {
	}

	int get_width() {
		return width;
	}

	int get_height() {
		return height;
	}

	virtual void set_width(int width_) {
		width = width_;
	}
	virtual void set_height(int height_) {
		height = height_;
	}

protected:
	int width = 0;
	int height = 0;

};

class square: public rectangle {
public:
	void set_width(int width_) {
		width = width_;
		height = width_;
	}

	void set_height(int height_) {
		width = height_;
		height = height_;
	}

};
