#include "MenuSystem.h"
#include <SFML/Window.hpp>
#include <iostream>


MenuSystem::MenuSystem (bool &inMenu,unsigned int &selected)
  : m_inMenu(inMenu),m_selected(selected)
{
    
}


void MenuSystem::manageEvent (sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
	if(event.key.code==sf::Keyboard::Escape)
	{
	    m_inMenu=!m_inMenu;
	}
	else if(m_inMenu)
	    switch(event.key.code)
	    {
	    case sf::Keyboard::Up:
		if(m_selected==0)
		    m_selected=3;
		--m_selected;
		break;
	    case sf::Keyboard::Down:
		++m_selected;
		m_selected%=3;
		break;
	    case sf::Keyboard::Return:
		switch(m_selected)
		{
		case 0:
		    m_inMenu=!m_inMenu;
		    break;
		case 1:
		    
		    break;
		case 2:
		    exit(0); //flemme pas le temps
		    break;
		default:
		    break;
		}
		break;
	    default:
		break;
	    }
	break;
    default:
	break;
    }
}

