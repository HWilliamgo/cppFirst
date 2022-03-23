//
// Created by HWilliam on 2020/12/30.
//

#ifndef C__FIRST_SCREEN_H
#define C__FIRST_SCREEN_H


class Screen {
public:
    typedef std::string::size_type pos;

    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {};

    char get() const {
        return contents[cursor];
    }

    inline char get(pos ht, pos wd) const;

    Screen &set(char);

    Screen &set(pos, pos, char);

    Screen &move(pos r, pos c);

    void some_member() const;

    const Screen &display(int count) const;


private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;

};

Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const {
    ++access_ctr;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}

const Screen &Screen::display(int count) const {
    return *this;
}

#endif //C__FIRST_SCREEN_H
