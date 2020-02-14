/* Alisha Kunwar 1001668106*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define numberOfDice 5
#define numberOfFacePerDice 6

int RollDice(int dicearray[])
{
    int i ;
	
    srand(time(NULL));
    
    for (i=0; i < numberOfDice; i++)
    {
      int dice = rand() % 6 + 1;
      dicearray[i] = dice;
    }
}


int main(void)
{
    char var;
    int numberOfReRolls;
    int dice=0;
    
    
    while(numberOfReRolls<3)
    {
        
    
      int dicearray[numberOfDice];
      int FullHouse = 0, CSlam = 0, LargeStraight = 0, SmallStraight = 0, ofAKind = 0, TwoPair = 0;
      int HowMany[] = {0, 0, 0, 0, 0, 0};
      int j=0; 
      int k=0;
      int l=0;
    
      RollDice(dicearray);

      for (j = 0; j <numberOfFacePerDice; j++)
      {
          
        for (k = 0; k < 5; k++)
        {
            
          if (dicearray[k] == j + 1)
          {
              
            HowMany[j] = HowMany[j] + 1;
          }
        }
        
      }

      printf("You rolled ");

      for (j = 0; j < numberOfDice; j++)
      {
          
        printf(" %d ", dicearray[j]);
        
      }
      printf("\n");
     
      for( l = 0; l <numberOfFacePerDice; l++)
      {

        if(HowMany[l] == 3)
        {
            
          FullHouse = FullHouse + 3;
        }
      
        if(HowMany[l] == 2)
        {
          FullHouse = FullHouse + 2;
          TwoPair++;
        }
        
        if(HowMany[l] == 5)
        {
          CSlam++;
        }

        if(HowMany[l] == 1)
        {
          LargeStraight++;
        }
        
        else if(HowMany[l] == 0 && LargeStraight > 0 && LargeStraight < 5)
        {
          LargeStraight = 0;
        }
        
        if(HowMany[l] >= 1)
        {
          SmallStraight++;
        }
        
        else if(HowMany[l] == 0 && SmallStraight > 0 && SmallStraight < 4)
        {
          SmallStraight = 0;
        }
        
        if(HowMany[l] == 4)
        {
          ofAKind = 4;
        }
        
        if(HowMany[l] == 3)
        {
          ofAKind = 3;
        }
      }

      if(LargeStraight == 5)
      {
        printf("Large Straight\n");
      }

      else if(SmallStraight >= 4)
      {
        printf("Small Straight\n");
      }

      else if(FullHouse == 5)
      {
        printf("Full House\n");
      }
      
      else if (CSlam == 1)
      {
        printf("CSlam");
      }
      
      else if(ofAKind == 4)
      {
        printf("Four of a kind\n");
      }
      
      else if(ofAKind == 3)
      {
        printf("Three of a kind\n");
      }
      
      else if(TwoPair == 2)
      {
        printf("Two Pair\n");
      }
      
      else
      {
        printf("You have nothing\n");
      }
    
      if(numberOfReRolls<2)
      {
        printf("\nDo you want to reroll? ");
      
        scanf (" %c", &var);
      }

      if (var == 'y' || var== 'Y')
      {
          
        numberOfReRolls++;
        continue;
      }
	  
    }
	
    return 0;
}

																			\