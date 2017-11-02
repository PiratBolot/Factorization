/*
 *
 *  Main programm for Windows version
 *  Usage - <main_file_name> <Source_file_name> <Output_file_name> *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "Factorizator.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Incorrect format of the input data. The number of parameters: " << argc - 1 << std::endl;
        std::cerr << "Usage - <main_file_name> <Source_file_name> <Output_file_name>" << std::endl;
        exit(1); // Don't have any objects yet.
    }
    std::ifstream input(argv[1], std::ios_base::in);
    if (!input) {
        std::cerr << "Can not open file : " << argv[1] << std::endl;
        exit(2);
    }
    std::ofstream output(argv[2], std::ios_base::trunc);
    if (!output) {
        std::cerr << "Can not open file : " << argv[1] << std::endl;
        exit(3);

    }
    std::string line;
    uint64_t number;
    while (input) {
        input >> line;
        std::istringstream converter(line);
        converter >> number;
        if (!converter.eof()) {
            std::cerr << "Incorrect input line: " << line << std::endl;
            continue;
        }
        Factorizator f(number);
        f.factorization();
        output << f.toString() << std::endl;
    }
    input.close();
    output.close();
    return 0;
}