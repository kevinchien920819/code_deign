#include<stdio.h>
#include<windows.h> 
#include<conio.h> 
#include<time.h>


#define canvas 50
void game();
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
	
    printf("\n\n\tnotice !!!!!\n \t\tchange your input to english mode\n\t\tpress 's'= use armstrong bomb to clear all barrier\n\t\tpress 'esc' = Za_Warudo mode will pause the game\n\t");
    system("pause");
	
    game();
}


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

void insertHp(char *floor,int n){//make some barrier
    int r=rand()%n;//random num
    floor[canvas-r]='+';//insert x means barrier
}

void shiftLeft(char *floor,int armstrong)//move the map left 
{   
    if(armstrong == 1)
        for(int i = 0 ; i < canvas;i++)
            if(floor[i] == 'X')
                floor[i] = '_';
    for(int i = 0;i<canvas-1;i++)
    {
        floor[i] = floor[i+1];
    }
    floor[canvas-1] = '_';
}

int recharge(int score,int charge){
    if(score % 100 == 0 && score != 0)
        charge++;
    return charge;
}

void Za_Warudo(){
    printf("\t\tZa Warudo!!!!!!\n");
    system("pause");
}

int isDead(int curfloor,int playerPos, char *floor){
    if(curfloor == 1 && playerPos == 6 && floor[playerPos] == 'X')//cur_floor and get x means dead then return 1(true)
        return 1;
    return 0;//else return 0 to continue
}

int isHeal(int playerPos , char * floor){
    if(playerPos == 6 && floor[playerPos] == '+')
        return 1;
    return 0;
}
void game(){
    int score = 0;
    int response = 0;
    int playerposition = 6;// the player stand
    int current_floor = 1;
    int sleeptime = 150;//refresh time 500 ms
    char floor1[canvas],floor2[canvas];
    int charge = 1;
    int life = 3;
    for(int i=0;i<canvas;i++){
        floor1[i]='_';
        floor2[i]=' ';
    }

    floor1[canvas-1] = 'X';
    
    while(1){
    int runtime = 0;
    int armstrong = 0;
    charge = recharge(score,charge);
    //check the keyboard hit space and current floor
    if(kbhit()){
        char strget = getch();
        //if get the space and the floor is 1
        if(strget == 32 && current_floor == 1){
            current_floor = 2;//change the dino floor
            runtime = 4;//give 2 sec for jump
        }
        else if(strget == 115||strget == 63){
            if(charge > 0&& current_floor ==1){
                charge--;
                armstrong = 1;
            }
        }
        else if(strget == 27)
            Za_Warudo();
    }

    if(runtime > 0)//time > 0 dino must on floor 2
        runtime --;

    if(runtime == 0)//time = 0 dino back to floor 1
        current_floor = 1;

    if(score % 20 == 0)//make some barrier frequentlly
        insertBarrier(floor1,15);

    if(score % 199 == 4 && score > 100) // make some chance to heal the dino
        insertHp(floor1,15);
    
    if(current_floor == 1 ){	
    printf("\n");//排版
    if(charge > 0)
        printf("\t\tpress s to use armstrong bomb\n");

    printf("\t\tpress esc to use zawarudo!!!\t\t");
    
    printf("\n\n\n\t");
    display(floor2,0,canvas);//sky
    printf("\n\t");//排版
    display(floor1,0,playerposition);//floor before dino 
    printf("0");//dino 
    display(floor1,playerposition,canvas-1);//floor after dino
    printf("\n\n");

    } 


    else if (current_floor == 2){
    printf("\n");
    if(charge > 0)
        printf("\t\tpress s to use armstrong bomb\n");

    printf("\t\tpress esc to use zawarudo!!!\t\t");

    printf("\n\n\n\t");
    display(floor2,0,playerposition);//sky before dino
    printf("0");//dino
    display(floor2,playerposition,canvas);//sky after dino 
    printf("\n\t");
    display(floor1,0,canvas);//floor
    printf("\n\n");
    }
    if(score+1 % 100 == 30){
        printf("\tspeed up !!!\n");
        sleeptime -= 20; 
    }
    printf("\tcharge: %d   ",charge);
    for(int i = 0; i < charge;i++)
        printf("*");
    printf("\n\tscore: %d    \n\tlife: %d",score,life);//print the score right now

    score++;//plus the score
    printf("\n\tStatus:");
    //pending the dino get heal or not
    if(isHeal(playerposition,floor1) == TRUE){
        life++;
        printf("you got heal!!!\n");
    }
    //pending whether dino dead or not
    if(isDead(current_floor,playerposition, floor1) == TRUE){
        life--;
        printf("\tyou got hurt!!!\n");
        if(life <= 0){
        printf("\t    you are dead!\n\tCongratulations !! you got %d point!!!\twant to try again??\n\t1 == restart,0 == quit\n\tresponse:",score);//if dead ask want to try or not
        scanf("%d",&response);
        if(response == 1)//if wana try again then call game function once again
            game();
        else{
            break;
        }
        }
    }
    shiftLeft(floor1,armstrong);//move the map
    Sleep(sleeptime);//sleep for a wail
    system("cls");//refresh system
    }
}

int main(){
    init_game();//start game
    printf("\tsee you next time, bye\n");
    system("pause");
    return 0;
}