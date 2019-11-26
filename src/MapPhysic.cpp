#include "MapPhysic.h"
#include <iostream>

MapPhysic::MapPhysic(int height, int width, int tileSize, int const* const* const  tilesKind)
{
    m_tilesKind = tilesKind;
    m_width = width;
    m_height = height;
    m_tileSize = tileSize;
    
}



/*
bool MapPhysic::isSolid(float x, float y){
    return (m_tilesKind[x][y]);
//    (m_tilesKind[(int) ((x*m_width)+y)]) == 1);
}
 
*/

/*
~MapPhysic::MapPhysic()
{
    for(int )
    
}
 */

void MapPhysic::update(sf::Time t)
{
    // Le MapPhysic n'est pas un component dynamique
    return;
}

void MapPhysic::collide( PhysicComponent &other)
{
    // Le Map physic n'est pas un component qui va devoir se modifier face à une
    // collision
    
    return;
}

typeCollision MapPhysic::intersect(sf::Vector2f point)
{
    
    for(int i=0;i<m_width;i++)
    {
        for(int j = 0;j<m_height;j++)
        {
            if(m_tilesKind[i][j] == 0 && i*m_tileSize==point.x && j*m_tileSize==point.y)
            {
                return  Collision;
            }
        }
    }
     
    return AucuneCollision;
    
}

typeCollision MapPhysic::intersect(sf::FloatRect rect)
{
    typeCollision retour = AucuneCollision;
    sf::FloatRect Tile(0,0,m_tileSize,m_tileSize);
    for(int i=0;i<m_width;i++)
    {
        for(int j = 0;j<m_height;j++)
        {
            if(m_tilesKind[i][j] != 1)
            {
                
                Tile.left=i*m_tileSize;
                Tile.top=j*m_tileSize;
               
                if(rect.intersects(Tile))
                {
                    switch(m_tilesKind[i][j])
                    {
                        case 0 :
                            if(retour<=Collision)
                            {
                                retour = Collision;
                            }
                            break;
                        case 2 :
                            
                            if(retour<=CollisionMortel)
                            {
                                retour = CollisionMortel;
                            }
                            break;
                        case 3 :
                            if(retour<=CollisionFinNiveau)
                            {
                                retour = CollisionFinNiveau;
                            }
                            break;
                        default:
                            break;
                    }
                    
                
                }
            }
        }
    }
    return retour;
     

}

MapPhysic::~MapPhysic()
{
    
}
