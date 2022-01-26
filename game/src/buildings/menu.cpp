#include <string>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>

#include "menu.h"

Menu::Menu(void) {}

void Menu::showMenu(void) {
    TextStream::instance().setText(item1, 5, 5);
    TextStream::instance().setText(item2, 8, 5);
    TextStream::instance().setText(item3, 11, 5);
    TextStream::instance().setText(item3, 14, 5);
}