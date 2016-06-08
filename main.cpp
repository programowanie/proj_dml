#include <iostream>
#include "Team.h"
#include "Competitor.h"
#include <time.h>
#include <cstdlib>
using namespace std;

void Match (Team team1, Team team2);

int main()
{
    cout << "Welcome to the match of Dolnoslaskie Mecze Matematyczne!" << endl << endl;
    srand(time(NULL));

    Team team0;
    Team team1;

    Match (team0, team1);

    return 0;
}

void Match (Team team1, Team team2)
{
    Team teams[2]={team1, team2};
    bool exReturn[2], ifSolved[10];
    for (int i=0; i<10; i++)
        ifSolved[i]=false;
    exReturn[0]=false;
    exReturn[1]=false;
    int point[2];
    point[0]=0;
    point[1]=0;

    teams[0].Solving();
    teams[1].Solving();

    for (int i=0; i<8; i++)
    {
        cout << "EX NR " << i << endl;
        int random = rand()%10;
        while (ifSolved[random]==true)
            random = rand()%10;
        ifSolved[random]=true;

        bool teamAsk;
        if (i%2==0)
            teamAsk=false;
        else
            teamAsk=true;

        cout << "Team nr " << teamAsk << " is asking a task nr " << random << endl;
        if (exReturn[!teamAsk]==false)
        {
            int random1 = rand()%2;
            if (random1==1)
            {
                exReturn[!teamAsk]=true;
                cout << "Team nr " << !teamAsk << " is returning a task nr " << random << endl;
                cout << "Team nr " << teamAsk << " is solving a task nr " << random << endl;
                cout << "Team nr " << teamAsk << " scored " << 2*teams[teamAsk].points[random]-10 << endl;
                point[teamAsk]+=2*teams[teamAsk].points[random]-10;
            }
            else
            {
                cout << "Team nr " << !teamAsk << " is solving a task nr " << random << endl;
                cout << "Team nr " << !teamAsk << " scored " << teams[!teamAsk].points[random] << endl;
                point[!teamAsk]+=teams[!teamAsk].points[random];
            }
        }
        else
        {
            cout << "Team nr " << !teamAsk << " is solving a task nr " << random << endl;
            cout << "Team nr " << !teamAsk << " scored " << teams[!teamAsk].points[random] << endl;
            point[!teamAsk]+=teams[!teamAsk].points[random];
        }

    cout << "points: " << point[0] << " " << point[1] << endl << endl;
    }

    if (point[0]>point[1])
        cout << "The winner is team nr 0! Congratulations!" << endl << endl;
    if (point[0]<point[1])
        cout << "The winner is team nr 1! Congratulations!" << endl << endl;
    if (point[0]==point[1])
        cout << "The teams drew!" << endl << endl;

}


