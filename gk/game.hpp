#ifndef GAME_HPP
#define GAME_HPP

#include "level.hpp"
#include "objects/character.hpp"
#include "projector.hpp"
#include "fps_meter.hpp"
#include "crosshair.hpp"
#include "compass.hpp"

#include "Camera.hpp"
#include "Character.hpp"

extern Camera* camera;
extern Character* character;

extern level w;
extern projector p;
extern fps_meter f;
extern crosshair c;
extern compass s;

#endif //GAME_HPP
