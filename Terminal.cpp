#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

string cd(std::string newPath_str, fs::path current_path) {

    std::string newPath = current_path.u8string() + "\\" + newPath_str;
    cout << newPath << "\n";
    for (const auto & entry : fs::directory_iterator(current_path))
    {
        if (entry.path().u8string().compare(newPath) == 0) {
            return newPath;
            break;
        }
    }
    return "";
    
}


int main() {
    fs::path current_path = fs::current_path();
    std::cout << current_path.u8string() << " ";
    std::string user_input;
    getline(cin, user_input);
    std::cout << "\n";
    if (user_input.substr(0, 2) == "ls") {
        for (const auto& entry : fs::directory_iterator(current_path))
            std::cout << entry.path().u8string() << std::endl;
    }
    else if (user_input.substr(0, 3) == "cd ") {
        std::string newPath_str = user_input.erase(0, 3);
        std::string dir = cd(newPath_str, current_path);
        if (dir != "") {
            current_path = fs::path(dir);
            std::cout << current_path.u8string();
        }
        else {

            std::cout << "The directory which you have specified does not exist!\n";
        }
        
        
    }
}

