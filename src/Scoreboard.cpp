#include "Scoreboard.hpp"
#include "utils/base64.hpp"
#include <algorithm>

Scoreboard::Scoreboard() {
  this->path = DATA_PATH + ".asteroids_score";
  this->initScores();
}

void Scoreboard::saveScore(std::string name, int score) {
  if (name.empty()) { return; }
  std::ofstream f(this->path, std::fstream::ios_base::app);
  std::string to_encode = name + ":" + std::to_string(score);
  f << base64_encode(reinterpret_cast<const unsigned char *>(to_encode.c_str()),
                     to_encode.length())
    << std::endl;
  this->scores.push_back(std::make_pair(name, score));
  this->sort();
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

    this->scores.push_back(std::make_pair(name, score));
  }
  this->sort();
}

void Scoreboard::sort() {
  std::sort(this->scores.begin(), this->scores.end(),
            [](auto &l, auto &r) { return l.second > r.second; });
}

void Scoreboard::updateMenu(const std::unique_ptr<Menu> &m, int width) {

  // init scores if not present
  if (m->components.find("s1") == m->components.end()) {
    for (int i = 0; i < 5; i++) {
      std::string key = "s" + std::to_string(i);
      m->addPlainText(key, "", {0, 200 + i * 100});
      m->components[key]->enabled = false;
    }
  }

  for (size_t i = 0; i < 5 && i < this->scores.size(); i++) {
    std::string key = "s" + std::to_string(i);
    m->components[key]->label =
        this->scores[i].first + " : " + std::to_string(this->scores[i].second);
    m->components[key]->centerHorizontally(width);
    m->components[key]->enabled = true;
  }
}
