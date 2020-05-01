#ifndef BUTTON_H
#define BUTTON_H

#include "UI/Clickable.hpp"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

class Button : public Clickable {
  public:
    Button(std::string label);
    Button(std::string label, glm::vec2 label_pos);
    Button(std::string label, glm::vec2 label_pos,
          std::function<void()> handler);

    /**
    * @brief Computes the bounding box
    */
    void computeBox();
    
    /**
    * @brief Draws element in window
    * 
    * @param renderer
    */
    void draw(SDL_Renderer *renderer);
};

#endif