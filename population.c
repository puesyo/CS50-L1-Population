#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int startPopulationSize;
    int endPopulationSize;
    int newBorn;
    int passAway;
    int endYearPopulation;
    int numberOfYears = 1;

    // TODO: Prompt for start size
    do
    {
        startPopulationSize = get_int("What is the initial population size?\n");
        if (startPopulationSize < 9)
        {
            printf("Please enter a different number\n");
        }
    } while (startPopulationSize < 9);

    // TODO: Prompt for end size
    do
    {
        endPopulationSize = get_int("What is the final population size?\n");
        if (endPopulationSize < startPopulationSize)
        {
            printf("Please enter a different number\n");
        }
    } while (endPopulationSize < startPopulationSize);

    // Background formula
    newBorn = startPopulationSize / 3;
    passAway = startPopulationSize / 4;
    endYearPopulation = startPopulationSize + newBorn - passAway;
    //printf("the population at the end of the year is: %i\n", endYearPopulation);

    // TODO: Calculate number of years until we reach threshold

    int totalYears = 1;
    int updatePopulation;

    //if start population and final population are the same, the year growth is 0
    if (startPopulationSize == endPopulationSize)
    {
        totalYears = 0;
    }
    else if (endYearPopulation == endPopulationSize)
    {
        totalYears = 1;
    }
    else
    {
        while (endPopulationSize > endYearPopulation)
        {
            updatePopulation = endYearPopulation;
            newBorn = updatePopulation / 3;
            passAway = updatePopulation / 4;
            endYearPopulation = updatePopulation + newBorn - passAway;
            totalYears++;
            //printf("total years: %i\n", totalYears);
        }
    }

    // TODO: Print number of years
    printf("Years: %i\n", totalYears);
}