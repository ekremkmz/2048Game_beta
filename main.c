#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*Bilinen hatalar:
*Ard arda "r" ye basýnca oynanan hamle sayýsýnýn sürekli azalmasý
*/
int main(){
    printf("~WELLCOME TO 2048GAME BETA~\n\nYou can play with\n\tW=UP\t\t\tR=UNDO\nA=LEFT\tS=DOWN\tD=RIGHT\t\tX=RESET\n\t\t\t\tE=EXIT\n");
    printf("Lutfen bir tusa basin");
    getch();
    system("cls");
    int null=16,x,y,m,t,z1=0,error=0,hscore=0,score=0,counter,a,n,ctrl,z=0,max=2,panel[4][4]={{0,0}},r=0,rpanel[4][4],win=2048;
    char play;
    while(max!=win&&null!=0){
        //High score atayan blok
        if(hscore<score){
            hscore=score;
        }
        //Rastgele bir yere 2 veya 4 atayan blok
        if(error==0&&r==0){
            srand(time(NULL));
            ctrl=((rand()%null)+1);
            a=0;
            r=0;
            for(m=0;m<4;m++){
                for(n=0;n<4;n++){
                    if(panel[m][n]==0){
                        a++;
                    }
                    if(a==ctrl){
                        if(((rand()%10)+1)<=8){
                            panel[m][n]=2;
                        }
                        else{
                            panel[m][n]=4;
                        }
                        x=m;
                        y=n;
                        ctrl=17;
                    }
                }           
            } 
        } 
        //Paneli çizen ve oyuncudan hamle isteyen blok
        printf("\nScore:%d HighScore:%d Move:%d\n", score,hscore,z);
        printf("_______________\n");
        for(m=0;m<4;m++){
            for(n=0;n<4;n++){
                printf("|");
                if(m==x&&n==y&&r==0){
                    printf("*");
                }
                printf("%d|", panel[m][n]);           
            }
        printf("\n_______________\n");
        }
        printf("\n\nYou can play with\n\tW=UP\t\t\tR=UNDO\nA=LEFT\tS=DOWN\tD=RIGHT\t\tX=RESET\n\t\t\t\tE=EXIT\n");
        //Hatalý girdi icin uyari veren blok
        if(error==1){
            printf("Error. Lets try again\n");
            error=0;
        }
        if(r==1){
            r=0;
        }
        play=getch();
        system("cls");
        //Sola hamleyi oynayan blok
        if(play=='a'||play=='A'){
            z1=1;
            z++;
            //Bi onceki hamleyi hafiza tutan blok
            for(n=0;n<4;n++){
                for(m=0;m<4;m++){
                    rpanel[n][m]=panel[n][m];
                }
            }
            for(m=0;m<4;m++){
                counter=0;
                n=0;
                while(n<4){
                    if(panel[m][n]!=0){
                        panel[m][counter]=panel[m][n];
                        counter++;
                        if(n!=counter-1){
                            panel[m][n]=0;
                        }
                    }
                    n++;
                }
            }
            for(m=0;m<4;m++){
                for(n=0;n<3;n++){
                    if(panel[m][n]==panel[m][n+1]){
                        t=n;
                        while(n<4){
                            panel[m][n]=panel[m][n+1];
                            n++;
                        }
                        score+=panel[m][t];
                        panel[m][t]=2*panel[m][t];
                        panel[m][3]=0;
                        n=t;
                    }
                }
            }       
        }
        //Saga hamleyi oynayan blok
        else if(play=='d'||play=='D'){
            z1=1;
            z++;
            //Bi onceki hamleyi hafiza tutan blok
            for(n=0;n<4;n++){
                for(m=0;m<4;m++){
                    rpanel[n][m]=panel[n][m];
                }
            }
            for(m=0;m<4;m++){
                counter=0;
                n=0;
                while(n<4){
                    if(panel[m][3-n]!=0){
                        panel[m][3-counter]=panel[m][3-n];
                        counter++;
                        if(n!=counter-1){
                            panel[m][3-n]=0;
                        }
                    }
                    n++;
                }
            }
            for(m=0;m<4;m++){
                for(n=0;n<3;n++){
                    if(panel[m][3-n]==panel[m][2-n]){
                        t=3-n;
                        while(n<4){
                            panel[m][3-n]=panel[m][2-n];
                            n++;
                        }
                        score+=panel[m][t];
                        panel[m][t]=2*panel[m][t];
                        panel[m][0]=0;
                        n=3-t;
                    }
                }
            }      
        }
       //Yukari hamleyi oynayan blok
        else if(play=='w'||play=='W'){
            z1=1;
            z++;
            //Bi onceki hamleyi hafiza tutan blok
            for(n=0;n<4;n++){
                for(m=0;m<4;m++){
                    rpanel[n][m]=panel[n][m];
                }
            }
            for(m=0;m<4;m++){
                counter=0;
                n=0;
                while(n<4){
                    if(panel[n][m]!=0){
                        panel[counter][m]=panel[n][m];
                        counter++;
                        if(n!=counter-1){
                            panel[n][m]=0;
                        }
                    }
                    n++;
                }
            }
            for(m=0;m<4;m++){
                for(n=0;n<3;n++){
                    if(panel[n][m]==panel[n+1][m]){
                        t=n;
                        while(n<4){
                            panel[n][m]=panel[n+1][m];
                            n++;
                        }
                        score+=panel[t][m];
                        panel[t][m]=2*panel[t][m];
                        panel[3][m]=0;
                        n=t;
                    }
                }
            }  
        }
        //Asagi hamleyi oynayan blok
        else if(play=='s'||play=='S'){
            z1=1;
            z++;
            //Bi onceki hamleyi hafiza tutan blok
            for(n=0;n<4;n++){
                for(m=0;m<4;m++){
                    rpanel[n][m]=panel[n][m];
                }
            }
            for(m=0;m<4;m++){
                counter=0;
                n=0;
                while(n<4){
                    if(panel[3-n][m]!=0){
                        panel[3-counter][m]=panel[3-n][m];
                        counter++;
                        if(n!=counter-1){
                            panel[3-n][m]=0;
                        }
                    }
                    n++;
                }
            }
            for(m=0;m<4;m++){
                for(n=0;n<3;n++){
                    if(panel[3-n][m]==panel[2-n][m]){
                        t=3-n;
                        while(n<4){
                            panel[3-n][m]=panel[2-n][m];
                            n++;
                        }
                        score+=panel[t][m];
                        panel[t][m]=2*panel[t][m];
                        panel[0][m]=0;
                        n=3-t;
                    }
                }
            }  
        }
        //Bi onceki hamleye donmeyi saglayan blok
        else if(z1!=0&&(play=='r'||play=='R')){
            z--;
            r=1;
            for(n=0;n<4;n++){
                for(m=0;m<4;m++){
                    panel[n][m]=rpanel[n][m];
                }
            }
        }
        //Oyunu sifirlayan blok
        else if(play=='x'||play=='X'){
            z=0;
            z1=0;
            score=0;
            for(n=0;n<4;n++){
                for(m=0;m<4;m++){
                    panel[n][m]=0;
                }
            }
        }
        //Oyunu durduran blok
        else if(play=='e'||play=='E'){
            break;
        }
        //Hatali girdiyi algilayan blok
        else{
            error=1;
        }
        //Maksimum sayiyi bulan ve boþ kutusayisini tespit eden blok.
        null=0;
        for(m=0;m<4;m++){
            for(n=0;n<4;n++){
                if(panel[m][n]==0){
                    null++;
                } 
                if(panel[m][n]>max){
                    max=panel[m][n];
                }   
            }
        } 
		//Oyunun sonucunu yazdiran blok
  	    if (max==win){
  	    	ctrl=0;
			while(ctrl==0){
				printf("\nCONGRATULATIONS YOU WIN %d\nDO YOU WANT TO CONTINUE?(Y/N)", win);
				play=getch();
				system("cls");
				if(play=='y'||play=='Y'||play=='n'||play=='N'){
					ctrl=1;
				}
			}
			if(play=='y'||play=='Y'){
    	    	win=win*2;
			}
    	} 
	}
	//High score atayan blok
        if(hscore<score){
            hscore=score;
        }
    printf("\nGAME OVER\n\nScore:%d HighScore:%d\n", score,hscore);
}
