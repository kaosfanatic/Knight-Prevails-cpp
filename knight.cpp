#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;




class Square{
	 
	 int key;
   
   int level;
	 
	 Square* opt1;  //Options 1-8, for each potential space the knight can move to.
	 Square* opt2;
	 Square* opt3;
	 Square* opt4;
	 Square* opt5;
	 Square* opt6;
	 Square* opt7;
	 Square* opt8;
	 
public:
	 
   bool visited;
   //Default Constructor
	 Square() {key=-1; level=0; visited = false; opt1=NULL; opt2=NULL; opt3=NULL; opt4=NULL; opt5=NULL; opt6=NULL; opt7=NULL; opt8=NULL; };
   
   int Key(){return key;}
   int Level(){return level;}
   
   Square* Opt1(){return opt1; };
   Square* Opt2(){return opt2; };
   Square* Opt3(){return opt3; };
   Square* Opt4(){return opt4; };
   Square* Opt5(){return opt5; };
   Square* Opt6(){return opt6; };
   Square* Opt7(){return opt7; };
   Square* Opt8(){return opt8; };
   
   void setKey(int n){ key = n; };
   void setLevel(int n){ level = n; };
   void setOpt1(Square * link){ opt1 = link; };
   void setOpt2(Square * link){ opt2 = link; };
   void setOpt3(Square * link){ opt3 = link; };
   void setOpt4(Square * link){ opt4 = link; };
   void setOpt5(Square * link){ opt5 = link; };
   void setOpt6(Square * link){ opt6 = link; };
   void setOpt7(Square * link){ opt7 = link; };
   void setOpt8(Square * link){ opt8 = link; };
   
};


void buildGraph(Square array[][8]){
  
  for(int j = 0; j < 8; j++){
    for(int i = 0; i < 8; i++){
      array[j][i].setKey(i*8 + j);
      
      if(i-2 >= 0 && j-1 >=0)
        array[i][j].setOpt1(&array[i-2][j-1]);
      if(i-1 >= 0 && j-2 >=0)
        array[i][j].setOpt2(&array[i-1][j-2]);
      if(i+1 <= 7 && j-2 >=0)
        array[i][j].setOpt3(&array[i+1][j-2]);
      if(i+2 <= 7 && j-1 >=0)
        array[i][j].setOpt4(&array[i+2][j-1]);
      if(i+2 <= 7 && j+1 <= 7)
        array[i][j].setOpt5(&array[i+2][j+1]);
      if(i+1 <= 7 && j+2 <= 7)
        array[i][j].setOpt6(&array[i+1][j+2]);
      if(i-1 >= 0 && j+2 <= 7)
        array[i][j].setOpt7(&array[i-1][j+2]);
      if(i-2 >= 0 && j+1 <= 7)
        array[i][j].setOpt8(&array[i-2][j+1]);
      
    }
  }
  return;
}

