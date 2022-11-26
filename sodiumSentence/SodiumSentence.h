#ifndef SODIUMSENTENCE
#define SODIUMSENTENCE

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include "WordManager.h"


#define INFO(x) std::cout << "[INFO] (" << __FUNCTION__ << " : " << __LINE__ << ") : " << x << std::endl
#define PRINTVAR(x) std::cout << "(" << x << ")" << std::endl


class SodiumSentence 
{
private:
    std::string m_format;
    std::string m_sentence;

public:
    SodiumSentence();
    SodiumSentence(std::vector<std::string> formats, std::vector< std::vector<std::string> > words, std::string Pnoun);

    static void init(); // must be called ONCE in the program before creation. seeds pseudo-random numbers. usage: SodiumSentence::init();
    void print();
    std::string getSentence();
    void clear();

    ~SodiumSentence();
};

#endif