#pragma once
#include <Windows.h>
#include <atltypes.h>

#include "Coord.h"

struct Cell {
	Cell() {
	}

	Cell(Coord coord, CRect rect)
		: coord(coord), rect(rect) {}

	Coord coord;
	CRect rect;

    bool operator==(const Cell& other) const {
        return (coord == other.coord) && (rect == other.rect);
    }

    bool operator!=(const Cell& other) const {
        return !(*this == other);
    }

    Cell& operator=(const Cell& other) {
        if (this != &other) {
            coord = other.coord;
            rect = other.rect;
        }
        return *this;
    }
};