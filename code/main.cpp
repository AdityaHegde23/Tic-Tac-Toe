#include <iostream>
#include <conio.h>
#include <stdlib.h>
//#include <graphics.h>

char m[9];
using namespace std;

class tictactoe
{

 public:

     user()
     {
         int pos=0;
         cout<<"\n\tEnter your position : ";
         cin>>pos;
         if((m[pos-1]!='o') && (m[pos-1]!='x') && m[pos-1]>48 && m[pos-1]<58)
          m[pos-1]='x';
         else
            {
             cout<<"\n\t Invalid entry";
             return -1;
            }



     }

     bot()
     {
       int i,j,temp;
            for(i=0;i<9;)
            {

               if(m[i]==m[i+1] && m[i+2]!='x' && m[i+2]!='o')//besides in rows
               {
                     m[i+2]='o';
                     return 0;
               }
               else if(m[i]==m[i+2] && m[i+1]!='x' && m[i+1]!='o')//besides in rows
              {
                 m[i+1]='o';
                 return 0;
              }
              else if(m[i+1]==m[i+2] && m[i]!='x' && m[i]!='o')//besides in rows
              {
                 m[i]='o';
                 return 0;
              }
              i=i+3;
            }
        for(j=0;j<3;j++)
         {
              if(m[j]==m[j+3] && m[j+6]!='x' && m[j+6]!='o')//besides in  columns
              {
                 m[j+6]='o';
                 return 0;
              }
              else if(m[j]==m[j+6] && m[j+3]!='x' && m[j+3]!='o')//besides in  columns
              {
                 m[j+3]='o';
                 return 0;
              }
               else if(m[j+3]==m[j+6] && m[j]!='x' && m[j]!='o')
              {
                 m[j]='o';
                 return 0;
              }
         }
              if(m[0]==m[4] && m[8]!='x' && m[8]!='o') //diagonals
              {
                  m[8]='o';
                  return 0;
              }
              else if(m[4]==m[8] && m[0]!='x' && m[0]!='o')
              {
                  m[0]='o';
                  return 0;
              }
              else if(m[0]==m[8] && m[4]!='x' && m[4]!='o')
              {
                  m[4]='o';
                  return 0;
              }
               else if(m[2]==m[4] && m[6]!='x' && m[6]!='o')
              {
                  m[6]='o';
                  return 0;
              }
              else if(m[4]==m[6] && m[2]!='x' && m[2]!='o')
              {
                  m[2]='o';
                  return 0;
              }
              else if(m[2]==m[6] && m[4]!='x' && m[4]!='o')
              {
                  m[4]='o';
                  return 0;
              }
             else
             {
                 if(m[4]!='o' && m[4]!='x')
                 {
                     m[4]='o';
                     return 0;
                 }

                 if(m[0]=='x'|| m[7]=='x' || m[8]=='x' && m[6]!='o' && m[6]!='x')
                 {
                     m[6]='o';
                     return 0;
                 }
                 else if(m[0]=='x' || m[7]=='x' || m[8]=='x' && m[2]!='o' && m[2]!='x')
                 {
                    m[2]='o';
                     return 0;
                 }
                 if(m[1]!='o' && m[1]!='x' && m[4]!='x')
                 {
                     m[1]='o';
                     return 0;
                 }
                 for(temp=0;temp<9;temp++)
                 {

                     if((m[temp]!='x') && (m[temp]!='o'))
                     {
                         m[temp] = 'o';
                         return 0;
                     }
                 }
             }
         }

     int display()
     {
       /* m[0]='o';
        m[2]='x';
        m[1]='o';
        m[3]='x';
        m[4]='o';
        m[5]='o';
        m[6]='x';
        m[7]='x';
        m[8]='o';  */


        cout<<"\t\t\t         |            |        \n";
        cout<<"\   \t\t            "<<m[0]<<"    |     "<<m[1]<<"      |     "<<m[2]<<endl;
        cout<<"\t\t\t         |            |        \n";
        cout<<"\t\t\      ------------------------------------ \n";
        cout<<"\t\t\t         |            |        \n";
        cout<<"\   \t\t            "<<m[3]<<"    |     "<<m[4]<<"      |     "<<m[5]<<endl;
        cout<<"\t\t\t         |            |        \n";
        cout<<"\t\t\      ------------------------------------ \n";
        cout<<"\t\t\t         |            |        \n";
        cout<<"\t  \t            "<<m[6]<<"    |     "<<m[7]<<"      |     "<<m[8]<<endl;
        cout<<"\t\t\t         |            |        \n";
        //cout<<"end of display";
    return(50);

     }

