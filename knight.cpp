#include <iostream>

using namespace std;


/* TODO LIST

TODO: Add Class (Square)
	Elements: Key, Link pointers (x8)
	Methods: Data returns, default constructor, Set link
	
TODO: Function to initialize a GRID of SQUARE objects
TODO: Function to set links for GRID

TODO: Function to return least moves, utilizing a breadth first search and a boolean traversal array

END LIST */

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
	 
   //Default Constructor
	 Square() {key=-1; level=0; opt1=NULL; opt2=NULL; opt3=NULL; opt4=NULL; opt5=NULL; opt6=NULL; opt7=NULL; opt8=NULL; };

   int Key(){return key;}
   
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
       cout<<i<<" "<<j<<"\n";
      array[j][i].setKey(i*8 + j);
      
      if(i-2 >= 0 && j-1 >=0)
        array[i][j].setOpt1(&array[i-2][j-1]);
      if(i-1 >= 0 && j-2 >=0)
        array[i][j].setOpt2(&array[i-1][j-2]);
      if(i+1 >= 0 && j-2 >=0)
        array[i][j].setOpt3(&array[i+1][j-2]);
      if(i+2 >= 0 && j-1 >=0)
        array[i][j].setOpt4(&array[i+2][j-1]);
      if(i+2 >= 0 && j+1 >=0)
        array[i][j].setOpt5(&array[i+2][j+1]);
      if(i+1 >= 0 && j+2 >=0)
        array[i][j].setOpt6(&array[i+1][j+2]);
      if(i-1 >= 0 && j+2 >=0)
        array[i][j].setOpt7(&array[i-1][j+2]);
      if(i-2 >= 0 && j+1 >=0)
        array[i][j].setOpt8(&array[i-2][j+1]);
      
    }
  }
  return;
}

void shortest(){
  
  

}

int main(){
	
  
  int startX = 4;
  int startY = 6;
  
  int goalX = 7;
  int goalY = 3;
  
  Square grid[8][8];
  
  buildGraph(grid);

	
	return 0;
}