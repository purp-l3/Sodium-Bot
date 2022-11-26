#include "WordManager.h"

std::vector< std::vector<std::string> > WordManager::loadWords(std::string filename) 
{
    std::ifstream userFile;
    std::string currentLine;
    
    std::vector< std::vector<std::string> > loadedWords;
    loadedWords.resize(WORDLIST_SIZE);

    userFile.open(filename);

    if(!userFile.is_open()) { throw std::invalid_argument("[ERROR] File not opened. "); }

    while(std::getline(userFile, currentLine)) 
    {
        std::istringstream firstWord(currentLine);
        std::string currWord;

        firstWord >> currWord;
        switch(currWord.at(0)) 
        {
            // adjective:
            case 'a':
                loadedWords.at(ADJECTIVE_INDEX).push_back(currentLine.substr(10, currentLine.size() - 11));
                break;
            // noun:
            case 'n':
                loadedWords.at(NOUN_INDEX).push_back(currentLine.substr(5, currentLine.size() - 6));
                break;
            // verb:
            case 'v':
                loadedWords.at(VERB_INDEX).push_back(currentLine.substr(5, currentLine.size() - 6));
                break;
            default:
                throw std::invalid_argument("Invalid type found.");
        }
    }
    
    userFile.close();
    return loadedWords;
}

std::vector<std::string> WordManager::loadFormats(std::string filename) 
{
    std::ifstream userFile;
    std::string currentLine;

    std::vector<std::string> loadedFormats;

    userFile.open(filename);

    if(!userFile.is_open()) { throw std::invalid_argument("[ERROR] File not opened. "); }

    while(std::getline(userFile, currentLine)) 
    {
        loadedFormats.push_back(currentLine);
    }

    userFile.close();
    return loadedFormats; 
}