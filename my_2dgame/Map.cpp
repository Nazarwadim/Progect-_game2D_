#include "Map.h"
#define W 0
#define G 1
#define D 2
int lvl1[ROW][COLUMN] = {
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
	{D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D},
	{D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D},
	{D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D},
	{D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D},
	{D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D},
};
Map::Map()
{
	dirt = Texture_manager::load_texture("assets/dirt.png");
	grass = Texture_manager::load_texture("assets/grass.png");
	water = Texture_manager::load_texture("assets/water.png");
	load_map(lvl1);

	src.x = src.y = 0;
	dest.x = dest.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
}

Map::~Map()
{}

void Map::load_map(int arr[ROW][COLUMN])
{	
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COLUMN; col++)
		{
			map[row][col] = arr[row][col];
		}
	}
}

void Map::draw_map()
{
	int type = 0;
	for (int row = 0; row < ROW; row++) // ROW 2W COL 25
	{
		for (int col = 0; col < COLUMN; col++)
		{
			type = map[row][col];
			dest.x = col * 32;
			dest.y = row * 32;
			switch (type)
			{
			case W:
				Texture_manager::draw(water, src, dest);
				break;
			case G:
				Texture_manager::draw(grass, src, dest);
				break;
			case D:
				Texture_manager::draw(dirt, src, dest);
				break;
			default:
				break;
			}
		}
	}
}