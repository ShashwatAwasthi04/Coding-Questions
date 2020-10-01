  #include <iostream>
    #include <cstdlib>
    #include <ctime>

    using namespace std;

    int main()
    {
        srand(static_cast <unsigned int> (time(0)));

        int compGuess = rand() % 100 +1; //Generates number between 1 - 100
        int highestNumber = 100;
        int lowestNumber = 1;
        char ready;
        char highLowSuccess;
        bool success;
        int tries = 0;


        cout << "Please pick a number between 1 - 100. I will guess your number. Don't tell me what it is!\n\n";


        do
        {
            cout << "Are you ready? (y/n)\n\n";
            cin >> ready;

            if (ready == 'y')
            {
                do
                {
                    cout << "Is your number " << compGuess << "?\n\n";
                    cout << "High, Low or Success?";
                    ++tries;
                    cin >> highLowSuccess; //User input telling the computer whether its too high, too low, or a success

                    if (highLowSuccess == 'h') //Executes code if number guessed was too high.
                    {

                        highestNumber = compGuess - 1; //Stores variable indicating the highest possible number based on user input
                        compGuess = rand() % highestNumber +1; //Generates a new random number between 1 and the new highest possible number
                        success = false;
                    }

                    else if (highLowSuccess == 'l') //Executes code if number guessed was too low.
                    {
                        lowestNumber = compGuess + 1;//Stores variable indicating the lowest possible number based on user input
                        compGuess = (rand() % highestNumber - lowestNumber + 1) + lowestNumber; // <---- Not producing the desired result
                        success = false;
                    }

                    else if (highLowSuccess == 's') //Executes code if the computer's guess was correct.
                    {
                        cout << "I guessed your number! It only took me " << tries << " tries!";
                        success = true;
                    }


                } while (success != true);
            }


            else
            {
             continue;
            }

       } while (ready != 'y');



    return 0;

    }
