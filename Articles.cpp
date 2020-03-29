/*
    Articles.cpp

    Summarize usage frequencey of English language articles
*/

#include <iostream>
#include <fstream>
#include <string>
#include "WordReader.hpp"

int main(int argc, char* argv[]) {

    // require filename
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    // number of each English language article
    int articleTheCount = 0;
    int articleAnCount = 0;
    int articleACount = 0;

    // count the articles from the input file
    WordReader reader(
        [&](const std::string& word)->void {
            if (word == "the")
                ++articleTheCount;
            else if (word == "an")
                ++articleAnCount;
            else if (word == "a")
                ++articleACount;
        }
    );
    std::ifstream in(argv[1]);
    reader.run(in);

    // output report on English-language articles
    std::cout << "the" << ": " << articleTheCount << '\n';
    std::cout << " an" << ": " << articleAnCount << '\n';  
    std::cout << "  a" << ": " << articleACount << '\n';   

    return 0;
}
