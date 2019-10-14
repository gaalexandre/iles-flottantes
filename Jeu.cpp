#include "Jeu.h"

int Jeu::gameLoop()
{
    while (m_window.isOpen())
    {
      eventloop();
      m_physicModule.update();
      m_window.clear(sf::Color::Black);
      m_graphicModule.draw();
      m_window.display();
    }

}

void Jeu::eventLoop()
{
  while (m_window.pollEvent(m_event))
    {
      switch (event.type)
	{
        case sf::Event::Closed:
	  window.close();
	  break;

        case sf::Event::KeyPressed:
	  m_systemModule.manageEvent(Event::some_event)
	  break;

        default:
	  break;
	}
    }
}
