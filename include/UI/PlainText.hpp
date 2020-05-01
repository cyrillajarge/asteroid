#ifndef PLAINTEXT_HPP
#define PLAINTEXT_HPP

#include "UI/UIComponent.hpp"

class PlainText : public UIComponent{
  public:
    PlainText(std::string label, glm::vec2 position);

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
