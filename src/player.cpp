#include "player.h"

using namespace godot;


void Player::_register_methods() {  
  register_method("_process", &Player::_process);
  register_method("_ready", &Player::_ready);
  register_property<Player, int>("speed", &Player::speed, 0);
  // register_signal<Simple>((String)"button_pressed", "node", GODOT_VARIANT_TYPE_OBJECT,
  //                           "data", GODOT_VARIANT_TYPE_STRING);
  register_signal<Player>((char *)"hit");
}

Player::Player() {}

Player::~Player() {}

void Player::_init() {
  if (speed == 0) {
    speed = 400;
  }

  direction = DIRECTION::SOUTH;
  Godot::print("In init!");
}

void Player::_ready() {

  sprite = cast_to<Sprite>(get_node("Sprite"));
  animation = cast_to<AnimationPlayer>(sprite->get_node("AnimationPlayer"));
  screen_size = get_viewport_rect().get_size();
  collider = cast_to<CollisionShape2D>(get_node("CollisionShape2D"));

  String screen = String("Screen size is x: {0} y: {1}")
    .format(Array::make(screen_size.x, screen_size.y));
  Godot::print(screen);

  if (animation == nullptr) {
    Godot::print("animation is null");
  }
  // Should check for null
}

void Player::_process(float delta) {
  Vector2 velocity{0, 0};

  Input *i = Input::get_singleton();
  if (i->is_action_pressed("ui_right")) {
    velocity.x += 1;
  }

  if (i->is_action_pressed("ui_left")) {
    velocity.x -= 1;
  }

  if (i->is_action_pressed("ui_down")) {
    velocity.y += 1;
  }

  if (i->is_action_pressed("ui_up")) {
    velocity.y -= 1;
  }

  if (velocity.length() > 0) {
    velocity = velocity.normalized() * speed;

  } else {
  }

  Vector2 position = this->get_position();
  //  position += velocity * delta;
  position += velocity;
  //  position.x = std::clamp(position.x, 0.0f, std::numeric_limits<float>::max());
  //  position.y = std::clamp(position.y, 0.0f, std::numeric_limits<float>::max());

  //this->set_position(position);
  move_and_slide(velocity);

  if (velocity.x > 0) {
    animation->play("walk_east");
    direction = DIRECTION::EAST;
  } else if (velocity.x < 0) {
    animation->play("walk_west");
    direction = DIRECTION::WEST;
  } else if (velocity.y > 0) {
    animation->play("walk_south");
    direction = DIRECTION::SOUTH;
  } else if (velocity.y < 0) {
    animation->play("walk_north");
    direction = DIRECTION::NORTH;
  } else {
    switch (direction) {
      case DIRECTION::WEST:
        animation->play("idle_west");
        break;
      case DIRECTION::EAST:
        animation->play("idle_east");
        break;
      case DIRECTION::NORTH:
        animation->play("idle_north");
        break;
      case DIRECTION::SOUTH:
      default:
        animation->play("idle_south");
        break;
    }
  }
}
