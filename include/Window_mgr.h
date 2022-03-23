//
// Created by HWilliam on 2020/12/30.
//
#include "Screen.h"

#ifndef C__FIRST_WINDOW_MGR_H
#define C__FIRST_WINDOW_MGR_H


class Window_mgr {
private:
    std::vector<Screen> screens{Screen(24, 80, '1')};

};

#endif //C__FIRST_WINDOW_MGR_H
