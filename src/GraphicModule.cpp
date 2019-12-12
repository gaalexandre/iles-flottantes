#include "GraphicModule.h"
#include "iostream"
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

void GraphicModule::update(const sf::Time t)
{
    for(auto it = m_components.begin(); it != m_components.end(); it++)
    {
        (*it)->update(t);
    }
}
void GraphicModule::unload()
{
  m_components.clear();
}
