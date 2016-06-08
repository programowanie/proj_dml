#include "Competitor.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;

Competitor::Competitor()
{
    for(int i=0; i<10; i++)
        skill[i] = (rand()%81);
    for(int i=0; i<10; i++)
        chance[i] = (rand()%46);

}

void Competitor::View()
{
    cout << "skills:" << endl;
    for (int i=0; i<10; i++)
    {
        cout << i << ": " << skill[i] << endl;
    }

    cout << "chances:" << endl;
    for (int i=0; i<10; i++)
    {
        cout << i << ": " << chance[i] << endl;
    }

}

int Competitor::GetSkill(int i)
{
    return skill[i];
}

int Competitor::GetChance(int i)
{
    return chance[i];
}

Competitor::~Competitor()
{
}

