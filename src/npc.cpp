#include "npc.h"

using namespace godot;

void NPC::_register_methods() {
  register_method("_process", &NPC::_process);
  register_method("_ready", &NPC::_ready);
  register_property<NPC, int>("speed", &NPC::speed, 0);
  // register_signal<Simple>((String)"button_pressed", "node", GODOT_VARIANT_TYPE_OBJECT,
  //                           "data", GODOT_VARIANT_TYPE_STRING);
  register_signal<NPC>((char *)"hit");
}

NPC::NPC() {}
NPC::~NPC() {}

void NPC::_init() {
  if (speed == 0) {
    speed = 400;
  }


  direction = DIRECTION::SOUTH;
  Godot::print("In init for NPC!");
}

void NPC::_ready() {

  Godot::print("In ready!");
  sprite = cast_to<Sprite>(get_node("Sprite"));
  animation = cast_to<AnimationPlayer>(sprite->get_node("AnimationPlayer"));
  screen_size = get_viewport_rect().get_size();
  collider = cast_to<CollisionShape2D>(get_node("CollisionShape2D"));

  String screen = String("Screen size is x: {0} y: {1}")
    .format(Array::make(screen_size.x, screen_size.y));
  Godot::print(screen);

  Rect2 region_rect = sprite->get_region_rect();
  Vector2 region_rect_size = region_rect.get_size();
  Vector2 region_rect_position = region_rect.get_position();

  Godot::print(String("Sprite region size is x: {0} y {1}").format(Array::make(region_rect_size.x, region_rect_size.y)));
  Godot::print(String("Sprite region position is x: {0} y {1}").format(Array::make(region_rect_position.x, region_rect_position.y)));


  if (animation == nullptr) {
    Godot::print("animation is null");
  }
  // Should check for null
}

void NPC::_process(float delta) {
  Vector2 velocity{0, 0};

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
