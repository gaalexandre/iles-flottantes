#include "PersoGraphic.h"
#include "Perso.h"
#include <fstream>
#include <iostream>

PersoGraphic::PersoGraphic(const std::string& textureFilename, const sf::Transform *transform, PersoAnimation *animation)
: m_transform{*transform}, m_animation{*animation}
{
  std::ifstream file("particles_sheet");
  int x,L,y,l;
  std::string particlesTextureFilename, name;
  file >> particlesTextureFilename;
  
    
  for(int i=0; i<5; ++i){
    file >> name >> x >> y >> L >> l;
    m_rectParticulesSprites[i] = sf::IntRect(x,y,L,l);
  }


  
  m_textureParticle.loadFromFile(particlesTextureFilename);
  m_spriteParticle.setTexture(m_textureParticle);
  m_sprite.setTextureRect(m_rectParticulesSprites[0]);
  m_sprite.setPosition(0,0);

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

  states.texture = &m_textureParticle;
  states.transform=m_transform;
  states.transform.translate(sf::Vector2f(11,-42));
  target.draw(m_spriteParticle, states);
}

void PersoGraphic::update(sf::Time t)
{
  m_spriteParticle.setTextureRect(m_rectParticulesSprites[m_animation.actualPower]);

  std::cout << m_animation.actualPower << "\n";

  m_sprite.setTextureRect(m_animation.sprites[m_animation.state][m_animation.frame]);
  if (m_animation.direction == -1){
    sf::IntRect rect = m_sprite.getTextureRect();
    m_sprite.setTextureRect(sf::IntRect(rect.left+rect.width, rect.top, rect.width*-1, rect.height));
  }
}
