#ifndef HANGAR_PILOT_H
#define HANGAR_PILOT_H

#include <string>

/// A mech pilot. This is the STARTER version: every field is public, so any code
/// anywhere can set a pilot's skill to -40 or give them an empty name.
/// Your job is to fix that. See README.md for the checkpoints.
class Pilot {
 public:
  
    Pilot(std::string name, int skill);

void rest();
/// A pilot with fatigue above 80 is too tired to fly: return false and change nothing.
/// Otherwise add 20 fatigue, add 1 mission, and return true.
bool fly_mission();
/// Prints one line:  name | skill N | fatigue N | missions N
void print() const;

bool set_name(const std::string& name);
void change_skill(int change);

std::string name() const;
int skill() const;
int fatigue() const;
int missions() const;

private:

 std::string name_;
 int skill_;      ///< 1 (rookie) to 100 (ace)
 int fatigue_;    ///< 0 (rested) to 100 (exhausted)
 int missions_;


};


#endif
