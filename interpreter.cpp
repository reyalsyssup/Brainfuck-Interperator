#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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

int main(int argc, char *argv[]) {
    std::ifstream file(argv[1]);
    std::string code;
    if(!file.is_open()) {
        std::cout << "File " << argv[1] << " failed to open\n";
        return 0;
    }
    std::string line;
    std::vector<std::string> lines = std::vector<std::string>();
    while(getline(file, line)) {
        lines.push_back(line);
    }
    for(std::string line : lines) {
        for(char letter : line) {
            code.push_back(letter);
        }
    }
    compile(code);
}