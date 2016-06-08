#pragma once
#include "Competitor.h"

class Team
{
    public:

        Competitor* comp[10];
        bool solve[10];
        int points[10];

        Team();
        ~Team();

        void SkillsView();
        void SolveView();
        void PointsView();

        void ExChoosing();
        void ExSolving();
        void ExPoints();
        void Solving();
};

