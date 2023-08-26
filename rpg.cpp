#include <iostream>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string>
using namespace std;
int board[100][100];
int M[100][100];
int playerx=1,playery=1;
int Level = 1,Exp = 0;
int PHP,PMHP;
int Mx=10,My=10;
struct Item_stat{
    string Item_name;
    int atk;
    int def;
};
Item_stat inventory[10] = {};

string monster[1][5]{{"Green Slime","Blue Slime","Bee","Snake","Angry Bird"}};
void incounter(){
    system("cls");
    printf("incounter!\n");
    int Mindex = rand()%5;
    int MLV = rand()%10-5+Level;
    if(MLV < 1)
        MLV = 1;
    int MHP = MLV * 10;
    int MMHP = MHP;
    int c;
    while(1){
        printf("%s LV %d\n",monster[0][Mindex].c_str(),MLV);
        printf("HP %d/%d\n",MHP,MMHP);
        printf("\n\n%s LV %d\n","player",Level);
        printf("HP %d/%d\n",PHP,PMHP);
        printf("1.atteck\n");
        printf("2.run away\n");
        scanf("%d",&c);
        if(c==2){
            return;}
        else if(c==1){
            MHP = MHP - (rand()%Level+1);
        }
        if(MHP <= 0){
            printf("Player win!\n");
            int expp = (rand()%(MLV+1)+1)*10;
            printf("Get Exp +%d!\n",expp);
            getch();
            Exp = Exp + expp;
            return;
        }
        system("cls");
    }
}

void getitem(){
    printf("take whose exp dot(exp +10)!\n");
    Exp = Exp + 10;
}
int main()
{
    srand((unsigned)time(NULL));
    for(int i = 1; i <= 10; i++){
        for(int n = 1; n <= 10; n++){
            M[i][n] = 'W';
            board[i][n] = 'W';
            board[playery][playerx] = '*';
            printf("%c ",M[i][n]);
        }
        printf("\n");
    }

    PMHP = Level*10;
    PHP = Level*10;
    while(1){
        if(_kbhit()){
            board[playery][playerx] = M[playerx][playery];
            char c = getch();
            if(c == 'w'||c == 'a'||c == 's'||c == 'd'){
                if(rand()%20+1 == 1){
                    incounter();
                }
                system("cls");
                if(c == 'd')
                    playerx++;
                else if(c == 'a')
                    playerx--;
                else if(c == 'w')
                    playery--;
                else if(c == 's')
                    playery++;
                if(playery < 1)
                    playery = 1;
                if(playery > 10)
                    playery = 10;
                if(playerx < 1)
                    playerx = 1;
                if(playerx > 10)
                    playerx = 10;
                board[playery][playerx] = '*';
                for(int i = 1; i <= 10; i++){
                    for(int n = 1; n <= 10; n++){
                        printf("%c ",board[i][n]);
                    }
                    printf("\n");
                }
                printf("LV %d EXP %d/%.2lf\n",Level,Exp,Level*(Level*0.5)*10);
                printf("HP %d/%d\n",PHP,PMHP);
                printf("     [%3s]     \n","");
                printf("[%3s][%3s][%3s]\n","","","");
                printf("     [%3s]     \n","");
                if(rand()%20+1 <3){
                    getitem();
                }
            }
            while((Level*(Level*0.5)*10) <= Exp){
                Exp = Exp - (Level*(Level*0.5)*10);
                Level++;
                PMHP = Level*10;
                PHP = Level*10;
                printf("LV UP!\n");
            }
        }

    }
}
