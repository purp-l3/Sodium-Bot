#include "SodiumSentence.h"
#include "WordManager.h"

int main() 
{
    std::vector< std::vector<std::string> > words;
    std::vector< std::string > formats;

    words = WordManager::loadWords("../SodiumBot_/MyBot/words.dat");

    formats = WordManager::loadFormats("../SodiumBot_/MyBot/sentenceFormats.dat");

    /*INFO(formats.at(0));
    INFO(formats.at(1));
    INFO(formats.at(2));
    INFO(formats.at(3));
    INFO(formats.at(4));*/

    SodiumSentence::init();

    for (int i = 0; i < 10; ++i) 
    {
        SodiumSentence test(formats, words, "purp");
        test.print();
    }
    return 0;
}