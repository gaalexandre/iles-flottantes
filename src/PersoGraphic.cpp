#include "PersoGraphic.h"
#include "Perso.h"

PersoGraphic::PersoGraphic(const std::string& textureFilename, const sf::Transform *transform, PersoAnimation *animation)
: m_transform{*transform}, m_animation{*animation}
{
  m_texture.loadFromFile(textureFilename);
  m_sprite.setTexture(m_texture);
  m_sprite.setTextureRect(m_animation.sprites[m_animation.state][m_animation.frame]);
  m_sprite.setPosition(0,0);
    
}

void PersoGraphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.texture = &m_texture;
  states.transform=m_transform;
  target.draw(m_sprite, states);
}

void PersoGraphic::update(sf::Time t)
{
  m_sprite.setTextureRect(m_animation.sprites[m_animation.state][m_animation.frame]);
  if (m_animation.direction == -1){
    sf::IntRect rect = m_sprite.getTextureRect();
    m_sprite.setTextureRect(sf::IntRect(rect.left+rect.width, rect.top, rect.width*-1, rect.height));
  }
}