#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------

struct Tileset {

	p2SString	name;
	p2SString	img_source;

	uint		tileWidth;
	uint		tileheight;
	uint		spacing;
	uint		margin;

};


// TODO 1: Create a struct needed to hold the information to Map node
enum Map_Orientation
{
	orthogonal=0,
	isometric,
	staggered,
	hexagonal
};

enum Map_renderorder 
{
	right_down=0,
	right_up,
	left_down,
	left_up
};

struct Map{

	float				version;

	Map_Orientation		orientation;
	Map_renderorder		renderorder;

	uint				width;
	uint				height;
	uint				tilewidth;
	uint				tileheight;
	uint				nextobject;

	Tileset				map_tile[];

};


// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

	//Load and fill map data
	void FillMap(const pugi::xml_document& document);

private:


public:

	// TODO 1: Add your struct for map info as public for now
	Map first_map;
	Tileset first_tile;

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__