#ifndef NPC_MANAGER_H
#define NPC_MANAGER_H

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

  class NPCManager : public Node2D {
    GODOT_CLASS(NPCManager, Node2D)


  public:
    NPCManager();
    ~NPCManager();
    static void _register_methods();
    void _init();
    void _process(float delta);
    void _ready();
    // random int
    int get_random_int(const int min, const int max);
    // random float
    float get_random_float(const float min, const float max);


  private:
    Vector2 screen_size;
    std::mt19937 rand;
    std::random_device rand_device;
  };

}

#endif
