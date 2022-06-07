// cp3_hw1_hint
// Card shuffling and dealing program using structures
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
#define HANDS 5 //增加手牌數目 

// card structure definition
struct card {
   const char *face; // define pointer face
   const char *suit; // define pointer suit
   int face_num;
   int suit_num;
}; // end struct card

typedef struct card Card; // new type name for struct card

// prototypes
void fillDeck( Card * const wDeck, const char * wFace[], const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck ,Card * const hand);

void onePair( const Card * const hand , const char * wFace[]); //對子
void twoPair( const Card * const hand , const char * wFace[]); //雙對子
void threeOfKind( const Card * const hand ,const char * wFace[]); //三條 
void fourOfKind( const Card * const hand,const char * wFace[] ); //四梅 


int main( void )
{ 
   Card deck[ CARDS ]; // define array of Cards
   Card hand[ HANDS ]; 

   // initialize array of pointers
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten",
      "Jack", "Queen", "King"};

   // initialize array of pointers
   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

   srand( time( NULL ) ); // randomize

   fillDeck( deck, face, suit ); // load the deck with Cards
   shuffle( deck ); // put Cards in random order
   deal( deck,hand ); // deal all 52 Cards
   onePair(hand,face);//check their is a pair
   twoPair(hand,face);//check there has two pair
   threeOfKind(hand,face);// check there has threekind
   fourOfKind(hand,face);//check there has fourkind
} // end main

// place strings into Card structures
void fillDeck( Card * const wDeck, const char * wFace[], 
   const char * wSuit[] )
{ 
   size_t i; // counter
 
   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) { 
      wDeck[ i ].face = wFace[ i % FACES ];
      wDeck[ i ].suit = wSuit[ i / FACES ];
      wDeck[ i ].face_num = i % FACES;
      wDeck[ i ].suit_num = i / FACES;

   } // end for
} // end function fillDeck

// shuffle cards
void shuffle( Card * const wDeck )
{ 
   size_t i; // counter
   size_t j; // variable to hold random value between 0 - 51
   Card temp; // define temporary structure for swapping Cards

   // loop through wDeck randomly swapping Cards
   for ( i = 0; i < CARDS; ++i ) { 
      j = rand() % CARDS;
      temp = wDeck[ i ];
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
   } // end for
} // end function shuffle

// deal cards
void deal( const Card * const wDeck , Card * const hand )
{ 
   size_t i; // counter

   // loop through wDeck
   for ( i = 0; i < HANDS; ++i ) {
      printf( "%5s of %-8s%s", wDeck[ i ].face, wDeck[ i ].suit,
         ( i + 1 ) % 5 ? "  " : "\n" );
	  hand[i]=wDeck[i];
   } // end for
} // end function deal

// determines if there are any pairs in the hand
void onePair( const Card * const hand, const char * wFace[] )
{
   // counter that records how many cards of each rank are in the hand
   unsigned int counter[ FACES ] = { 0 };

   size_t r, p; // loop counters

   // record how many cards of each rank are in the hand
   for ( r = 0; r < HANDS ; ++r ){
   		++counter[ hand[r].face_num ];
   }

   // print result if there is a pair
   for ( p = 0; p < FACES; ++p )
      if (counter[p] == 2) //couter = 2 then there was a pair
        printf( "The hand contains a pair of %ss.\n", wFace[ p ] );
} // end function pair

void twoPair(const Card* const hand,const char * wFace[]){
   // counter that records how many cards of each rank are in the hand
   unsigned int counter[ FACES ] = { 0 };

   size_t r, p; // loop counters

   // record how many cards of each rank are in the hand
   for ( r = 0; r < HANDS ; ++r ){
   		++counter[ hand[r].face_num ];
   }
   int flag[2] = {0};//set a flag to store the pair number
   int k = 0;// flag counter
   // print result if there is two pair
   for ( p = 0; p < FACES; ++p )
      if (counter[p] == 2){//means a pair
         flag[k] = p;// memory a pair
         k++;//next
         }
   if(k == 2)//k = 2 means there has two pair 
      printf( "The hand contains two pair of %ss and %ss.\n", wFace[flag[0]],wFace[flag[1]]);
}
void threeOfKind(const Card * const hand,const char * wFace[]){
   // counter that records how many cards of each rank are in the hand
   unsigned int counter[ FACES ] = { 0 };

   size_t r, p; // loop counters

   // record how many cards of each rank are in the hand
   for ( r = 0; r < HANDS ; ++r ){
   		++counter[ hand[r].face_num ];
   }

   // print result if there has three kind
   for ( p = 0; p < FACES; ++p )
      if (counter[p] == 3) //check their has three same number card or not
        printf( "The hand contains threeofkind of %ss.\n", wFace[ p ] );//if true then there has threekind
}
void fourOfKind(const Card * const hand,const char * wFace[]){
   // counter that records how many cards of each rank are in the hand
   unsigned int counter[ FACES ] = { 0 };

   size_t r, p; // loop counters

   // record how many cards of each rank are in the hand
   for ( r = 0; r < HANDS ; ++r ){
   		++counter[ hand[r].face_num ];
   }

   // print result if there has fourkind
   for ( p = 0; p < FACES; ++p )
      if (counter[p] == 4)//check their has four same number cards or not
        printf( "The hand contains fourofkind of %ss.\n", wFace[ p ] );//if true then there has fourkind
}
