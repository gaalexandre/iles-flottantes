#include "Jeu.h"

int Jeu::gameLoop()
{
    while (m_window.isOpen())
    {
      eventLoop();
      m_physicModule.update();
      m_window.clear(sf::Color::Black);
      m_graphicModule.draw();
      m_window.display();
    }
    return 0;
}

void Jeu::eventLoop()
{
  while (m_window.pollEvent(m_event))
    {
      switch (m_event.type)
	{
        case sf::Event::Closed:
	  m_window.close();
	  break;

        case sf::Event::KeyPressed:
	  m_systemModule.manageEvent(Event::some_event);
	  break;

        default:
	  break;
	}
    }
}