     int quit()
     {
         int i,drawc=0;
        // cout<<"entering quit()\n";
        for(i=0;i<9;) //rows
        {

            if(m[i]==m[i+1] && m[i+1]==m[i+2])
            {

                    if(m[i]=='x')
                    {
                        // cout<<"\n\t\t\t---------------PLAYER WIN--------------\n";
                            return 1;
                    }
                    else if(m[i]=='o')
                    {
                         //cout<<"\n\t\t\t---------------BOT WIN-----------------\n";
                            return 2;
                    }
                    else
                        return -1;


            }
                i=i+3;
        }
        for(i=0;i<3;i++) //columns
        {

            if(m[i]==m[i+3] && m[i+3]==m[i+6])
            {

                    if(m[i]=='x')
                    {
                        // cout<<"\n\t\t\t---------------PLAYER WIN--------------\n";
                        return 1;
                    }
                    else if(m[i]=='o')
                    {
                         //cout<<"\n\t\t\t---------------BOT WIN-----------------\n";
                            return 2;
                    }
                    else
                        return -1;

            }
        }
        if((m[0]==m[4] && m[4]==m[8]) || (m[2]==m[4] && m[4]==m[6])) //diagonals
        {

                if(m[4]=='x')
                {
                    // cout<<"\n\t\t\t---------------PLAYER WIN--------------\n";

                    return 1;
                }
                else if(m[4]=='o')
                {
                    // cout<<"\n\t\t\t---------------BOT WIN-----------------\n";
                        return 2;
                }
                else
                    return -1;


        }
        for(i=0;i<9;i++)
        {
            if(m[i]=='x' || m[i]=='o')
             drawc++;
        }
        if(drawc==9)
        {
           // cout<<"\n\t\t\t--------------- Draw -----------------\n";
            return 0;
        }
        else return -1;
     }

};



int main()
{

    int flagq=0,flagu=0;
    cout<<"\n\t\t\t\tWELCOME TO TIC-TAC-TOE\n";
    cout<<"\n\t\t\tPlayer:x\tBot:o\n\n";
    //int gd = DETECT, gm;

    //initgraph(&gd, &gm, "");
     //settextstyle( 10, 0, 6);
    //outtextxy(150, 150, "x   o");
    tictactoe c1;
    m[0]=49;
    for(int i=1;i<9;i++)
    {

        m[i]=m[i-1]+1;
    }
     c1.display();

    do
     {
        do
        {
         flagu=c1.user();
        }while(flagu==-1);

        flagq=c1.quit();
        if(flagq==1)
        {
            cout<<"\n\t\t\t---------------PLAYER WIN--------------\n";
            c1.display();
            exit(1);
        }
        else if(flagq==2)
        {
            cout<<"\n\t\t\t---------------BOT WIN-----------------\n";
            c1.display();
           exit(1);
        }
        else if(flagq==0)
        {
            cout<<"\n\t\t\t--------------- Draw -----------------\n";
            c1.display();
            exit(1);
        }
        c1.bot();
        flagq=c1.quit();
        if(flagq==1)
        {
            cout<<"\n\t\t\t---------------PLAYER WIN--------------\n";
            c1.display();
            exit(1);
        }
        else if(flagq==2)
        {
            cout<<"\n\t\t\t---------------BOT WIN-----------------\n";
            c1.display();
            exit(1);
        }
        else if(flagq==0)
        {
            cout<<"\n\t\t\t--------------- Draw -----------------\n";
            c1.display();
            exit(1);
        }
        c1.display();

     }while(flagq==-1);

        c1.display();
        getch();
//closegraph();
}

