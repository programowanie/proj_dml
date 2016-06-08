#include "Team.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

Team::Team()
{
    for(int i=0; i<10; i++)
        comp[i] = new Competitor();
}

Team::~Team()
{
    delete [] comp;
}

//////////////////////////////////////////////////////
void Team::SkillsView()
{
    for (int i=0; i<10; i++)
    {
        cout << "competitor nr " << i << ": " << endl;
        comp[i]->View();
    }

}

//////////////////////////////////////////////////////
void Team::SolveView()
{
    for (int i=0; i<10; i++)
        cout << "solved " << i << ": " << solve[i] << endl;
}

//////////////////////////////////////////////////////
void Team::PointsView()
{
    for (int i=0; i<10; i++)
        cout << "points " << i << ": " << points[i] << endl;
}

//////////////////////////////////////////////////////
void Team::ExChoosing()
{
    for (int i=0; i<10; i++)
    {
        Competitor bestCompetitor = *comp[i];
        for (int j=i+1; j<9; j++)
        {
            if (comp[j]->GetSkill(i) > bestCompetitor.skill[i])
                bestCompetitor = *comp[j];
        }

        Competitor tmp = *comp[i];
        *comp[i] = bestCompetitor;
        bestCompetitor = tmp;
    }
}
//////////////////////////////////////////////////////
void Team::ExSolving()
{
    srand(time(NULL));
    for (int i=0; i<10; i++)
    {
        int random = rand()%100;
        if (random < comp[i]->GetSkill(i))
            solve[i]=true;
        else
            solve[i]=false;
    }
}

///////////////////////////////////////////////////////
void Team::ExPoints()
{
    srand(time(NULL));
    for (int i=0; i<10; i++)
    {
        if (solve[i]==true)
        {
            points[i]=6;
            for (int j=10; j>6; j--)
            {
                int random = rand()%100;
                if (random < comp[i]->GetChance(i))
                {
                    points[i]=j;
                    break;
                }
            }
        }

        if (solve[i]==false)
        {
            points[i]=0;
            for (int j=5; j>0; j--)
            {
                int random = rand()%100;
                if (random < comp[i]->GetChance(i))
                {
                    points[i]=j;
                    break;
                }
            }
        }
    }
}

///////////////////////////////////////////////////////
void Team::Solving()
{
    ExChoosing();
    ExSolving();
    ExPoints();
}




