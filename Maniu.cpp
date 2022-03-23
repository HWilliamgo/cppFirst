//
// Created by HWilliam on 2020/12/20.
//

#include "include/Maniu.h"
#include "iostream"

using namespace std;

Maniu::Maniu(int age) : age(age) {
    cout << "init by one param" << endl;
}

Maniu::Maniu(int age, int b, int c) : age(age), b(b), c(c) {
    cout << "init by three param" << endl;
}

int Maniu::getAge() {
    return age;
}

void Maniu::setAge(int age) {
    this->age = age;
}

namespace {
    void testNamespace() {
        printf("Maniu.cpp testNamespace");
    }
}

void ManiuTestNamespace() {
    testNamespace();
}
