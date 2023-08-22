#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;


// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }


    for (int i = 0; i < candidate_count; i++) //establece el nombre y asigna 0 votos a cada votante
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: "); //pregunta por cuantas personas votaran

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");   //cada votante vota por su eleccion

        // Check for invalid vote

        if (!vote(name))    //si el nombre del votante no se encuentra en la funcion de vote
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (strcmp(candidates[c].name, name) == 0)
        {
            candidates[c].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int max_vote = 0;

    for (int i=0; i < candidate_count ; i++) //Obtiene el num de votos maximo
    {
        if (candidates[i].votes > max_vote)
        {
            max_vote = candidates[i].votes;
        }
    }

    for (int i=0; i < candidate_count ; i++) //Los candidatos que coinciden con el voto máximo son impresos
    {
        if (candidates[i].votes == max_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}