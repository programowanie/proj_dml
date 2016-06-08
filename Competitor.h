#pragma once

class Competitor
{
    public:
        int skill[10];
        int chance[10];
        Competitor();
        ~Competitor();
        void View();
        int GetSkill(int i);
        int GetChance(int i);
};

