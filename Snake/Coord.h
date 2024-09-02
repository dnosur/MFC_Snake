#pragma once

struct Coord {
	Coord() {
		X = Y = -1;
	}

	Coord(const int X, const int Y) {
		this->X = X;
		this->Y = Y;
	}

	int X, Y;

    bool operator==(const Coord& other) const {
        return (X == other.X) && (Y == other.Y);
    }

    bool operator!=(const Coord& other) const {
        return !(*this == other);
    }

    Coord& operator=(const Coord& other) {
        if (this != &other) {
            X = other.X;
            Y = other.Y;
        }
        return *this;
    }
};