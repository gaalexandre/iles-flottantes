#ifndef MAP_GRAPHIC_H
#define MAP_GRAPHIC_H

#include <SFML/Graphics.hpp>
#include "GraphicComponent.h"

class MapGraphic : public GraphicComponent
{
public:
  MapGraphic(const std::string& textureFilename, int height, int width, int tileSize, const int* tiles);

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  sf::VertexArray m_vertices;
  sf::Texture m_tileset;
  
};

#endif
