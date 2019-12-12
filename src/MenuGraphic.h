#ifndef MENU_GRAPHIC_H
#define MENU_GRAPHIC_H

#include <SFML/Graphics.hpp>
#include "GraphicComponent.h"

class MenuGraphic : public GraphicComponent
{
 public:
  MenuGraphic(bool &inMenu,sf::View &view,unsigned int &selected);
  virtual void update(sf::Time t);
 private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates  states) const;
  sf::Text m_text[3];
  sf::Font m_font;
  bool &m_inMenu;
  sf::View &m_view;
  sf::RectangleShape m_filter;
  unsigned int &m_selected;
};
#endif
