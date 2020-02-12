#ifndef BUTTON_H
#define BUTTON_H

#include "UI/Clickable.hpp"
#include "glm/vec2.hpp"

class Button : public Clickable {
public:
  Button(std::string label, glm::vec2 label_pos);
  Button(std::string label, glm::vec2 label_pos,
         std::function<void()> handler);
  // ~Button();

public:
  bool border = false;

public:
  void draw(SDL_Renderer *renderer);
  void setX(int x);
  void setY(int y);
  void setPos(int x, int y);

private:
  glm::vec2 label_pos;

private:
  void computeBox();
};

#endif