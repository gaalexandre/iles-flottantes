#ifndef SYSTEM_Module_H
#define SYSTEM_Module_H

#include <forward_list>
#include <SFML/Window.hpp>
#include "SystemComponent.h"

enum class Event{some_event};

class SystemModule

{
 public:
  bool addComponent(SystemComponent &component);
  void manageEvent(sf::Event event);
  void unload();
 private:
  std::forward_list<SystemComponent*> m_components; 
};

#endif
