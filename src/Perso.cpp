#include "Perso.h"

void Perso::saut (float acc) {

  if (Map.isSolid(m_physicComponent.getAbs(),m_physicComponent.getOrd()-1))
    {
      m_physicComponent.setAcceleration(acc);
      return;
    }
  
  return;
  
}
