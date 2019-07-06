#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Node2D.hpp>
#include <Sprite.hpp>
#include <AnimationPlayer.hpp>
#include <Input.hpp>
#include <Vector2.hpp>
#include <Area2D.hpp>
#include <algorithm>
#include <limits>
#include <CollisionShape2D.hpp>
#include <Node2D.hpp>
#include <random>
#include <algorithm>

namespace godot {

  class GameManager : public Node2D {
    GODOT_CLASS(GameManager, Node2D)


  public:
    GameManager();
    ~GameManager();
    static void _register_methods();
    void _init();
    void _process(float delta);
    void _ready();
    // random int
    // random float


  private:
    Vector2 screen_size;
    std::mt19937 rand;
  };

}

#endif
