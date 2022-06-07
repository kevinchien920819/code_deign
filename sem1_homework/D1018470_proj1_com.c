
// Randomly generate numbers between 1 and 1000 for user to guess.
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randint(int);
void correct(void);
void guessGame(void); // function prototype
int isCorrect(int, int); // function prototype
int count;
int main(void)
{
   // srand( time( 0 ) ); // seed random number generator
   guessGame();
} // end main

// guessGame generates numbers between 1 and 1000
// and checks user's guess
void guessGame(void)
{
   int answer; // randomly generated number
   unsigned int guess = 0; // user's guess
   int response; // 1 or 2 response to continue game
   int callback;
   int counter = 1;
   int min = 1;
   int max = 80;
   int temp;
   // loop until user types 2 to quit game
   do {
      srand(time(NULL));
      counter = 0;
      // generate random number between 1 and 1000
      // 1 is shift, 1000 is scaling factor
      answer = 1 + rand() % 1000;
      printf("answer is:%d\n",answer);

      // prompt for guess
      puts("I have a number between 1 and 1000.\n" 
           "Can you guess my number?\n" 
           "Please type your first guess.\n");
      guess =500;
      temp = 500;
      printf("%d\n",guess);
      callback = isCorrect(guess,answer);
      // loop until correct number
      while (isCorrect(guess, answer)!=1) {
         if(isCorrect(guess,answer)==2){
            printf( "%s", "Too low. Try again.\n? " );
            guess = (guess + randint(max - min + 1)%100) % 1000;
            temp = guess;
            printf("%d\n",guess);  
         }
         else if(isCorrect(guess,answer)==3){
            printf( "%s", "Too high. Try again.\n? " );
            guess = (guess -randint(max - min + 1)%100) % 1000;
            temp = guess;
            printf("%d\n",guess);
         }
            
         isCorrect(guess,answer);
         counter++;
      }
    

      // prompt for another game
      printf("the computer compute %d times.",counter);
      puts("\nExcellent! You guessed the number!\n"
         "Would you like to play again?");
      correct();
      printf("%s", "Please type ( 1=yes, 2=no )? ");
      scanf("%d", &response);

      puts("");
   } while (response == 1);
} // end function guessGame

// isCorrect returns true if g equals a
// if g does not equal a, displays hint
int isCorrect(int g, int a)
{
   // guess is correct
   if (g == a)
      return 1;

   // guess is incorrect; display hint
   if (g < a){
         return 2;
   }
     
   else{
      
       return 3;
   }
} // end function isCorrect

int randint(int n) {
  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    /* 計算可以被整除的長度 */
    long end = RAND_MAX / n;
    assert (end > 0L);
    end *= n;

    /* 將尾端會造成偏差的幾個亂數去除，
       若產生的亂數超過 limit，則將其捨去 */
    int r;
    while ((r = rand()) >= end);

    return r % n;
  }
}
void correct(void){
char pig[][60]={
    "                        /  `.             ",
    "                      ,'     `.           ",
    "       /`.________   (         :          ",
    "       \\          `. _\\_______  )       ",
    "        \\ `.----._  `.        \"`-.        ",
    "         )  \\     \\   `       ,\"__\\       ",
    "         \\   \\     )    ,--    (/o\\\\     ",
    "     (  _ `.  `---'     ,--.    \\ _)).      ",
    "      `(-',-`----'     ( (O \\    `--,\"`-.   ",
    "        `/              \\ \\__)    ,'   O )  ",
    "        /                `--'     (  O  ,'  ",
    "       (                           `--,'    ",
    "        \\                    `==  _.-'      ",
    "         \\              .____.-;-'          ",
    "   -hrr-  ) `._               /             ",
    "         (    |`-._\\    | ,' /              ",
    "          `.__|__/ \"\\   |'  /               ",
    "                     `._|_,'                "

};
      int i ;
      for(i=0;i<=19;i++)
        printf("%s\n",pig[i]);
}