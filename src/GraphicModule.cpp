#include "GraphicModule.h"

void GraphicModule::addComponent(GraphicComponent &component)
{
  m_components.push_front(&component);
}

void GraphicModule::draw(sf::RenderWindow &window)
{
  for(auto i(m_components.begin());i!=m_components.end();++i)
  {
    window.draw(**i);
  }
}
