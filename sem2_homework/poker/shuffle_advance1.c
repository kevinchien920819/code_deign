// Fig. 10.3: fig10_03.c
// Card shuffling and dealing program using structures
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// card structure definition                  
struct card {                                 
   const char *face; // define pointer face   
   const char *suit; // define pointer suit   
}; 

typedef struct card Card; // new type name for struct card   

// prototypes
void fillDeck(Card * const wDeck, const char * wFace[], 
   const char * wSuit[]);
void shuffle(Card * const wDeck,int *);
void deal(const Card * const wDeck,int *);

int main(void)
{ 
   Card deck[CARDS]; // define array of Cards
    int index[CARDS] = {0};
   // initialize array of pointers
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten",
      "Jack", "Queen", "King"};

   // initialize array of pointers
   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

   srand(time(NULL)); // randomize

   fillDeck(deck, face, suit); // load the deck with Cards
   shuffle(deck,index); // put Cards in random order
   deal(deck,index); // deal all 52 Cards
} 

// place strings into Card structures
void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[])
{ 
   // loop through wDeck
   for (size_t i = 0; i < CARDS; ++i) { 
      wDeck[i].face = wFace[i % FACES];//0 1 2--12,0 1 2 12,
      wDeck[i].suit = wSuit[i / FACES];//0 0 0 0--,1 1 1 ,
   } 
} 

// shuffle cards
void shuffle( Card * const wDeck,int *index )
{ 
    int  num[CARDS] = {0};//set a new array to compute index
    int flag,k = 0;//set flag to sure the output of randam number has taken or not 
    for(int i = 1;i <=52;i++){
        do{//while the number has been taken make a new random number 
            num[i-1] = rand() % CARDS;//get a random number between 0 to 51
            flag = 0;//set flag = 0 means has not taken
            for(int j = 1; j < i;j++){
                if(num[i-1] == num[j-1]){//check taken or not
                    flag =1;//if true change the flag
                    break;//and break out to make a new num
                }
            }
        }while(flag == 1);
        index[k] = num[i-1];//if not taken then memorize in a index array
        k++;
    }
} // end function shuffle


// deal cards
void deal(const Card * const wDeck,int *index)
{ 
   // loop through wDeck
   for (size_t i = 0; i < CARDS; ++i) {
      printf("%5s of %-8s%s", wDeck[index[i]].face, wDeck[index[i]].suit,
         (i + 1) % 4 ? "  " : "\n");
   } 
}