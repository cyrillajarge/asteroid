#ifndef UICOMP_H
#define UICOMP_H

#include "Font.hpp"
#include "SDL2/SDL.h"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"
#include <iostream>

#define DEFAULT_PADDING 10
#define TEXT_HEIGHT 23

struct padding {
  int top;
  int right;
  int bottom;
  int left;
};

class UIComponent {
  public:
    /**
     * @brief Defines elemnts visibility
     */
    bool enabled = true;

    /**
     * @brief Defines elements position
     */
    glm::vec2 position;

    /**
     * @brief Bounding box position and width and height.
     * Position corresponds to top left corner.
     */
    int xbox, ybox, wbox, hbox;

    /**
     * @brief Padding inside bounding box
     */
    struct padding padding = {DEFAULT_PADDING, DEFAULT_PADDING, DEFAULT_PADDING,
                              DEFAULT_PADDING};
    
    /**
     * @brief Elements label
     */
    std::string label;

    /**
     * @brief Font used for the text
     */
    static Font *font;

    /**
     * @brief Defines if elements borders are displayed or not
     */
    bool border = false;

    /**
     * @brief Defines border color
     */
    glm::vec4 border_color = {255,255,255,255};

  public:
    
    /**
    * @brief Sets padding using values for each direction
    * 
    * @param top
    * @param right
    * @param bottom
    * @param left
    */
    void setPadding(int top, int right, int bottom, int left);
    
    /**
    * @brief Sets padding using values for vertical and horizontal direction
    * 
    * @param v
    * @param h 
    */
    void setPadding(int v, int h);
    
    /**
    * @brief Sets padding using a single value for all orientations
    * 
    * @param val
    */
    void setPadding(int val);
    
    /**
    * @brief Sets horizontal position.
    * 
    * @param x
    */
    void setX(int x);
    
    /**
    * @brief Sets vertical position
    * 
    * @param y
    */
    void setY(int y);
    
    /**
    * @brief Moves element horizontally
    * 
    * @param x
    */
    void moveX(int x);
    
    /**
    * @brief Moves element vertically
    * 
    * @param y
    */
    void moveY(int y);
    
    /**
    * @brief Sets position
    * 
    * @param x
    * @param y 
    */
    void setPosition(int x, int y);
    
    /**
    * @brief Centers vertically in window
    * 
    * @param height 
    */
    void centerVertically(int height);
    
    /**
    * @brief Centers horizontally in window
    * 
    * @param width
    */
    void centerHorizontally(int width);
    
    /**
    * @brief Centers element in window
    * 
    * @param height
    * @param width
    */
    void center(int height, int width);
    
    /**
    * @brief Draws element in window
    * 
    * @param renderer
    */
    virtual void draw(SDL_Renderer *renderer) = 0;
    
    /**
    * @brief Computes the bounding box
    */
    virtual void computeBox() = 0;
    
    /**
    * @brief Destructor
    */
    virtual ~UIComponent() {}

};

#endif