//
// Created by HWilliam on 2020/12/20.
//

#ifndef C__FIRST_MANIU_H
#define C__FIRST_MANIU_H


class Maniu {
public:
    Maniu(int age);

    Maniu(int age, int b, int c);

private:
    int b;
    int age;
protected:
    int c;

public:
    int getAge();

    void setAge(int age);
};

void ManiuTestNamespace();


#endif //C__FIRST_MANIU_H
