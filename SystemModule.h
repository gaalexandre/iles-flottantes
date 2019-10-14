#ifndef SYSTEM_H
#define SYSTEM_H

#include <forward_list>

enum class Event{some_event};

class System
{
 public:
  bool addComponent(SystemComponent &component);
  void manageEvent(Event event);
 private:
  forward_list<SystemComponent*> m_components; 
};

#endif
