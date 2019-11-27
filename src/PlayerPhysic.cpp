#include "PlayerPhysic.h"
#include "Perso.h"
#include <iostream>

PlayerPhysic::PlayerPhysic(sf::Transform *t,float x, float y, float width, float height, float scale, PersoEtatSystem* persoEtat, PersoAnimation *animation)
:  m_hitBox(x,y, scale*width, scale*height),m_transform (*t), m_persoEtat(*persoEtat), m_scale(scale), m_animation{*animation}
{
    
}



void PlayerPhysic::update(const sf::Time t) // bouge selon les accelaration.
{
    
    addVitesse(0,180*t.asSeconds());
    
    //gestion de la gravité
    if(m_vitesseY>450) // vitesse limite
    {
        m_vitesseY=450;
    }
    
    
    //gestion des déplacements du system
    setVitesseX(m_persoEtat.deplacementX*100);

    if(m_persoEtat.deplacementX)
    {
        m_animation.frame = m_animation.state == walk ? m_animation.frame : 0;
        m_animation.state = walk;
        m_animation.direction = m_persoEtat.deplacementX;
    }
    else
    {
        m_animation.frame = m_animation.state == wait ? m_animation.frame : 0;
        m_animation.state = wait;
    }
    
    //gestion du saut
    if(m_persoEtat.saut)
    {
        saut();
    }

    if(!m_surLeSol)
    {
        m_animation.frame = m_animation.state == jump ? m_animation.frame : 0;
        m_animation.state = jump;
    }

    int step = (m_animation.clock + t.asMilliseconds()) / m_animation.timeBetweenFrames[m_animation.state];
    m_animation.clock = (m_animation.clock + t.asMilliseconds()) % m_animation.timeBetweenFrames[m_animation.state];
    m_animation.frame = (m_animation.frame+step)%m_animation.nbFrames[m_animation.state];
   
    // reinitialisation des coordonnées si demandé.
    if(m_persoEtat.resetCoord)
        resetCoord();
    
    
    
    
    
    
    
    
    //deplacement :
    
    m_hitBox.left += m_scale*m_vitesseX*( t.asSeconds());
    m_hitBox.top += m_scale*(m_vitesseY*( t.asSeconds() )+10*t.asSeconds());
    m_transform.translate(  m_vitesseX*( t.asSeconds()), m_vitesseY*( t.asSeconds())+10*t.asSeconds());
    m_transfX =m_vitesseX*( t.asSeconds());
    m_transfY =m_vitesseY*( t.asSeconds())+10*t.asSeconds();
    return;
    
}

void PlayerPhysic::collide(PhysicComponent &other)
{
    //algorithme (?)
    m_surLeSol = false;
    
    
    
    
    //gerer les collisions particulières :
    switch(other.intersect(m_hitBox))
    {
        case CollisionMortel:
            m_persoEtat.contactMortel = true;
            break;
        case CollisionFinNiveau :
            m_persoEtat.contactFinNiveau = true;
            break;
            
        case Collision :
                m_transform.translate( -1*m_transfX, 0);
                m_hitBox.left -= m_scale*m_transfX;
                if(other.intersect(m_hitBox))
                {
                    if(m_transfY>0)
                    {
                        m_surLeSol=true;
                    }
                    
                    m_transform.translate(m_transfX, 0);
                    m_hitBox.left += m_scale*m_transfX;
                    
                    m_transform.translate(0, -1*m_transfY);
                    m_hitBox.top -= m_scale*m_transfY;
                    
                    if(other.intersect(m_hitBox))
                    {
                        m_transform.translate( -1*m_transfX, 0);
                        m_hitBox.left -= m_scale*m_transfX;
                        setVitesseY(0);
                        setVitesseX(0);
                        return;
                    }
                    else
                    {
                        setVitesseY(0);
                        return;
                    }
                    
                }
                else
                {
                    setVitesseX(0);
                    return;
                }
            
            break;
        case AucuneCollision:
            
            break;
    }
    
    
    return;
}


typeCollision PlayerPhysic::intersect(sf::Vector2f point)
{
    
    return (m_hitBox.contains(point)) ? Collision : AucuneCollision;
            

}

typeCollision PlayerPhysic::intersect(sf::FloatRect rect)
{
    
    return (rect.intersects(m_hitBox)) ? Collision : AucuneCollision;
       
}



void PlayerPhysic::setVitesseX(float accelerationX)
{
    m_vitesseX = accelerationX;
}
void PlayerPhysic::setVitesseY(float accelerationY)
{
    m_vitesseY = accelerationY;
}
void PlayerPhysic::addVitesse(float accelerationX, float accelerationY)
{
    m_vitesseY+= accelerationY;
    m_vitesseX+= accelerationX;
}





void PlayerPhysic::saut()
{
    if(m_surLeSol)
    {
        setVitesseY(-180);
        m_surLeSol=false;
    }
    m_persoEtat.saut = false;
}

void PlayerPhysic::resetCoord()
{
    m_transform.combine(m_transform.getInverse());
    m_transform.scale(m_scale, m_scale);
    m_hitBox.left = 0;
    m_hitBox.top = 0;
    setVitesseX(0);
    setVitesseY(0);
    
    m_persoEtat.resetCoord = false;
}
