#include "PersoSystem.h"
#include <SFML/Window.hpp>
#include <iostream>


PersoSystem::PersoSystem (PersoEtatSystem *persoEtat)
: m_persoEtat(*persoEtat)
{
    
    //on charge les sons
    
    std::string listeSon[8] = {"saut", "victoire", "jump1",
        "deathPain", "youLose", "victory", "victory2", "collision"
    };
    // de taille 2
    
    for(int i = 0; i < 8;i++)
    {
    if(!m_soundBuffers[listeSon[i]].loadFromFile("./audio/"+listeSon[i]+".wav"))
    {
        std::cout << "Erreur de chargement de son" << std::endl;
        // lancer une exception ?
    }
    m_sounds[listeSon[i]].setBuffer(m_soundBuffers[listeSon[i]]);
    //m_sounds[listeSon[i]].setVolume(50.f);
    }
 
  
    
}


 void PersoSystem::manageEvent (sf::Event event){
    
     
     // gerer les états detecté par le physique :
     if(m_persoEtat.contactMortel)
     {
         m_sounds["deathPain"].play();
         m_sounds["youLose"].play();
         m_persoEtat.contactMortel = false;
         std::cout << " Mort ! " << std::endl;
         m_persoEtat.resetCoord = true;
         m_persoEtat.cle = false;
     }
     if(m_persoEtat.contactFinNiveau)
     {
         m_sounds["victory"].play();
         m_persoEtat.contactFinNiveau = false;
         std::cout << " Fin du niveau ! " << std::endl;
         m_persoEtat.resetCoord = true; // a replacer par un changement de niveau 
         m_persoEtat.cle = false;
    
     }
     
     
     //gerer les sons declenches :
     if(m_persoEtat.sonCollision ==1)
     {
         m_persoEtat.sonCollision =0;
         m_sounds["collision"].play();
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
         if(m_persoEtat.surLeSol)
         {
         m_sounds["jump1"].play();
         m_persoEtat.saut = true;
         }
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

