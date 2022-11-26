#include "../sodiumSentence/SodiumSentence.h"

SodiumSentence::SodiumSentence() 
{
    m_sentence = "Default Sentence.";
}

SodiumSentence::SodiumSentence(std::vector<std::string> formats, std::vector<std::vector<std::string>> word, std::string Pnoun) 
{
    // get random format:
    int rNum = rand(); 
    int formatIdx = rNum % formats.size();
    m_format = formats.at(formatIdx);


    std::istringstream format(m_format);
    std::string tempWord;

    // put random words into the sentence:
    while(!format.eof()) 
    {
        format >> tempWord;

        if (tempWord.substr(0, 7) == "[Pnoun]") 
        {
            m_sentence.append(Pnoun.substr(0, (Pnoun.size() - 5)));
            if (tempWord.size() > 7) m_sentence.append(tempWord.substr(7));
        }
        else if (tempWord.substr(0, 11) == "[adjective]") 
        {
            int adjIdx = rand() % word.at(ADJECTIVE_INDEX).size();
            std::string newWord = word.at(ADJECTIVE_INDEX).at(adjIdx);

            m_sentence.append(newWord);
            if (tempWord.size() > 11) m_sentence.append(tempWord.substr(11));
        }
        else if (tempWord.substr(0, 6) == "[verb]")
        {
            int vbIdx = rand() % word.at(VERB_INDEX).size();
            std::string newWord = word.at(VERB_INDEX).at(vbIdx);
            
            m_sentence.append(newWord);
            if (tempWord.size() > 6) m_sentence.append(tempWord.substr(6));
        }
        else if (tempWord.substr(0, 6) == "[noun]")
        {
            int nIdx = rand() % word.at(NOUN_INDEX).size();
            std::string newWord = word.at(NOUN_INDEX).at(nIdx);

            m_sentence.append(newWord);
            if (tempWord.size() > 6) m_sentence.append(tempWord.substr(6));
        }
        else 
        {
            m_sentence.append(tempWord);
        }
        m_sentence.append(" ");
        tempWord.clear();
    }
    //m_sentence.pop_back();
    //m_sentence.pop_back();
}

void SodiumSentence::init() 
{
    srand((unsigned int)time(NULL));
}

void SodiumSentence::print() 
{
    std::cout << "Current Sentence: \"" << m_sentence << "\"" << std::endl;
}

std::string SodiumSentence::getSentence() 
{
    return m_sentence;
}

void SodiumSentence::clear() 
{
    m_format.clear();
    m_sentence.clear();
}

SodiumSentence::~SodiumSentence() 
{
    this->clear();
}