#ifndef PLAYER_H
#define PLAYER_H

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

namespace godot {
  enum class DIRECTION { NORTH, SOUTH, EAST, WEST };

  class Player : public Node2D {
    GODOT_CLASS(Player, Node2D)

  public:
    int speed;

    Player();
    ~Player();
    static void _register_methods();
    void _init();
    void _process(float delta);
    void _ready();


  private:
    Sprite *sprite;
    AnimationPlayer *animation;
    Vector2 screen_size;
    DIRECTION direction;

  };

}

#endif
