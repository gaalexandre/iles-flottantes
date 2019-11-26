#ifndef MAP_GRAPHIC_H
#define MAP_GRAPHIC_H

#include <SFML/Graphics.hpp>
#include "GraphicComponent.h"

class MapGraphic : public GraphicComponent
{
public:
  MapGraphic(const std::string& textureFilename, const std::string& backgroundFilename, int height, int width, int tileSize, const int* tiles, int worldType);

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  sf::VertexArray m_vertices;
  sf::VertexArray m_verticesBackground;
  sf::Texture m_tileset;
  sf::Texture m_tilesetBackground;
  
};

#endif
