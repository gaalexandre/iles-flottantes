#include "MapGraphic.h"

MapGraphic::MapGraphic(const std::string& textureFilename, int height, int width, int tileSize, const int* tiles)
{
  m_tileset.loadFromFile(textureFilename);
  m_vertices.setPrimitiveType(sf::Quads);
  m_vertices.resize(width * height * 4);

  for (unsigned int i = 0; i < width; ++i)
	for (unsigned int j = 0; j < height; ++j)
	{
		int tileNumber = tiles[i + j * width];

		int tu = tileNumber % (m_tileset.getSize().x / tileSize);
		int tv = tileNumber / (m_tileset.getSize().x / tileSize);

		sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

		quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
		quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
		quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
		quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

		quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
		quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
		quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
		quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
	}
}

void MapGraphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  
  states.texture = &m_tileset;
  
  target.draw(m_vertices, states);
}
