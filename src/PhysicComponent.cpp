#include "PhysicComponent.h"

float PhysicComponent::getAbs (){
  return m_abs;
}

float PhysicComponent::getOrd (){
  return m_ord;
}

void PhysicComponent::setAcceleration (float acc){
  m_acc = acc;
  return;
}

