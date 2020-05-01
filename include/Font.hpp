#ifndef FONT_H
#define FONT_H

#include "Hershey.hpp"
#include "SDL2/SDL.h"
#include <iostream>

class Font {
public:
  /**
   * @brief Scale factor of the font. Defaults to 1.
   *
   */
  double size;

  /**
   * @brief Spacing between two letters
   *
   */
  int spacing;

  /**
   * @brief Font color
   *
   */
  SDL_Color color;

  Font();
  Font(double size);
  Font(SDL_Color color);
  ~Font();

  /**
   * @brief Draws a letter at (x, y). Returns the horizontal space taken.
   *
   * @param renderer
   * @param letter
   * @param x
   * @param y
   * @return int
   */
  int drawLetter(SDL_Renderer *renderer, char letter, int x, int y);

  /**
   * @brief Draws a text at (x, y). Returns the horizontal space taken.
   *
   * @param renderer
   * @param text
   * @param x
   * @param y
   * @return int
   */
  int drawText(SDL_Renderer *renderer, std::string text, int x, int y);

  /**
   * @brief Returns a letter width (scaling included).
   *
   * @param letter
   * @return int
   */
  int getLetterWidth(char letter);

  /**
   * @brief Returns the x coordinate where text ends.
   *
   * @param text
   * @param x
   * @return int
   */
  int getEndPos(std::string text, int x);


  /**
   * @brief Returns the width of the text.
   *
   * @param text
   * @return int
   */
  int getWidth(std::string text);
};

#endif