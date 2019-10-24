#include "MapPhysic.h"

MapPhysic::MapPhysic(int height, int width, int tileSize, const int* const* tilesKind)
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

void MapPhysic::update()
{
    return;
}

void MapPhysic::collide( PhysicComponent &other)
{
    return;
}

bool MapPhysic::intersect(sf::Vector2f point)
{
    
    for(int i=0;i<m_width;i++)
    {
        for(int j = 0;j<m_height;j++)
        {
            if(m_tilesKind[i][j] == 1 && i*m_tileSize==point.x && j*m_tileSize==point.y)
            {
                return  true;
            }
        }
    }
     
    return false;
    
}

bool MapPhysic::intersect(sf::FloatRect rect)
{
    
    for(int i=0;i<m_width;i++)
    {
        for(int j = 0;j<m_height;j++)
        {
            if(m_tilesKind[i][j] == 1 && rect.contains(i*m_tileSize, j*m_tileSize))
            {
                return  true;
            }
        }
    }
    return false;
     
}
