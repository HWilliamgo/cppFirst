#include <iostream>
#include <zconf.h>
#include <pthread.h>
#include "myutils.h"

using namespace std;
#define LIMIT 100
typedef struct data {
    int n;
    data *next;
} data;

unsigned int getH264NaluType(unsigned int data) {
    return data & 0x1Fu;
}

unsigned int getH265NaluType(unsigned int data) {
    return (data & 0x7Eu) >> 1u;
}

void undefineMethod();
//void undefineMethod(){}

typedef struct S {
    char c;
    double b;
} S;


#define FLAG_0 (1 << 0) // 1
#define FLAG_1 (1 << 1) // 2
#define FLAG_2 (1 << 2) // 4
#define FLAG_3 (1 << 3) // 8
#define FLAG_4 (1 << 4) // 16
#define FLAG_5 (1 << 5) // 32
#define FLAG_6 (1 << 6) // 64
#define FLAG_7 (1 << 7) // 128

void testString(std::string &input) {
    cout << &input << endl;
}

static void printX(const uint8_t *input, int count) {
    char *output = (char *) calloc(1, 5 * count * sizeof(uint8_t));

    for (int i = 0; i < count; i++) {
        char cs[5] = {0};
        sprintf(cs, "%x ", input[i]);
        strcat(output, cs);
    }
    printf("printX-> %s", output);
    free(output);
    output = NULL;
}

class A {
public:
    A() {
        printf("A create");
    }

    virtual ~A() {
        printf("A destroy");
    }
};

class B : public A {
public:
    B() {
        printf("B create");
    }

    ~B() {
        printf("B destroy");
    }
};

void testVargs(char *msg, ...) {
    va_list args;
    va_start(args, msg);
    printf(msg, args);
    va_end(args);
}

const char *TAG = __FILE__;

char *getFileNameFromPath(const char *input) {
    if (!input) {
        return nullptr;
    }
    int len = strlen(input);
    char sig = '/';
    int lastSigIndex = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (input[i] == sig) {
            lastSigIndex = i;
            break;
        }
    }
    if (lastSigIndex == -1) {
        return nullptr;
    }
    int retLen = len - lastSigIndex;
    char *ret = (char *) calloc(retLen + 1, sizeof(char));
    strncpy(ret, input + lastSigIndex + 1, retLen);
    return ret;
}

namespace {
    void testNamespace() {
        printf("main.cpp testNamespace");
    }
}


static void *threadA(void *args) {
    cout << "threadA" << endl;
    char *str = static_cast<char *>(args);
    cout << str << endl;
    return nullptr;
}

//static pthread_cond_t condv = PTHREAD_COND_INITIALIZER;
//static pthread_mutex_t mlock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t *condv = nullptr;
pthread_mutex_t *mlock = nullptr;

static data *phead = nullptr;

static void initLock() {
    condv = new pthread_cond_t;
    mlock = new pthread_mutex_t;
    pthread_mutex_init(mlock, nullptr);
    pthread_cond_init(condv, nullptr);
}

static void destroyLock() {
    pthread_mutex_destroy(mlock);
    pthread_cond_destroy(condv);
    delete condv;
    condv = nullptr;
    delete mlock;
    mlock = nullptr;
}

static void *producer(void *arg) {
    printf("producer thread running.\n");
    int count = 0;
    while (true) {
        int n = randomNum(100);
        data *nd = static_cast<data *>(malloc(sizeof(data)));
        memset(nd, 1, sizeof(data));
        nd->n = n;

        pthread_mutex_lock(mlock);
        // 头插法
        data *tmp = phead;
        phead = nd;
        nd->next = tmp;
        pthread_mutex_unlock(mlock);
        pthread_cond_signal(condv);

        count += n;

        if (count > LIMIT) {
            break;
        }
        sleep(rand() % 5);
    }
    printf("producer count=%d\n", count);
    return nullptr;
}

static void *consumer(void *arg) {
    printf("consumer thread running.\n");
    int count = 0;
    while (true) {
        pthread_mutex_lock(mlock);
        if (phead == nullptr) {
            pthread_cond_wait(condv, mlock);
        } else {
            while (phead != nullptr) {
                data *tmp = phead;
                count += tmp->n;
                phead = phead->next;
                free(tmp);
            }
        }
        pthread_mutex_unlock(mlock);
        if (count > LIMIT) {
            break;
        }
    }
    printf("consumer count=%d", count);
    return nullptr;
}

int flaga = 0x01;
int flagb = 0x02;
int flagc = 0x03;
int flagNone = 0;
int flag = 0;

void printBits(size_t const size, void const *const ptr) {
    unsigned char *b = (unsigned char *) ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int parseHexNaluType(int hexNaluValue) {
    int flag = 11100000;
    return hexNaluValue &= ~flag;
}

namespace {
}

#define STRING "hello world!"

int main() {
    int pipefd[2];
    char buf[BUFSIZ];
    if (pipe(pipefd) == -1) {
        perror("pipe()");
        exit(1);
    }
    if (write(pipefd[1], STRING, strlen(STRING)) < 0) {
        perror("write()");
        exit(1);
    }
    if (read(pipefd[0], buf, strlen(STRING)) < 0) {
        perror("read()");
        exit(1);
    }
    return 0;
}