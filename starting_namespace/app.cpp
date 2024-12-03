#include "app.h"

namespace app {
App::App(std::string app_name, int rank) : app_name_(app_name), rank_(rank) {}
}  // namespace app