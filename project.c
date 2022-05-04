#include <stdio.h>
#include <string.h>

#define n_round 10

//Global Variable
int Location = 0;
int Time=0;

// BUS RED COLOR = 0;
// BUS BLUE COLOR = 1;
// BP = Bus Stop [0-5];, 0 = Bus Stop 1
int BP[6][2]={ 
// R B   -> 0 = Bus No Stop, 1 = Bus Stop there
  {1,0}, // Bus Stop 1  
  {0,1}, // Bus Stop 2  
  {0,1}, // Bus Stop 3  
  {1,0}, // Bus Stop 4  
  {1,1}, // Bus Stop 5  
  {1,1}, // Bus Stop 6  
};

int RED[n_round]={ // RED BUS TIME
    1000, // -> 10:00 O'Clock 
    1100,
    1200,
    1300,
    1400,
    1500,
    1600,
    1700,
    1800,
    1900
};

int BLUE[n_round]={ // BLUE BUS TIME
    1030, // -> 10:30 O'Clock 
    1130,
    1330,
    1330,
    1430,
    1530,
    1630,
    1730,
    1830,
    1930
};

void cal_time(int redbus,int bluebus){
    if(redbus==1){
        printf("\nTime \n");
        printf("=== Next Red Bus === \n");
        for(int i=0; i<n_round; i++){
            if(RED[i] >= Time){
                printf("%d O'Clock\n",RED[i]);
            }
        }
    }
    if(bluebus==1){
        printf("\nTime \n");
        printf("=== Next Blue Bus === \n");
        for(int i=0; i<n_round; i++){
            if(BLUE[i] >= Time){
                printf("%d O'Clock\n",BLUE[i]);
            }
        }
    }
}

void cal_bp(){
    int redbus = BP[Location-1][0];
    int bluebus = BP[Location-1][1];
    
    if(redbus==1 && bluebus==1){
        printf("Red Bus & Blue Bus Coming Soon... \n");
        cal_time(redbus,bluebus);
    }
    else if(redbus==1 && bluebus==0){
        printf("Only Red Bus Coming Soon... \n");
        cal_time(redbus,bluebus);
    }
    else if(redbus==0 && bluebus==1){
        printf("Only Blue Bus Coming Soon... \n");
        cal_time(redbus,bluebus);
    }
    else{
        printf("No Bus Coming T T \n");
    }
}

void Display(){
    printf("\nI'm at Bus Stop %d \n",Location);
    printf("Time at %d o'clock \n\n",Time);
}

int main()
{
    printf("Where are you ? Bus Stop (1-6) : ");
    scanf("%d",&Location);
    printf("What time is it ? ex.16:30 o'clock -> (1630) : ");
    scanf("%d",&Time);
    Display();
    cal_bp();

    return 0;
}