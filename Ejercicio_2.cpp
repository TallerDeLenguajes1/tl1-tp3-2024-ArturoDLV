//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

//Constants
#define WIDTH 12 //Months
#define HEIGHT 5 //Years

//Structs
typedef struct matrix_value
{
    long int value;
    unsigned int month;
    unsigned int year;
}matrix_value;

//Function Statements
void matrix_fill(long int matrix[WIDTH][HEIGHT]);
void matrix_show(long int matrix[WIDTH][HEIGHT]);
void matrix_yearlyAvg(long int matrix[WIDTH][HEIGHT]);
void matrix_getExtremes(long int matrix[WIDTH][HEIGHT]);

//Main Function
int main()
{
    long int matrix[WIDTH][HEIGHT];

    matrix_fill(matrix);        // a
    matrix_show(matrix);        // b
    matrix_yearlyAvg(matrix);   // c
    matrix_getExtremes(matrix); // d

    return 0;
}


//Functions

//Fill the given matrix with random numbers
void matrix_fill(long int matrix[WIDTH][HEIGHT])
{
    srand(time(0)); //Set seed for randomness to match device time

    for (unsigned int i = 0; i < HEIGHT; i++)
    {
        for (unsigned int j = 0; j < WIDTH; j++)
        {
            matrix[j][i] = ((rand() % 40000) + 10000);
        }
    }
}

//Show in the console each value of the given matrix
void matrix_show(long int matrix[WIDTH][HEIGHT])
{
    printf("\n");
    printf("\nTabla de ganancias. Meses a lo largo, a%cos a lo alto:",164);
    for (unsigned int i = 0; i < HEIGHT; i++)
    {
        printf("\n");
        for (unsigned int j = 0; j < WIDTH; j++)
        {
            printf(" [$%d] ",matrix[j][i]);
        }
    }
}

//Get the yearly average income
void matrix_yearlyAvg(long int matrix[WIDTH][HEIGHT])
{
    printf("\n");
    printf("\nGanancias promedio por a%co:",164);
    for (unsigned int i = 0; i < HEIGHT; i++)
    {
        float average = 0;

        for (unsigned int j = 0; j < WIDTH; j++)
        {
            average += matrix[j][i];
        }

        average /= WIDTH;
        printf("\nGanancia promedio del a%co %d: $%f",164,(i + 1),average);
    }
}

//Show the end points of the matrix (max and min) with its respective month and year
void matrix_getExtremes(long int matrix[WIDTH][HEIGHT])
{
    matrix_value max;
    matrix_value min;
    bool found_max = false;
    bool found_min = false;

    for (unsigned int i = 0; i < HEIGHT; i++)
    {
        for (unsigned int j = 0; j < WIDTH; j++)
        {
            if (found_max == true)
            {
                if (matrix[j][i] > max.value)
                {
                    max.value = matrix[j][i];
                    max.month = j + 1;
                    max.year = i + 1;
                }
            }
            else
            {
                max.value = matrix[j][i];
                max.month = j + 1;
                max.year = i + 1;
                found_max = true;
            }

            if (found_min == true)
            {
                if (matrix[j][i] < min.value)
                {
                    min.value = matrix[j][i];
                    min.month = j + 1;
                    min.year = i + 1;
                }
            }
            else
            {
                min.value = matrix[j][i];
                min.month = j + 1;
                min.year = i + 1;
                found_min = true;
            }
        }
    }

    printf("\n");
    if ((found_max == true) && (found_min == true))
    {
        printf("\nLa ganancia maxima se dio en el mes %d del a%co %d, y fue de $%d",max.month,164,max.year,max.value);
        printf("\nLa ganancia minima se dio en el mes %d del a%co %d, y fue de $%d",min.month,164,min.year,min.value);
    }
    else
    {
        printf("\nHubo un error al intentar encontrar la maxima y la minima ganancia.");
    }
}