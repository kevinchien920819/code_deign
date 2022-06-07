#include<stdio.h>
#include<windows.h> 
#include<conio.h> 
#include<time.h>
#define canvas 50
void init_game(){
	printf("		DINO GAME		\n");
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
    "                     `._|_,'                "};

    for(int i=0;i<=17;i++)
        printf("%s\n",pig[i]);
	
    printf("\n\n");
	
    printf("press enter to start!!!");
	
    getchar();
}

// void startgame(){
	


// }

void display(char floor[],int lowerlimit,int upperlimit){ //print the map
    int i;
	for(i = lowerlimit;i < upperlimit;i++){
        printf("%c",floor[i]);
    }
}


void insertBarrier(char *floor,int n){//make some barrier
    int r=rand()%n;//random num
    floor[canvas-r]='X';//insert x means barrier
}


void shiftLeft(char *floor)//move the map left 
{   
    for(int i = 0;i<canvas-1;i++)
    {
        floor[i] = floor[i+1];
    }
    floor[canvas-1] = '_';
}

int isDead(int curfloor,int playerPos, char floor1[]){
    if(curfloor == 1 && playerPos == 6 && floor1[playerPos] == 'X')//cur_floor and get x means dead then return 1(true)
        return 1;
    return 0;//else return 0 to continue
}
int main(){
    init_game();//start game
    int score = 0;
    int playerposition = 6;// the player stand
    int current_floor = 1;
    int sleeptime = 500;//refresh time 500 ms
	char floor1[canvas],floor2[canvas];

    for(int i=0;i<canvas;i++){
        floor1[i]='_';
        floor2[i]=' ';
    }
    
    floor1[canvas-1] = 'X';
    
	while(1){
	int runtime = 0;

    //check the keyboard hit space and current floor
	if(kbhit()){
        //if get the space and the floor is 1
		if(getch() == 32 && current_floor == 1){
			current_floor = 2;//change the dino floor
			runtime = 2;//give 2 sec for jump
		}
	}

	if(runtime > 0)//time > 0 dino must on floor 2
		runtime --;

	if(runtime == 0)//time = 0 dino back to floor 1
		current_floor = 1;

	if(score % 20 == 0)//make some barrier frequentlly
		insertBarrier(floor1,15);
	
	if(current_floor == 1){	

	printf("\n\n\n\t");//排版
    display(floor2,0,canvas);//sky
    printf("\n\t");//排版 

    display(floor1,0,playerposition);//floor before dino 
    printf("0");//dino 
    display(floor1,playerposition,canvas-1);//floor after dino
    printf("\n\n");

	} 
	else if (current_floor == 2){
	printf("\n\n\n\t");
    display(floor2,0,playerposition);//sky before dino
	printf("0");//dino
	display(floor2,playerposition,canvas);//sky after dino 

	printf("\n\t");

	display(floor1,0,canvas);//floor

    printf("\n\n");
	}

	printf("score: %d",score);//print the score right now
	score++;//plus the score

	Sleep(sleeptime);//sleep for a wail
	system("cls");//refresh system

    //pending whether dino dead or not
	if(isDead(current_floor,playerposition, floor1) == TRUE){
        break;
    }
    shiftLeft(floor1);//move the map
    }
    printf("you are dead!\n");//if dead tell the player
	return 0;
}