#ifndef PERSO_GRAPHIC_H
#define PERSO_GRAPHIC_H

#include <SFML/Graphics.hpp>
#include "GraphicComponent.h"
#include "Perso.h"

class PersoGraphic : public GraphicComponent
{
public:
  PersoGraphic(const std::string& textureFilename, const sf::Transform *transform, PersoAnimation *animation);

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  virtual void update(sf::Time t);
  sf::IntRect* m_rectParticulesSprites{new sf::IntRect[5]};
  sf::Sprite m_sprite;
  sf::Texture m_texture;
  sf::Sprite m_spriteParticle;
  sf::Texture m_textureParticle;
  const sf::Transform &m_transform;
  PersoAnimation &m_animation;
};

#endif
