#include "../include/BaseballGame.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

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
    return m_isGameDone;
}
void BaseballGame::initialize()
{
    numOfStrike = 0;
    srand(time(NULL));
    generate3DigitRandomNumber();
}
int BaseballGame::getNumOfStrike()
{
    return numOfStrike;
}

bool BaseballGame::isNumber(char ch)
{
    bool res = false;

    if (ch >= '0' && ch <= '9')
    {
        res = true;
    }

    return res;
}

bool BaseballGame::isInputNumberWrong()
{
    bool res = false;

    if (userNumberString.size() != 3)
    {
        res = true;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (!isNumber(userNumberString[i]))
            {
                res = true;
                break;
            }
        }
    }

    return res;
}

void BaseballGame::input()
{
    userNumberString = "";
    while (isInputNumberWrong())
    {
        cout << "Enter 3 digit number" << endl;
        cin >> userNumberString;
    }
}
void BaseballGame::judge()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (userNumberString[i] == answerNumberString[j])
            {
                if (i == j)
                    numOfStrike++;
                else
                    numOfBall++;
            }
        }
    }
}
void BaseballGame::output()
{
    cout << "Strike(";
    cout << numOfStrike;
    cout << "), ";
    cout << "Ball(";
    cout << numOfBall;
    cout << ")" << endl;

    if (numOfStrike == 3)
    {
        cout << "Correct Number!" << endl;
    }
}
void BaseballGame::generate3DigitRandomNumber()
{
    bool hasNumber[10] = {
        false,
    };
    int number;

    number = rand() % 10;
    answerNumberString += to_string(number);
    hasNumber[number] = true;

    number = rand() % 10;
    while (hasNumber[number])
    {
        number = rand() % 10;
    }
    answerNumberString += to_string(number);
    hasNumber[number] = true;

    number = rand() % 10;
    while (hasNumber[number])
    {
        number = rand() % 10;
    }
    answerNumberString += to_string(number);

    cout << answerNumberString << endl;
}