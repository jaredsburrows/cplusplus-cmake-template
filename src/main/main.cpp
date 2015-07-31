#include <iostream>

#include <boost/filesystem.hpp>

int main(void) {

    std::cout << "Hello" << std::endl;
    boost::filesystem::path full_path( boost::filesystem::current_path() );
    std::cout << "Current path is : " << full_path << std::endl;

    return 0;
}

