#include "game.hpp"

Camera* camera;
Character* character;

level w;
projector p;
fps_meter f;
crosshair c(vertex(0.0f, 1.0f, 1.0f), 8.0f);
compass s(50);
