#include "PersoSystem.h"
#include <SFML/Window.hpp>
#include <iostream>


PersoSystem::PersoSystem (PlayerPhysic *physicComponent)
: m_physicComponent(*physicComponent)
{
    
    
}


 void PersoSystem::manageEvent (sf::Event event){
    
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
     {
         
         m_physicComponent.setVitesseX(-100);
     }
     else if
         (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
     {
         
         m_physicComponent.setVitesseX(100);
     }
     else
     {
         m_physicComponent.setVitesseX(0);
     }
     
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
     {
         
         m_physicComponent.setVitesseY(-100);
     }
     else if
         (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
     {
         
         m_physicComponent.setVitesseY(100);
     }
     else
     {
         m_physicComponent.setVitesseY(0);
     }
     
     /*
    // Evènement liés au clavier
    switch(event.key.code)
    {
        case sf::Keyboard::Key::Up :
            *m_isJumping = true;
            break;
        case sf::Keyboard::Key::Left :
            m_physicComponent.setVitesseX(10);
            break;
        default :
            
            break;
    }
      */
     
}

