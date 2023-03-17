#ifndef _LEVELMAP_H
#define _LEVELMAP_H
#include "Constants.h"

#pragma once

class LevelMap
{

public:
	LevelMap(int map[MAP_HEIGHT][MAP_WIDTH]);
	~LevelMap();

	int GetTileAt(unsigned int h, unsigned int w);

private:
	int** m_map;
};

#endif