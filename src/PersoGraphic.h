#ifndef PERSO_GRAPHIC_H
#define PERSO_GRAPHIC_H

#include <SFML/Graphics.hpp>
#include "GraphicComponent.h"

class PersoGraphic : public GraphicComponent
{
public:
  PersoGraphic(const std::string& textureFilename, const sf::Transform *transform, sf::IntRect const& textureRect);

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  sf::Sprite m_sprite;
  sf::Texture m_texture;
  const sf::Transform &m_transform;
};

#endif
