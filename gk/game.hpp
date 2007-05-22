#ifndef GAME_HPP
#define GAME_HPP

#include "world.hpp"
#include "objects/character.hpp"
#include "projector.hpp"
#include "fps_meter.hpp"
#include "crosshair.hpp"
#include "compass.hpp"

#include "Camera.hpp"
#include "Character.hpp"

static Camera* camera;
static Character* character;

static world w;
static projector p;
static fps_meter f;
static crosshair c(vertex(0.0f, 1.0f, 1.0f), 8.0f);
static compass s(50);

#endif //GAME_HPP
