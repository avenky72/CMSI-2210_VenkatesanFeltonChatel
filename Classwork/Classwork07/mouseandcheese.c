#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define  TRUE        1
#define  FALSE       0
#define  MAX_GUESSES 10
#define  WORD_COUNT  16

/*
 * helper function that displays the game instructions and
 *    waits for the user to press enter to continue
 */
void instructions() {
   printf( "\n\n   MOUSE AND CHEESE GAME\n\n   =====================\n\n" );
   printf( "  The purpose of the game is to keep the mouse from getting the cheese.\n" );
   printf( "  You must guess the word indicated by the blanks below.\n" );
   printf( "  You have 10 guesses.  If you guess right, the mouse sits still.\n" );
   printf( "  If you guess a letter that is NOT in the word, the mouse moves one step.\n" );
   printf( "  If the mouse reaches the cheese, you lose, if you guess the word first, you WIN!\n" );
   printf( "\n\n     Press the 'enter' key to begin:" );
   fflush( stdin );
   getchar();
}

/*
 * helper function to get the user input letter
 *    returns the letter in uppercase
 */
char getLetterInUppercase() {
   char letter[2];
   printf( " Enter your letter: " );
   fflush( stdout );
   scanf( "%s", letter );
   for( int i = 0; letter[i] != '\0'; i++ ) {
      if(letter[i] >= 'a' && letter[i] <= 'z') {
         letter[i] = letter[i] - 32;
      }
   }
   return letter[0];
}

/*
 * main program is really just a loop that runs while both the
 *    "allGuessed" flag is false and the number of guesses is
 *    less than ten.
 */
int main() {

   char guess;
   char words[WORD_COUNT][15]  = { "NANDGATE", "XORGATE", "CPU", "MEMORY",
                                   "MOTHERBOARD", "CHEESE", "MOUSE", "HDMIPORT",
                                   "HARDDRIVE", "RAM", "COOLINGFAN", "FLOATINGPOINT",
                                   "COMPILER", "LINKLOADER", "LINUX", "WINDOWS" };

   int found      = FALSE;
   int allGuessed = FALSE;
   int guesses    = 0;
   int index      = 0;
   int k          = 0;

   srand( time(0) );
   index = (rand() % WORD_COUNT);

  /*
   * Set the mask array - mask[i] is true if the
   * character s[i] has been guessed.  The mask
   * must be allocated, and initialized to all false
   */
   int N = strlen( words[index] );
   int mask[N];
   for( int i = 0; i < N; ++i ) {
      mask[i] = FALSE;
   }

   instructions();

  // Loop over each round of guessing
   while( !allGuessed && (guesses < MAX_GUESSES) ) {
     // Print word with underscores for unguessed letters
      printf( "\n  The word is now: " );
      for( int j = 0; j < N; ++j ) {
         if( mask[j] ) {
            printf( "%c ", words[index][j] );
         } else {
            printf( "_ " );
         }
      }
      printf( "    You've used %d of %d guesses...\n", guesses, MAX_GUESSES );

     // Get player's next guess
      guess = getLetterInUppercase();

     // Mark true all mask positions corresponding to guess
      found = FALSE;
      for( k = 0; k < N; ++k ) {
         if( words[index][k] == guess ) {
            mask[k] = TRUE;
            found = TRUE;
         }
      }
      if( !found ) {
         guesses++;
         printf( "\n    Didn't find that letter!\n" );
      }

     // Determine whether the player has won!
      allGuessed = TRUE;
      for( int m = 0; m < N; ++m ) {
         if( !mask[m] ) {
            allGuessed = FALSE;
            break;
         }
      }
   }

  // Print victory message!
   if( guesses == MAX_GUESSES ) {
      printf("\n\n   YOU LOSE! The word is \"%s\".\n", words[index]);
   } else {
      printf("\n\n   Victory! The word is \"%s\".\n", words[index]);
   }

   return 0;
}
