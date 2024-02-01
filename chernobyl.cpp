
#include "chernobyl.h"

void printt(vector<vector<loc> >& region){
	int pop=0;
for (int i = 0; i < region.size(); i++)// printing the state. 
	{
		for (int j = 0; j < region.at(i).size(); j++)
		{
			if (region[i][j].regionType == ' ')
			{
				cout << ' ' << ' ';
			}
			else if (region[i][j].regionType == '-')
			{
				cout << '-' << ' ';
			}
			else if (region[i][j].regionType == '#')
			{
				cout << '#' << ' ';
			}
			else
			{
				if (region[i][j].population == 0)// checks if the region is populated
				{
					cout << region[i][j].regionType << " ";

				}
				else
				{
					pop += region[i][j].population;// adds it the main population
					cout << region[i][j].population << " ";
				}
			}


		}
		cout << endl;
	}
}
void game(vector<vector<loc> >& region, int &sick){
    cout<<"Would you like to play a game? (y/n): ";
    char c, userChoice;
    cin>>c;
	int col2=3;
    if (c=='y'){
    do {
        c='n';
int computerChoice,k,row,col; //row & col is the coordinates for the random reactor to explode
srand(time(NULL));
computerChoice = (rand() % 2);
cout<<"take a pick heads or tails(h/t), if you guess correctly you win if not it can have dire consequences (type h for heads and anyother character for tails): ";
cin>>userChoice;
k = (tolower(userChoice)=='h') ? 0 : 1;
if(k==computerChoice){
    cout<<" Congrats you win! ";
}
else{
    cout<<"UH OH! Looks like you guessed incorrectly, Now a random reactor will explode! \n";
    row=(rand() % 3)+1;//row
    col=(rand() % 3);//column
region[row][col].regionType='X'; //reactor explodes
region[row][col].population=0;
printt(region);
cout<<"Oh No! the radiation is spreading down to the area below! \n";    
    //radition builds down to the left of residential
	for (int r=5;r<8;r++){
		for(int c=0;c<2;c++){
			region[r][c].regionType='r'; 
			region[r][c].population=0;
			printt(region);
			sleep(5);
			cout << endl;
		}
	}
    //residential getting sick
	cout<<"Looks like its spreading to the residential area and making the residents sick! \n";
	for(int r=5;r<8;r++){
			sick+=region[r][col2].population;
	}
	col2++;
	cout<<"sick population is: "<<sick<<endl;
	if (sick > 16)
	{
		break;
	}
	else
	{
		cout << "Would you like to try again? (y/n): ";
		cin >> c;
	}
   

}
if(c!='y'){
    cout<<"Have a great day!\n";
}

}while(c=='y');


}
else{
    cout<<"Understandable. Have a nice day!\n";
}
}


    
    
    


