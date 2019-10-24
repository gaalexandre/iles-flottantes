#include "PhysicModule.h"

bool PhysicModule::addComponent(PhysicComponent &component)
{
    m_components.push_front(&component);
    
  return true;
}


void PhysicModule::update()
{
    for(auto it = m_components.begin(); it != m_components.end(); it++)
    {
        (*it)->update();
        for(auto it2 = m_components.begin(); it2 != m_components.end(); it2++)
        {
            if(it2 != it)
            {
            (*it)->collide( **it2 );
            }
        }
    }
  
}
