#include "pilot.h"
#include <utility>
#include <iostream>
#include <algorithm>
Pilot::Pilot(std::string name, int skill) 
    : name_ (name.empty() ? "Unnamed" : std::move(name)),
      skill_(std::clamp(skill, 1, 100)) ,
       fatigue_(0),
       missions_(0) {}

void Pilot::rest() {
    fatigue_ -= 30;
    if (fatigue_ < 0) {
        fatigue_ = 0;
    }
}

bool Pilot::fly_mission() {
    if (fatigue_ > 80) {
        return false;
    }
    fatigue_ += 20;
    missions_ += 1;
    return true;
}

void Pilot::print() const {
    std::cout << name_ << " | skill " << skill_ 
    << " | fatigue "   << fatigue_ 
    << " | missions " << missions_ << '\n';
}

bool Pilot::set_name(const std::string& name){
    if (name.empty()){
    return false;
    }
     name_ = name;
     return true;
 }

void Pilot::change_skill(int change) {
    skill_ = std::clamp(skill_ + change, 1, 100);

}


std::string Pilot::name() const {
    return name_;
}

int Pilot::skill() const {
    return skill_;    
}

int Pilot::fatigue() const {
    return fatigue_;
}

int Pilot::missions() const {
    return missions_;
}
