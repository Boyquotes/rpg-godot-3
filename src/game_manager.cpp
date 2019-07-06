#include "game_manager.h"

using namespace godot;

void GameManager::_register_methods() {
  register_method("_process", &GameManager::_process);
  register_method("_ready", &GameManager::_ready);
  //register_property<GameManager, int>("speed", &GameManager::speed, 0);
  // register_signal<Simple>((String)"button_pressed", "node", GODOT_VARIANT_TYPE_OBJECT,
  //                           "data", GODOT_VARIANT_TYPE_STRING);
  //register_signal<GameManager>((char *)"hit");
}

GameManager::GameManager() {}
GameManager::~GameManager() {}

void GameManager::_init() {
  Godot::print("In init for GameManager!");
}

void GameManager::_ready() {

  Godot::print("In ready!");
}

void GameManager::_process(float delta) {
}
