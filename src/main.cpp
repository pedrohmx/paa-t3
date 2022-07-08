#include <iostream>
#include <cstdint>

#include "argparse/argparse.hpp"

#include "tree_node.hpp"
#include "bst.hpp"
#include "avl.hpp"

auto main(int argc, char *argv[]) -> int {
    argparse::ArgumentParser program("paat3","0.0.1");
    
    program.add_argument("buildfile")
        .help("File containing the data to build the trees")
        .required();

    program.add_argument("queryfile")
        .help("File containing the data to build the trees")
        .required();

    program.add_argument("-r")
        .help("Number of runs")
        .default_value(1)
        .scan<'i',int>()
        .nargs(1);

    program.add_argument("--output","-o")
        .help("CSV file to store the results");

    try
    {
        program.parse_args(argc, argv);
    }
    catch(const std::runtime_error& err)
    {
        std::cerr << err.what() << '\n';
        std::cerr << program;;
        std::exit(1);
    }

    std::cout << "Build -> " << program.get("buildfile") << std::endl;
    std::cout << "Query -> " << program.get("queryfile") << std::endl;
    std::cout << "Runs -> " << program.get<int>("-r") << std::endl;
    if (program.present("-o")) {
        std::cout << "Output -> " << program.get("-o") << std::endl;
    } else {
        std::cout << "No output file specified, dumping to stdout." << std::endl;
    }

    return 0;
}
