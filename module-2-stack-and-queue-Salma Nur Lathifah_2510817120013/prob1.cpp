#include "stack.h"
#include <iostream>
#include <string>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;

    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        std::string token;
        std::cin >> token;

        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            push(&s, std::stoi(token));
        } else {
            int val2 = peek(&s); pop(&s);
            int val1 = peek(&s); pop(&s);

            if (token == "+") push(&s, val1 + val2);
            else if (token == "-") push(&s, val1 - val2);
            else if (token == "*") push(&s, val1 * val2);
            else if (token == "/") push(&s, val1 / val2);
        }
    }

    std::cout << peek(&s) << std::endl;
    return 0;
}