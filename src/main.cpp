#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

#include "argparse/argparse.hpp"

#include "tree_node.hpp"
#include "bst.hpp"
#include "avl.hpp"

auto main(int argc, char *argv[]) -> int {
    using std::cout;
    using std::cerr;
    using std::endl;

    using paa::t3::BST;
    using paa::t3::AVL;

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
        .default_value(std::string("output.csv"))
        .help("CSV file to store the results");

    try
    {
        program.parse_args(argc, argv);
    }
    catch(const std::runtime_error& err)
    {
        cerr << err.what() << '\n';
        cerr << program;;
        std::exit(1);
    }

    std::string str_build, str_query, str_out;

    str_build = program.get<std::string>("buildfile");
    str_query = program.get<std::string>("queryfile");
    str_out   = program.get<std::string>("-o");
    int runs  = program.get<int>("-r");

    cout << "Build -> "  << str_build << endl;
    cout << "Query -> "  << str_query << endl;
    cout << "Runs -> "   << runs      << endl;
    cout << "Output -> " << str_out   << endl;

    // Store input file contens
    std::vector<long> in_build, in_query;

    // load from files
    {
        long value;

        std::ifstream ifs_build(str_build);
        while (ifs_build >> value) {
            in_build.push_back(value);
        }
        
        std::ifstream ifs_query(str_query);
        while(ifs_query >> value) {
            in_query.push_back(value);
        }
    }

    // write results to output
    std::ofstream ofs_output(str_out);

    // run tests
    for (int r = 0; r < runs; r++) {
        cout << "Running [" << r+1 << '/' << runs << "]" << endl;

        BST bst;
        for (auto i : in_build) {
            bst.insert(i);
        }
        for (auto i : in_query) {
            bst.search(i);
        }

        AVL avl;
        for (auto i : in_build) {
            avl.insert(i);
        }
        for (auto i : in_query) {
            avl.search(i);
        }

        cout << "BST: B-> " << bst.get_insertion_cmp_count() << " Q-> " << bst.get_search_cmp_count() << endl;
        cout << "AVL: B-> " << avl.get_insertion_cmp_count() << " Q-> " << avl.get_search_cmp_count() << endl;
    }
    

    return 0;
}
