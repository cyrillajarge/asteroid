#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <iostream>
#include "UI/UIComponent.hpp"

class TextInput : public UIComponent{
  public:
    /**
     * @brief Input text
     */
    std::string input = "";

  public:
    TextInput(std::string label, glm::vec2 position);
    
    /**
     * @brief Adds letter to input if symbol is allowed
     * 
     * @param e
     */
    void addLetter(SDL_Event e);
    
    /**
     * @brief Removes last letter from input
     */
    void removeLetter(SDL_Event e);

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