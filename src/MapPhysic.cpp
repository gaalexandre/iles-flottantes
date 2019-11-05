#include "MapPhysic.h"

MapPhysic::MapPhysic(int height, int width, int tileSize, const int* tilesKind)
{
  m_tilesKind = tilesKind;
  m_width = width;
}

