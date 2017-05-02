#include <iostream>

char board[] = {'-','-','-','-','-','-','-','-','-'};

using namespace std;

void print_start()
 {
    cout<<"Move options:"<<endl;
    cout<<"-9-|-8-|-7-"<<endl;
    cout<<"-4-|-5-|-6-"<<endl;
    cout<<"-1-|-2-|-3-"<<endl;
 }

void print_board()
 {
    cout<<"Board:"<<endl;
    cout<<"-"<<board[6]<<"-|-"<<board[7]<<"-|-"<<board[8]<<"-"<<endl;
    cout<<"-"<<board[3]<<"-|-"<<board[4]<<"-|-"<<board[5]<<"-"<<endl;
    cout<<"-"<<board[0]<<"-|-"<<board[1]<<"-|-"<<board[2]<<"-"<<endl;
 }

int get_move()
 {
    print_board();
    cout<<"Your move: "<<endl;
    int user_move;
    cin>>user_move;

  while(user_move>9 || user_move<1 || board[user_move - 1]!='-')
     {
            cout<<"Incorrect move!!! Try again!!!"<<endl;
            cin>>user_move;
     }
  return user_move;    
 }

 bool Win_Or_Lose(char player)
{

 int Win[][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};

 for(int i = 0; i<8; i++)
 {
    int count = 0;
    for(int j = 0; j<3;j++)
    {
          if(board[Win[i][j]] == player)
           count++;
          }   
          if(count == 3)
          {
               return true;
          }
     }
     return false;
  
}





char Get_Winner()
 {
       int turn = 1;
       while(!Win_Or_Lose('X') && !Win_Or_Lose('0'))
       {
             int user_move = get_move();
             if(turn%2 == 1)
             {
                     board[user_move - 1] = 'X';
                     if(Win_Or_Lose('X'))
                     {
                              cout<<"Player X has won!!!";
                              return 'X'; 
                    } }
              else
              {
                     board[user_move - 1] = '0';
                     if(Win_Or_Lose('0'))
                     {
                             cout<<"Player 0 has won!!!";
                             return '0';
        }             }
       turn++;
        
       if(turn == 10){
       cout<<"Draw!"<<endl;
        return 'D';
        }
 }

}
int main()
{
 cout<<endl<<"      !!!Welcome to Tic-Tac-Toe!!!       "<<endl<<endl;
 
 string reply = "Y";
 int x_wins = 0;
 int o_wins = 0;
 int ties = 0;


      
 while(reply == "Y")
  {
       print_start();
       char winner = Get_Winner(); 
       print_board();
        
 switch(winner)
  {
       case 'X':
        x_wins++;
        break;
       case '0':
        o_wins++;
        break;
       case 'D':
        ties++;
        break;
  }
  
  cout<<"------Games stats:------"<<endl;
  cout<<"Player X: "<<x_wins<<endl;
  cout<<"Player 0: "<<o_wins<<endl;
  cout<<"Ties: "<<ties<<endl;
  cout<<"Would you like to play again(Y/N)?"<<endl;
  cin>>reply;
  } 

 return 0;
}