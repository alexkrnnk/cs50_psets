#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Максимальное количество кандидатов
#define MAX 9

// Кандидаты имеют имя и подсчет голосов
typedef struct
{
    string name;
    int votes;
}
candidate;

// Массив кандидатов
candidate candidates[MAX];

// Номер кандидатов
int candidate_count;

// Функциональные прототипы
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Проверить на недопустимое использование
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Заполните массив кандидатов
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Прокрутите всех избирателей
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Проверить на недействительность голоса
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Показать победителя выборов
    print_winner();
}

// Обновить итоги голосов при новом голосовании
bool vote(string name)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Выведите победителя (или победителей) выборов
void print_winner(void)
{
    // TODO
    int highestVotes = 0;
       for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes > highestVotes)
        {
            highestVotes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == highestVotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

