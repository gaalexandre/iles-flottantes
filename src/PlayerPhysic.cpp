#include "PlayerPhysic.h"
#include "Perso.h"
#include <iostream>

PlayerPhysic::PlayerPhysic(sf::Transform *t,float x, float y, float width, float height, float scale, PersoEtatSystem* persoEtat, PersoAnimation *animation, double xBegin, double yBegin)
  :  m_hitBox(x,y, scale*width-10, scale*height),m_transform (*t), m_persoEtat(*persoEtat), m_scale(scale), m_animation{*animation}, m_xBegin(xBegin), m_yBegin(yBegin)
{
  m_persoEtat.height = height;
  m_persoEtat.width = width;
}

void PlayerPhysic::update(const sf::Time t) // bouge selon les accelaration.
{
    
    
    //gestion de la gravité
    if(not m_persoEtat.surLeSol)
    {
        addVitesse(0,gravite*t.asSeconds());
        
        
        if(m_vitesseY>vitesseLimiteGravite) // vitesse limite
        {

            m_vitesseY=vitesseLimiteGravite;

        }
    }
    
    //gestion des déplacements du system
    m_vitesseX+=m_persoEtat.deplacementX*sizeDeplacement*(m_persoEtat.actualPower==air?airPowerFactor:1)*t.asSeconds();
    m_vitesseX/=1+(3*t.asSeconds());
    if(m_persoEtat.deplacementX)
    {
        m_animation.frame = m_animation.state == walk ? m_animation.frame : 0;
        m_animation.state = walk;
        m_animation.direction = m_persoEtat.deplacementX;
    }
    else
    {
        m_animation.frame = m_animation.state == stand ? m_animation.frame : 0;
        m_animation.state = stand;
    }
    
    
    //gestion du saut
    if(m_persoEtat.saut)
    {
        saut();
    }

    if(!m_persoEtat.surLeSol)
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
    
    m_transform.translate(  m_vitesseX*( t.asSeconds()), m_vitesseY*( t.asSeconds())+10*t.asSeconds());
    m_transfX =m_vitesseX*( t.asSeconds());
    m_transfY =m_vitesseY*( t.asSeconds())+10*t.asSeconds();
    m_hitBox.left += m_scale*m_transfX;
    m_hitBox.top += m_scale*m_transfY;
  
  
  m_persoEtat.x = m_hitBox.left;
  m_persoEtat.y = m_hitBox.top;
  
    return;
    
}

void PlayerPhysic::collide(PhysicComponent &other)
{
    //algorithme (?)
    m_persoEtat.surLeSol = false;
    
    
    
    
    //gerer les collisions particulières :
    int typeCollision = other.intersect(m_hitBox);
    //std::cout << typeCollision << std::endl;

    if((typeCollision&CollisionFireAltar) != 0)
    {
        m_persoEtat.actualPower = fire;
    }
    if((typeCollision&CollisionWaterAltar) != 0)
    {
        m_persoEtat.actualPower = water;
    }
    if((typeCollision&CollisionAirAltar) != 0)
    {
        m_persoEtat.actualPower = air;
    }
    if((typeCollision&CollisionEarthAltar) != 0)
    {
        m_persoEtat.actualPower = earth;
    }
    if((typeCollision&CollisionNullAltar) != 0)
    {
        m_persoEtat.actualPower = null;
    }

    m_animation.actualPower = m_persoEtat.actualPower;

    if((typeCollision&CollisionFeu) != 0)
    {
        if(m_persoEtat.actualPower!=water)
            m_persoEtat.contactMortel = true;
    }
  
    if((typeCollision&CollisionMortel) != 0)
    {
        m_persoEtat.contactMortel = true;
    }
    if((typeCollision&CollisionFinNiveau) !=0)
    {
        if(m_persoEtat.cle)
        {
            m_persoEtat.contactFinNiveau = true;
        }
    }
    
    
    
    
    if((typeCollision&CollisionCle) !=0 && m_persoEtat.sonCollision != -1)
    {
        m_persoEtat.cle = true;
        m_persoEtat.sonCollision = 2;
    }
    
    if((typeCollision&Collision) !=0)
    {
        if( m_persoEtat.surLeSol)
        {
            m_persoEtat.sonCollision=1;
        }
        
        m_transform.translate( -1*m_transfX, 0);
        m_hitBox.left -= m_scale*m_transfX;
        typeCollision = other.intersect(m_hitBox);
        if((typeCollision&Collision)!=0)
        {
            if(m_transfY>0)
            {
                m_persoEtat.surLeSol=true;
            }
            
            m_transform.translate(m_transfX, 0);
            m_hitBox.left += m_scale*m_transfX;
            
            m_transform.translate(0, -1*m_transfY);
            m_hitBox.top -= m_scale*m_transfY;
            
            typeCollision = other.intersect(m_hitBox);
            if((typeCollision&Collision)!=0)
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
    }
    
    
    
    
    
    /*
    switch(other.intersect(m_hitBox))
    {
        case CollisionMortel :
            m_persoEtat.contactMortel = true;
            break;
        case CollisionFinNiveau :
            if(m_persoEtat.cle)
            {
                m_persoEtat.contactFinNiveau = true;
            }
            break;
        case CollisionCle :
            m_persoEtat.cle = true;
            break;
            
        case Collision :
                m_transform.translate( -1*m_transfX, 0);
                m_hitBox.left -= m_scale*m_transfX;
                if(other.intersect(m_hitBox) == Collision)
                {
                    if(m_transfY>0)
                    {
                        m_persoEtat.surLeSol=true;
                    }
                    
                    m_transform.translate(m_transfX, 0);
                    m_hitBox.left += m_scale*m_transfX;
                    
                    m_transform.translate(0, -1*m_transfY);
                    m_hitBox.top -= m_scale*m_transfY;
                    
                    if(other.intersect(m_hitBox) == Collision)
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
     */
   

    return;
}

int PlayerPhysic::intersect(sf::Vector2f point)
{    
    return (m_hitBox.contains(point)) ? Collision : AucuneCollision;
}

int PlayerPhysic::intersect(sf::FloatRect rect)
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
    if(m_persoEtat.surLeSol)
    {
      setVitesseY(sizeJump);
      
      m_persoEtat.surLeSol=false;
    }
    m_persoEtat.saut = false;
}

void PlayerPhysic::resetCoord()
{
    m_transform.combine(m_transform.getInverse());
    m_transform.scale(m_scale, m_scale);
    m_transform.translate(m_xBegin,m_yBegin);
    m_hitBox.left = m_scale*m_xBegin;
    m_hitBox.top = m_scale*m_yBegin;
    setVitesseX(0);
    setVitesseY(0);
    
    m_persoEtat.resetCoord = false;
    m_persoEtat.sonCollision = 0;
}

