#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "app.h"

void print_list(const std::list<app::App>& input_list) {
    std::for_each(input_list.begin(), input_list.end(), [](const app::App& item) {
        std::cout << item.app_name_ << ' ' << item.rank_ << std::endl;
    });
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " Filename" << std::endl;
        return 1;
    }    

    const std::string kFilename = argv[1];

    std::ifstream infile(kFilename);
    if (!infile.is_open()) {
        std::cout << "Could not open " << kFilename << std::endl;
        return 2;
    }

    std::list<app::App> apps_list;
    std::string line;
    while (std::getline(infile, line)) {
        int comma_position = line.find(',');

        app::App app;
        app.app_name_ = line.substr(0, comma_position);
        app.rank_ = std::stod(line.substr(comma_position + 1));

        apps_list.push_back(app);
    }

    infile.close();

    ::print_list(apps_list); // :: refers to Default Global Namespace

    return 0;
}