#include <stdio.h>
#include <stdlib.h>
/* 9x9-es sudoku megoládsa
a fájl álljon egy 9x9-es számtáblázatból (természetesen 10-es számrendszerbeli számjegyekre gondolok), a számok egy db szóközzel legyenek elválasztva
sudokuban lévő üres négyzetek legyenek 0-val jelölve */

/*a program módosítható úgy is, hogy ne csak egy megoldást találjon meg, viszont a sudokus oldalakon lévő feladatoknak csak 1 megoldása van*/
int sudoku[9][9];
int sudoku2[9][9];
unsigned long int megoldasok=0;
void visszairas(int i,int j)
{
    int sor,oszlop;
    for (sor=i;sor<9;sor++)
    {
        for (oszlop=j;oszlop<9;oszlop++)
        {
            sudoku2[sor][oszlop]=sudoku[sor][oszlop];
        }
    }
}
int beolvasas(char* filepath) //works
{
    int i,j;
    FILE *fm;
    if (fm=fopen(filepath,"r"));
    else return -1;

    for (i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
                fscanf(fm,"%d",&sudoku[i][j]);
                sudoku2[i][j]=sudoku[i][j];
        }
    }
    fclose(fm);
    return 0;
}
void kiiratas() //kiirja a sudoku2-t
{
    int i,j;
    for (i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%d ",sudoku2[i][j]);
        }
        printf("\n");
    }
}

int rekurziv(int i,int j)
{
    int kezdoi=i,kezdoj=j;
    int szam=1;
  if (sudoku2[i][j]==0)
  {
      for (szam=1;szam<10;szam++)
      {
          sudoku2[i][j]=szam;
        if (vizsgalat(i,j)==0)
        {
        leptetes:{
           j++;
               if (j==9)
               {
                   j=0;i++;
                   if (i==9)
                   {
                       megoldasok++;
                       kiiratas();
                       printf("------------------------------------------------------------\n");
                       return 0;

                   }
                }
            }
         if (rekurziv(i,j)==-1)
         {
            i=kezdoi;j=kezdoj;
         }
         //itt
         else
         return 0;
        }
      }
  }
  else
  {
      leptetes2:{
           j++;
           if (j==9)
           {
               j=0;i++;
               if (i==9)
               {
                megoldasok++;
                kiiratas();
                printf("------------------------------------------------------------\n");
                return 0;
               }
           }
       }
    if (rekurziv(i,j)==-1)
    {
        visszairas(i,j);
        return -1;
    }
    //itt
    else
    return 0;
  }
  visszairas(i,j);
  return -1;
}
int vizsgalat(int i, int j) //ha rossz a szám akkor igaz, works
{
    int vizsga1,vizsga2; //vizsga1 a sor, vizsga2 az oszlop
    vizsga2=j;
    for (vizsga1=0;vizsga1<9;vizsga1++)
    {
        if (vizsga1==i)
        continue;
        if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
        return 1;
    }
        vizsga1=i;
    for (vizsga2=0;vizsga2<9;vizsga2++)
    {
        if (vizsga2==j)
        continue;
        if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
        return 1;
    }
    if (i<3) //legfelsõk
    {
        if (j<3) //bal
        {
            for (vizsga1=0;vizsga1<3;vizsga1++)
            {
                for (vizsga2=0;vizsga2<3;vizsga2++)
                {
                    if (vizsga1==i && vizsga2==j)
                    continue;
                    if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
                    return 1;
                }
            }
        }
        if (j>2 && j<6) //középsõ
        {
            for (vizsga1=0;vizsga1<3;vizsga1++)
            {
                for (vizsga2=3;vizsga2<6;vizsga2++)
                {
                    if (vizsga1==i && vizsga2==j)
                    continue;
                    if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
                    return 1;
                }
            }
        }
        if (j>5) //jobb
        {
            for (vizsga1=0;vizsga1<3;vizsga1++)
            {
                for (vizsga2=6;vizsga2<9;vizsga2++)
                {
                    if (vizsga1==i && vizsga2==j)
                    continue;
                    if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
                    return 1;
                }
            }
        }
    }
    if (i>2 && i<6) //középsõk
    {
       if (j<3) //bal
        {
            for (vizsga1=3;vizsga1<6;vizsga1++)
            {
                for (vizsga2=0;vizsga2<3;vizsga2++)
                {
                    if (vizsga1==i && vizsga2==j)
                    continue;
                    if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
                    return 1;
                }
            }
        }
        if (j>2 && j<6) //középsõ
        {
            for (vizsga1=3;vizsga1<6;vizsga1++)
            {
                for (vizsga2=3;vizsga2<6;vizsga2++)
                {
                    if (vizsga1==i && vizsga2==j)
                    continue;
                    if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
                    return 1;
                }
            }
        }
        if (j>5) //jobb
        {
            for (vizsga1=3;vizsga1<6;vizsga1++)
            {
                for (vizsga2=6;vizsga2<9;vizsga2++)
                {
                    if (vizsga1==i && vizsga2==j)
                    continue;
                    if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
                    return 1;
                }
            }
        }
    }
    if (i>5) //legalsók
    {
        if (j<3) //bal
        {
            for (vizsga1=6;vizsga1<9;vizsga1++)
            {
                for (vizsga2=0;vizsga2<3;vizsga2++)
                {
                    if (vizsga1==i && vizsga2==j)
                    continue;
                    if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
                    return 1;
                }
            }
        }
        if (j>2 && j<6) //középsõ
        {
            for (vizsga1=6;vizsga1<9;vizsga1++)
            {
                for (vizsga2=3;vizsga2<6;vizsga2++)
                {
                    if (vizsga1==i && vizsga2==j)
                    continue;
                    if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
                    return 1;
                }
            }
        }
        if (j>5) //jobb
        {
            for (vizsga1=6;vizsga1<9;vizsga1++)
            {
                for (vizsga2=6;vizsga2<9;vizsga2++)
                {
                    if (vizsga1==i && vizsga2==j)
                    continue;
                    if (sudoku2[vizsga1][vizsga2]==sudoku2[i][j])
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
char tomb[257];
printf("adja meg a fajl eleresi utjat: (pl asd.txt)\n");
fgets(tomb,256,stdin); //van meg benne \n
tomb[strlen(tomb)-1]='\0'; // \n-t kiszedjük
//printf("%s",tomb);
if(beolvasas(tomb))
{
   printf("beolvasasi hiba :(\n");
   return -1;
}
if (rekurziv(0,0)==-1) //ennek akkor van jelentősége, ha nem csak egy megoldást keresünk
printf("megoldasok szama: %d", megoldasok);
return 0;
}



/*
       leptetes:
       {
           j++;
           if (j==9)
           {
               j=0;i++;
               if (i==9)
               {
                   kiiratas();exit(1);
               }
           }
       }
*/
