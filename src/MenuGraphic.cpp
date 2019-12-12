#include "MenuGraphic.h"
#include <fstream>
#include <iostream>

MenuGraphic::MenuGraphic(bool &inMenu,sf::View &view,unsigned int &selected):m_inMenu(inMenu), m_view(view), m_selected(selected)
{
  m_font.loadFromFile("sansation.ttf");
  std::string s[3]={"Play","Settings","Quit"};
  for(int i{0};i<3;i++)
  {
      m_text[i].setString(s[i]);
      m_text[i].setFont(m_font);
      m_text[i].setCharacterSize(24);
      m_text[i].setFillColor(sf::Color::Black);
      m_text[i].setOutlineColor(sf::Color::White);
      m_text[i].setOutlineThickness(1);
  }
  m_filter.setSize(sf::Vector2f(10000.f, 10000.f));
  m_filter.setFillColor(sf::Color(0,0,0,70));
  
}
void MenuGraphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  if(m_inMenu)
  {
      target.draw(m_filter,states);
      for(int i{0};i<3;i++)
	  target.draw(m_text[i],states);

  }
  // states.texture = &m_tilesetBackground;

  // target.draw(m_verticesBackground, states);

  //  states.texture = &m_tileset;

  //  target.draw(m_vertices, states);
}

void MenuGraphic::update(sf::Time t)
{
    for(int i{0};i<3;i++)
    {
	m_text[i].setPosition(m_view.getCenter());
	m_text[i].move(0,60*(i-1));
	if(m_selected==i)
	    m_text[i].setOutlineColor(sf::Color::Red);
	else
	    m_text[i].setOutlineColor(sf::Color::White);
    }
}
