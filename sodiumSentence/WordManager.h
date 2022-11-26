#ifndef WORDMANAGER
#define WORDMANAGER

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

const int ADJECTIVE_INDEX = 0;
const int NOUN_INDEX = 1;
const int VERB_INDEX = 2;

const std::size_t WORDLIST_SIZE = 3;

class WordManager 
{
public:
    static std::vector<std::vector<std::string>> loadWords(std::string filename);
    static std::vector<std::string> loadFormats(std::string filename);
};

#endif