//
// Created by HWilliam on 2021/6/12.
//
char global_c[100] = {0};

static void hello(char *input) {
    if (input) {
        input[0] = 'h';
        input[1] = 'e';
        input[2] = 'l';
        input[3] = 'l';
        input[4] = 'o';
    }
}

void out_hello(char *input) {
    hello(input);
}

char *out_invokeByInternal() {
    hello(global_c);
    return global_c;
}




