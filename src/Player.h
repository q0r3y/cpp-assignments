#ifndef PIG_DICE_PLAYER_H
#define PIG_DICE_PLAYER_H

using std::string;

class Player {
    private:
        string name;
        int totalPoints;
        int roll;
        int turnPoints;
    public:
        Player(string name);
        void setTotalPoints(int points);
        void setName(string name);
        int getTotalPoints();
        string getName();
        void setCurrentRoll(int value);
        int getCurrentRoll() const;
        void setTurnPoints(int points);
        int getTurnPoints();
};


#endif //PIG_DICE_PLAYER_H
