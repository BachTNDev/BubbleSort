// Bach Nguyen
// CECS 325-02
// Prog 3 - Bubblesort
// Due Date: 03/12/2024
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>

using namespace std;

void bubble(int A[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (A[j] > A[j + 1]) 
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        cerr << "Usage: " << argv[0] << " input_file output_file\n";
        return EXIT_FAILURE;
    }

    ifstream infile(argv[1]);
    if (!infile) 
    {
        cerr << "Error: Unable to open input file.\n";
        return EXIT_FAILURE;
    }

    ofstream outfile(argv[2]);
    if (!outfile) 
    {
        cerr << "Error: Unable to open output file.\n";
        return EXIT_FAILURE;
    }

    const int MAX_SIZE = 1000000;
    int numbers[MAX_SIZE];
    int count = 0;

    int num;
    while (infile >> num) 
    {
        numbers[count++] = num;
    }

    infile.close();

    bubble(numbers, count);

    for (int i = 0; i < count; ++i) 
    {
        outfile << numbers[i] << endl;
    }

    outfile.close();

    return 0;
}
