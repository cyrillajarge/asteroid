#include "Scoreboard.hpp"
#include "utils/base64.hpp"

Scoreboard::Scoreboard() {
  this->path = getenv("HOME") + std::string("/.hemoroids");
  std::cout << "Scoreboard dir : " << this->path << std::endl;
  this->initScores();
}

void Scoreboard::saveScore(std::string name, int score) {
  std::ofstream f(this->path, std::fstream::ios_base::app);
  std::string to_encode = name + ":" + std::to_string(score);
  f << base64_encode(reinterpret_cast<const unsigned char *>(to_encode.c_str()), to_encode.length()) << std::endl;
}

void Scoreboard::initScores() {
  std::ifstream f(this->path);
  std::string bs;
  std::string sep = ":";
  while (std::getline(f, bs)) {
    int score;
    std::string name;
    std::string s = base64_decode(bs);
    try {
      size_t pos = s.find(sep);
      name = s.substr(0, pos);
      score = std::stoi(s.substr(pos + 1, s.length()));
    } catch (std::exception e) {
      std::cerr << "Error parsing score file" << std::endl;
      continue;
    }

    this->scores[name] = score;
  }
}

void Scoreboard::draw() {
  std::cout << this->scores.size() << std::endl;
  for (std::pair<std::string, int> p : this->scores) {
    std::cout << p.first << " - " << p.second << std::endl;
  }
}
