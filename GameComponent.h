#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

class GameComponent
{
 public:
  
 protected:
  GraphicComponent* m_graphicComponent(nullptr);
  PhysicComponent* m_physicComponent(nullptr);
  Component* m_systemComponent(nullptr);
};


#endif
