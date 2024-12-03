#ifndef APP_H
#define APP_H

#include <string>

namespace app {
class App {
  public:
    App(std::string app_name = "", int rank = -1);

    std::string app_name_;
    int rank_;
};

}  // namespace app

#endif  // APP_H