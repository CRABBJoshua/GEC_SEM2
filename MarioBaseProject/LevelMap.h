#ifndef _LEVELMAP_H
#define _LEVELMAP_H

#include "Constants.h"

#pragma once

//The LevelMap header file is being used to hold all the info and values of the LevelMap class. 
class LevelMap
{

public:
	LevelMap(int map[MAP_HEIGHT][MAP_WIDTH]);
	~LevelMap();

	int GetTileAt(unsigned int h, unsigned int w);
	void ChangeTileAt(unsigned int row, unsigned int column, unsigned int new_value);

private:
	int** m_map;
};

#endif //_LEVELMAP_H