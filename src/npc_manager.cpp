#include "npc_manager.h"

using namespace godot;

void NPCManager::_register_methods() {
  register_method("_process", &NPCManager::_process);
  register_method("_ready", &NPCManager::_ready);
  //register_property<NPCManager, int>("speed", &NPCManager::speed, 0);
  // register_signal<Simple>((String)"button_pressed", "node", GODOT_VARIANT_TYPE_OBJECT,
  //                           "data", GODOT_VARIANT_TYPE_STRING);
  //register_signal<NPCManager>((char *)"hit");
}

NPCManager::NPCManager() {}
NPCManager::~NPCManager() {}

void NPCManager::_init() {
  Godot::print("In init for NPCManager!");
  rand = std::mt19937{rand_device()};
}

void NPCManager::_ready() {

  Godot::print("In ready!");
}

void NPCManager::_process(float delta) {
}

int NPCManager::get_random_int(const int min, const int max) {
  std::uniform_int_distribution dis(min, max);
  int rand_int = dis(rand);

  return rand_int;
}

float NPCManager::get_random_float(const float min, const float max) {
  std::uniform_real_distribution dis(min, max);

  return dis(rand);
}
