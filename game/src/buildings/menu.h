#ifndef GBA_GAME_MENU
#define GBA_GAME_MENU

#include <libgba-sprite-engine/background/text_stream.h>
#include <string>

class Menu {
private:
    
public:
    const char* item1;
    const char* item2;
    const char* item3;
    const char* item4;

    Menu();
    Menu(const char* item1, const char* item2, const char* item3, const char* item4) :
        item1(item1), item2(item2), item3(item3), item4(item4) { };
    void showMenu();
};

#endif // GBA_GAME_MENU