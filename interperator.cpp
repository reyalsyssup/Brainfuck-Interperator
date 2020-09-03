#include <iostream>

void compile(std::string data) {
    int tape[30000] = {0};
    int ptr = 0;

    for(int i = 0; i < data.length(); i++) {
        if(data[i] == '+') tape[ptr]++;
        else if(data[i] == '-') tape[ptr]--;
        else if(data[i] == '>') ptr++;
        else if(data[i] == '<') ptr--;
        else if(data[i] == '.') std::cout << char(tape[ptr]);
        else if(data[i] == ',') {
            char input;
            std::cin >> input;
            tape[ptr] = int(input);
        }
    }
    for(int i = 0; i < 20; i++) {
        std::cout << tape[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::string code;
    std::cin >> code;
    compile(code);
}