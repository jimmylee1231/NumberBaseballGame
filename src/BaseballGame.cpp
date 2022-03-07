#include "../include/BaseballGame.h"

BaseballGame::BaseballGame()
{
    answerNumberString = "";
    userNumberString = "";
    numOfStrike = 0;
    numOfBall = 0;
    m_isGameDone = false;
}
bool BaseballGame::isGameDone()
{
}
void BaseballGame::initialize()
{
    numOfStrike = 0;
    generate3DigitRandomNumber();
}
int BaseballGame::getNumOfStrike()
{
}
void BaseballGame::input()
{
}
void BaseballGame::judge()
{
}
void BaseballGame::output()
{
}

void BaseballGame::generate3DigitRandomNumber()
{
}