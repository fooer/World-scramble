//Word Jumble
// The classic word jumble game where the player can ask for hints

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	system("color 0A");
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
	{"wall", "Do you feel you're banging your head against something?"},
	{"glasses", "These might help you see the answers."},
	{"labored", "Going slowly, is it?"},
	{"persistent", "Keep at it"},
	{"jumble", "It's what the game is all about"}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];  //word to guess
	string theHint = WORDS[choice][HINT]; //hint for word
    string jumble = theWord; //jumbled version of word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
		}

	cout << "\t\t\tWelcome to Word Jumble";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "the jumble is: " << jumble << endl;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess !="quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Sorry, that's not it.";
		}
		cout << "\n\nyour guess: ";
		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "\nThat's it! you guessed it GG";
	}
	cout << "\nty for playing\n";
	return 0;
}