void shortest(queue<Square*> * Queue){

  Square* holder;
  
  
  while(!Queue->empty()){
    holder = Queue->front();
    Queue->front()->visited = true;
    //cout<<"Current location: "<<holder->Key()<<"\n";
    
    if(holder->Opt1()!=NULL && !holder->Opt1()->visited){
      //cout<<"Testing option 1: "<<holder->Opt1()->Key()<<"\n";
      holder->Opt1()->visited = true;
      holder->Opt1()->setLevel(holder->Level()+1);
       Queue->push(holder->Opt1());
    }
    
    if(holder->Opt2()!=NULL && !holder->Opt2()->visited){
      //cout<<"Testing option 2: "<<holder->Opt2()->Key()<<"\n";
      holder->Opt2()->visited = true;
      holder->Opt2()->setLevel(holder->Level()+1);
       Queue->push(holder->Opt2());
    }
    
    if(holder->Opt3()!=NULL && !holder->Opt3()->visited){
      //cout<<"Testing option 3: "<<holder->Opt3()->Key()<<"\n";
      holder->Opt3()->visited = true;
      holder->Opt3()->setLevel(holder->Level()+1);
       Queue->push(holder->Opt3());
    }
    
     
    if(holder->Opt4()!=NULL && !holder->Opt4()->visited){
      //cout<<"Testing option 4: "<<holder->Opt4()->Key()<<"\n";
      holder->Opt4()->visited = true;
      holder->Opt4()->setLevel(holder->Level()+1);
       Queue->push(holder->Opt4());
    }
    
     
    if(holder->Opt5()!=NULL && !holder->Opt5()->visited){
      //cout<<"Testing option 5: "<<holder->Opt5()->Key()<<"\n";
      holder->Opt5()->visited = true;
      holder->Opt5()->setLevel(holder->Level()+1);
       Queue->push(holder->Opt5());
    }
    
     
    if(holder->Opt6()!=NULL && !holder->Opt6()->visited){
      //cout<<"Testing option 6: "<<holder->Opt6()->Key()<<"\n";
      holder->Opt6()->visited = true;
      holder->Opt6()->setLevel(holder->Level()+1);
       Queue->push(holder->Opt6());
    }
    
     
    if(holder->Opt7()!=NULL && !holder->Opt7()->visited){
      //cout<<"Testing option 7: "<<holder->Opt7()->Key()<<"\n";
      holder->Opt7()->visited = true;
      holder->Opt7()->setLevel(holder->Level()+1);
       Queue->push(holder->Opt7());
    }
    
     
    if(holder->Opt8()!=NULL && !holder->Opt8()->visited){
      //cout<<"Testing option 8: "<<holder->Opt8()->Key()<<"\n";
      holder->Opt8()->visited = true;
      holder->Opt8()->setLevel(holder->Level()+1);
       Queue->push(holder->Opt8());
    }
    
    Queue->pop();
  }
  
  return;

}

int main(){
	
  
  int startX = -1;
  int startY = -1;
  
  
  int goalX = -1;
  int goalY = -1;
  
  bool checkInput = false;
  
  string inputString;
  
 
  
  while(startX < 0 || startX > 7){
  cout<<"\nEnter starting position (x): ";
    while(!(cin >> startX)){
      cin.clear();
      cin.ignore(1000, '\n');
      cout<<"Invalid value.\n";
      cout<<"\nEnter starting position (x): ";
    }
    if(startX < 0 || startX >7)
        cout<<"Invalid value.\n";
  }
  
  while(startY < 0 || startY > 7){
  cout<<"\nEnter starting position (y): ";
    while(!(cin >> startY)){
      cin.clear();
      cin.ignore(1000, '\n');
      cout<<"Invalid value.\n";
      cout<<"\nEnter starting position (y): ";
    }
    if(startY < 0 || startY >7)
        cout<<"Invalid value.\n";
  }
  
  while(goalX < 0 || goalX > 7){
  cout<<"\nEnter final position (x): ";
    while(!(cin >> goalX)){
      cin.clear();
      cin.ignore(1000, '\n');
      cout<<"Invalid value.\n";
      cout<<"\nEnter final position (x): ";
    }
    if(goalX < 0 || goalX >7)
        cout<<"Invalid value.\n";
  }
  
  while(goalY < 0 || goalY > 7){
  cout<<"\nEnter final position (y): ";
    while(!(cin >> goalY)){
      cin.clear();
      cin.ignore(1000, '\n');
      cout<<"Invalid value.\n";
      cout<<"\nEnter final position (y): ";
    }
    if(goalY < 0 || goalY >7)
        cout<<"Invalid value.\n";
  }
  
  
  
  Square grid[8][8];
  
  buildGraph(grid);
  
  queue<Square*> s;
  
  
  grid[startX][startY].setLevel(0);
  s.push(&grid[startX][startY]);
  
  
 
  shortest(&s);
  
  
  cout<<"\n\nShortest path\nfrom\tx: "<<startX<<"\ty: "<<startY<<"\n"\
      <<"to\tx: "<<goalX<<"\ty: "<<goalY<<"\n\nResult: "<<grid[goalX][goalY].Level()<<"\n";

	
	return 0;
}