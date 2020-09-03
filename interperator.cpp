#include <iostream>
#include <vector>

void compile(std::string data) {
    int tape[30000] = {0};
    int ptr = 0;
    std::vector<int> loopIndexes = std::vector<int>();
    int loops = 0;
    bool isLoop = false;

    for(int i = 0; i < data.length(); i++) {
        if(isLoop) {
            if(data[i] == '[') loops++;
            if(data[i] == ']') {
                // if there are no loops happening
                if(loops == 0) isLoop = false;
                else loops--;
            }
        }

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
        else if(data[i] == '[') {
            if(tape[ptr] == 0) isLoop = true;
            else loopIndexes.push_back(i);
        }
        else if(data[i] == ']') {
            if(tape[ptr] != 0) i = loopIndexes[loopIndexes.size()-1];
            else loopIndexes.pop_back();
        }
    }
    // this prints out the tape
    // only used in dev or debugging
    // for(int i = 0; i < 20; i++) {
    //     std::cout << tape[i] << " ";
    // }
    // std::cout << "\n";
}

int main() {
    std::string code;
    std::cin >> code;
    compile(code);
}