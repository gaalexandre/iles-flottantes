#include "PersoGraphic.h"

PersoGraphic::PersoGraphic(const std::string& textureFilename, const sf::Transform *transform, sf::IntRect const& textureRect): m_transform{*transform}
{
  m_texture.loadFromFile(textureFilename);
  m_sprite.setTexture(m_texture);
  m_sprite.setTextureRect(textureRect);
    m_sprite.setPosition(0,0);
    
}

void PersoGraphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{ 
  states.texture = &m_texture;
  states.transform=m_transform;
  target.draw(m_sprite, states);
}
