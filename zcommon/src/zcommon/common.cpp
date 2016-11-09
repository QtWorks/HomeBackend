#include "common.h"

std::vector<std::string> Common::split(std::string str, char delimiter) {
    std::vector<std::string> vector_result;
    std::stringstream ss(str); // Turn the string into a stream.
    std::string tok;

    while (getline(ss, tok, delimiter)) {
        vector_result.push_back(tok);
    }

    return vector_result;
}

std::string Common::generatorUsers() {
    return "";
}
