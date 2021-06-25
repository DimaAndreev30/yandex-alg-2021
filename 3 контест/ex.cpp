#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>



using namespace std;


std::ifstream file("input.txt");

int main()
{
    unsigned numPupils;
    file >> numPupils;

    string lang;
    unsigned numLangs;
    unordered_set<string> allLangs, commonLangs;
    for (file >> numLangs; numLangs > 0; --numLangs)
    {
        file >> lang;
        allLangs.emplace(lang);
        commonLangs.emplace(lang);
    }

    unordered_set<string> langs;
    auto langIter = commonLangs.begin();
    for (unsigned i = 1; i < numPupils; ++i)
    {
        langs.clear();
        for (file >> numLangs; numLangs > 0; --numLangs)
        {
            file >> lang;
            langs.emplace(lang);
            allLangs.emplace(lang);
        }
        auto langIter = commonLangs.begin();
        while (langIter != commonLangs.end())
        {
            if (langs.find(*langIter) == langs.end())
                langIter = commonLangs.erase(langIter);
            else
                ++langIter;
        }
    }

    /*unsigned numCommonLangs = commonLangs.size();
    cout << numCommonLangs << endl;
    for (const string &lang : commonLangs)
    {
        cout << lang << endl;
    }

    unsigned numAllLangs = allLangs.size();
    cout << numAllLangs << endl;
    for (const string &lang : allLangs)
    {
        cout << lang << endl;
    }*/

    return EXIT_SUCCESS;
}