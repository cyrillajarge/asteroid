#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "UI/Clickable.hpp"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

class Checkbox : public Clickable{
  public:
    /**
     * Checkbox status
     */
    bool checked = false;

  public:
    Checkbox(std::string label);
    Checkbox(std::string label, glm::vec2 position);
    Checkbox(std::string label, glm::vec2 position,
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
    void draw(SDL_Renderer* renderer);
};

#endif