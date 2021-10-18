// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
int wordscount = 0;
node *table[N];


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word); // хешируем словово что бы получить хеш значение
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0) // сравнием слова без учёта регистра
        {
            return true; // если находим слово
        }
        // если не находим слово
        cursor = cursor->next;
    }
    return false; 
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
   FILE *file = fopen(dictionary, "r");
   if (file == NULL)
   {
       return false;
   }
   //
   char word[LENGTH + 1];
   while(fscanf(file, "%s", word) != EOF) // бесконечный цикл, который считывает слова до конца списка
   {
       // cканирует словарь слово за словом (заполняя хеш-таблицу узлами, содержащими слова, найденные в словаре)
       node *n = malloc(sizeof(node));
       // проверяет успешность выполнения malloc, в противном случае возвращает false
       if (n == NULL)
       {
           return false;
       }
       //
      n->next = NULL;
      strcpy(n->word, word); // копируем слово в массив символов, которое является полем слова этого узла
      int index = hash(word); // хешировать слово в буфере, чтобы получить индекс массива
      // если список пустой
      if(table[index] == NULL) 
      {
          table[index] = n; // 75-80 строки вставляем слово в связанный список
                            // добавляем наш новый узел в начало связаного списка
      }
      else
      {
          n->next = table[index]; 
          table[index] = n; 
      }
     wordscount++; // повтоярем процес для каждого слова в словаре и отслеживаем количество слов
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordscount; // в лоаде мы отследили количество слов и возвращаем значение в своём размере
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while(cursor != NULL)
        {
            node *head = cursor;
            cursor = cursor->next;
            free(head);
        }
    }
    return true;
}
