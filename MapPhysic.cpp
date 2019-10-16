#include "MapPhysic.h"

MapPhysic::MapPhysic(int height, int width, int tileSize, const int* tilesKind)
{
  m_tilesKind = tilesKind;
  m_width = width;
}

bool MapPhysic::isSolid(float x, float y){
  return ((m_tilesKind[(int) ((x*m_width)+y)]) == 1);
}
