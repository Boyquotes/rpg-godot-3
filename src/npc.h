#ifndef NPC_H
#define NPC_H

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
#include <KinematicBody2D.hpp>
#include "player.h"
#include <random>
#include <algorithm>
#include "npc_manager.h"

namespace godot {
  //  enum class DIRECTION { NORTH, SOUTH, EAST, WEST };

  class NPC : public KinematicBody2D {
    GODOT_CLASS(NPC, KinematicBody2D)


  public:
    int speed;
    NPCManager *manager;


    NPC();
    ~NPC();
    static void _register_methods();
    void _init();
    void _process(float delta);
    void _ready();


  private:
    Sprite *sprite;
    AnimationPlayer *animation;
    Vector2 screen_size;
    CollisionShape2D *collider;
    DIRECTION direction;

    const static unsigned int HORIZONTAL_SHEET_SIZE = 156;
    const static unsigned int VERTICAL_SHEET_SIZE = 290;
    const static unsigned int HORIZONTAL_SPRITE_COUNT = 4;
    const static unsigned int VERTICAL_SPRITE_COUNT = 2;
  };

}

#endif
