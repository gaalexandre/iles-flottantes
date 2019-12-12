#ifndef MAP_GRAPHIC_H
#define MAP_GRAPHIC_H

#include <SFML/Graphics.hpp>
#include "GraphicComponent.h"

enum changementBloc // (?)
{ VIDE};

struct tile {
  int id;
  std::string name;
  int x;
  int y;
  int width;
  int height;
  int up;
  int right;
  int down;
  int left;
};



class MapGraphic : public GraphicComponent
{
public:
  MapGraphic(const std::string& textureFilename, const std::string& backgroundFilename, int height, int width, int tileSize, const int* tiles, int worldType);
  
  
  void change(sf::Vector2f point, int changement);

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  virtual void update(sf::Time t);
    
  sf::VertexArray m_vertices;
  sf::VertexArray m_verticesBackground;
  sf::Texture m_tileset;
  sf::Texture m_tilesetBackground;
  
  int m_tileSize;
  int m_height;
  int m_width;
  
  tile*** m_tileList{nullptr};
  int m_nbTypesOfTiles, m_nbTexturesTypes, m_nbTextures;
  
};

#endif
