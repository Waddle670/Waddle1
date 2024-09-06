#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// function declarationcl
int randNum();

//function implementation
int randNum(int sd)
{
    srand(time(0) + sd);
    return (rand() % 6 + 1);
}

// Declaring dice class
class Dice
{
	private:
	    int faceValue;
	
	public:
	    Dice(int fv = randNum())
	    {
	        faceValue = fv;
	    }
	    int getFaceValue()
	    {	
			this->displayFV();
	        return this->faceValue;
	    }
	    void displayFV(){
		  switch(this->faceValue){
		    case 1:
		      cout << " ------------ " << endl;
		      cout << "|            |" << endl;   
		      cout << "|      *     |" << endl;
		      cout << "|            |" << endl;
		      cout << " ------------ " << endl;
		      break;
		
		    case 2:
		      cout << " ------------ " << endl;
		      cout << "|  *        |" << endl;   
		      cout << "|           |" << endl;
		      cout << "|        *  |" << endl;
		      cout << " ------------ " << endl;
		      break;
		
		    case 3:
		      cout << " ------------ " << endl;  
		      cout << "|  *        |" << endl;
		      cout << "|     *     |" << endl;
		      cout << "|        *  |" << endl;
		      cout << " ------------ " << endl;
		      break;
		
		    case 4:
		      cout << " ------------ " << endl;
		      cout << "|  *     *  |" << endl;   
		      cout << "|           |" << endl;
		      cout << "|  *     *  |" << endl;
		      cout << " ------------ " << endl;
		      break;
		
		    case 5:
		      cout << " ------------ " << endl;
		      cout << "|  *     *  |" << endl;   
		      cout << "|     *     |" << endl;
		      cout << "|  *     *  |" << endl;
		      cout << " ------------ " << endl;
		      break;
		
		    case 6:
		      cout << " ------------ " << endl;
		      cout << "|  *     *  |" << endl;
		      cout << "|  *     *  |" << endl;
		      cout << "|  *     *  |" << endl;
		      cout << " ------------ " << endl;
		      break;
		
		    default:
		      cout << "Invalid face value" << endl;
		  }
		
		}
};

// Declaring Player class
class Player
{
	private:
	    string name;
	    int score;
	    Dice dice1;
	    Dice dice2;
	
	public:
	    Player(string n, Dice d1, Dice d2) : name(n), dice1(d1), dice2(d2), score(0) {}
	
	    void setScore()
	    {
	        this->score = this->dice1.getFaceValue() + this->dice2.getFaceValue();
	    }
	
	    void play()
	    {
	        cout << "\n Player : " << this->name << " Rolling" << endl;
	        this->setScore();
	    }
	
	    int getScore()
	    {
	        return this->score;
	    }
	
	    string getName()
	    {
	        return this->name;
	    }
};

// Declaring GameController class
class GameController
{
	private:
	    Player player1;
	    Player player2;
	
	public:
	    GameController(Player p1, Player p2) : player1(p1), player2(p2) {}
	
	    void play()
	    {
	        this->player1.play();
	        this->player2.play();
	
	        if (this->player1.getScore() > this->player2.getScore())
	        {
	            cout << this->player1.getName() << " Won the game" << endl;
	        }
	        else if (this->player1.getScore() < this->player2.getScore())
	        {
	            cout << this->player2.getName() << " Won the game" << endl;
	        }
	        else
	        {
	            cout << " We have a tie" << endl;
	        }
	    }
};

int main()
{   
	string fpname, spname;
	int cont = 1;
	while (cont==1)
	{
		cout << " First player Enter your name : ";
		cin >> fpname;
		cout << " Second player Enter your name : ";
		cin >> spname;
		  
	    Dice d1(randNum(4));
	    Dice d2(randNum(7));
	    Dice d3(randNum(2));
	    Dice d4(randNum(5));
	    
	    Player p1(fpname,d1,d2);
	    Player p2(spname,d3,d4);
	    
	    GameController game(p1, p2);
	    game.play();
	    
	    cout << "\n Enter"<<endl<< " 1 to Restart Game"<<endl<<" 0 to exit : ";
        cin>>cont;
	}
    return 0;
}
