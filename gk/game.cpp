#include "game.hpp"

Camera* camera;
Character* character;

level w;
projector p(vertex(0.0f, 1.0f, 1.0f));
fps_meter f;
crosshair c(8.0f);
compass s(50);
