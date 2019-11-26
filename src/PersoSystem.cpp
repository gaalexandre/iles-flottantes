#include "PersoSystem.h"
#include <SFML/Window.hpp>
#include <iostream>


PersoSystem::PersoSystem (PersoEtatSystem *persoEtat)
: m_persoEtat(*persoEtat)
{
    
    
}


 void PersoSystem::manageEvent (sf::Event event){
    
     
     // gerer les états detecté par le physique :
     if(m_persoEtat.contactMortel)
     {
         m_persoEtat.contactMortel = false;
         std::cout << " Mort ! " << std::endl;
         m_persoEtat.resetCoord = true;
     }
     if(m_persoEtat.contactFinNiveau)
     {
         m_persoEtat.contactFinNiveau = false;
         std::cout << " Fin du niveau ! " << std::endl;
         m_persoEtat.resetCoord = true; // a replacer par un changement de niveau 
     }
     
     
     
     
     
     
     
     // gerer l'entrée clavier :
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
     {
         m_persoEtat.deplacementX = -1;
     }
     else if
         (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
     {
         m_persoEtat.deplacementX = 1;
     }
     else
     {
         m_persoEtat.deplacementX = 0;
     }
     
     /*
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
     */
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
     {
         
         m_persoEtat.saut = true;
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

