//
// Created by xmly on 2019/9/15.
//

#ifndef CLEARNING_SCREEN_H
#define CLEARNING_SCREEN_H


#include <string>

class Screen {
public:
    Screen &set(char);
    Screen &set(int, int, char);
    std::string getString(){
        return contents;
    }
private:
    char contents[20]="fjefefhjefhef";
};
 inline Screen &Screen::set(char c) {
    contents[1]=c;
    return *this;
}

#endif //CLEARNING_SCREEN_H
