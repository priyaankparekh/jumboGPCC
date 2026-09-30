#include<bits/stdc++.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// John's Games

// vector<int> jg1 = {7, 9, 13, 24, 33, 40};
// vector<int> jg2 = {16, 19, 22, 29, 31, 39};
// vector<int> jg3 = {1, 7, 18, 22, 30, 36};

vector<vector<int>> johnGames = {
	{7, 9, 13, 24, 33, 40},
	{16, 19, 22, 29, 31, 39},
	{1, 7, 18, 22, 30, 36},
};

// Mary's Games

// vector<int> mg1 = {2, 22, 13, 24, 32, 39};
// vector<int> mg2 = {7, 22, 24, 31, 33, 40};
// vector<int> mg3 = {3, 7, 18, 21, 37, 38};

vector<vector<int>> maryGames = {
	{2, 22, 13, 24, 32, 39},
	{7, 22, 24, 31, 33, 40},
	{3, 7, 18, 21, 37, 38},
};

// Winning Numbers

set<int> winnings = {7,22,24,31,33,40};

 
// BONUS TASK
vector<int> systemTicket = {3,5,7,11,22,24,31,34,40};

vector<vector<int>> allPermutations;


void generatePermutations(vector<int> ticket){

	vector<int> mask = {1, 1, 1, 1, 1, 1, 0, 0, 0};
	int totalCount = 0;

	do{
		vector<int> currPerm;
		// totalCount++;
		// cout<<totalCount<<endl;

		bool first = true;
		for(int i = 0; i < systemTicket.size(); i++){
			if(mask[i]){
				currPerm.push_back(ticket[i]);
			}
		}
		allPermutations.push_back(currPerm);
	}while(prev_permutation(mask.begin(), mask.end()));

	// cout<<"PS: "<<allPermutations.size()<<endl;
}

vector<int> checkWinnings (vector<int> game, set<int>win){

	vector<int> intersecting_numbers;
	bool match = false;
	
	set_intersection(game.begin(), game.end(),win.begin(), win.end(), back_inserter(intersecting_numbers));	

	return intersecting_numbers;
}


int checkDivision (vector<int> intsec_num){

	int matches = intsec_num.size();
	int div = 0;

	if(matches < 3){
		div = 99;
	}
	else if (matches  == 3){
		div = 4;
	}
	else if (matches  == 4){
		div = 3;	
	}
	else if (matches  == 5){
		div = 2;
	}
	else if (matches  == 6){
		div = 1;
	}

	return div;

}


void gameStatus(string playerName, int div, vector<int> match, vector<int> game){

	string result = "";

	if(div <= 4){

		result = "won";
		cout<< playerName <<" "<< result << " Division "<< div  << " with matches ";

		for(auto x : match){
			cout<< x << " ";
		}

		cout<<"for game ";

		for(auto y: game){
			cout<< y <<" ";
		}
		cout<<endl;
	}

	else{
		result = "lost";
		cout<< playerName << " has "<< result <<" the game ";

		for(auto y: game){
			cout<< y <<" ";
		}
		cout<<endl;
	}
}


int main(){


	vector<int> gameMatches;
	
	int winningDivision = 0;
	
	// gameMatches = checkWinnings(jg1,winnings);
	// winningDivision = checkDivision(gameMatches);
	// gameStatus("John", winningDivision, gameMatches, jg1);
	
	// gameMatches = checkWinnings(jg2,winnings);
	// winningDivision = checkDivision(gameMatches);
	// gameStatus("John", winningDivision, gameMatches,jg2);
	
	// gameMatches = checkWinnings(jg3,winnings);
	// winningDivision = checkDivision(gameMatches);
	// gameStatus("John", winningDivision, gameMatches,jg3);
	
	// gameMatches = checkWinnings(mg1,winnings);
	// winningDivision = checkDivision(gameMatches);
	// gameStatus("Mary", winningDivision, gameMatches,mg1);
	
	// gameMatches = checkWinnings(mg2,winnings);
	// winningDivision = checkDivision(gameMatches);
	// gameStatus("Mary", winningDivision, gameMatches,mg2);
	
	// gameMatches = checkWinnings(mg3,winnings);
	// winningDivision = checkDivision(gameMatches);
	// gameStatus("Mary", winningDivision, gameMatches,mg3);

	cout<<"----------------- John's Results ------------------"<<endl;
	int johnWinCount = 0;

	for(int i = 0; i < johnGames.size(); i++){
		gameMatches = checkWinnings(johnGames[i], winnings);
		winningDivision = checkDivision(gameMatches);
		gameStatus("John", winningDivision, gameMatches, johnGames[i]);
		if(winningDivision<=4) johnWinCount++;
	}

	cout<<"----------------- John's Winning Count ------------------"<<endl;
	cout<<"John won a total of "<<johnWinCount<< " games"<<endl;

	cout<<"----------------- Mary's Results ------------------"<<endl;	
	int maryWinCount = 0;

	for(int i = 0; i < maryGames.size(); i++){
		gameMatches = checkWinnings(maryGames[i], winnings);
		winningDivision = checkDivision(gameMatches);
		gameStatus("Mary", winningDivision, gameMatches, maryGames[i]);
		if(winningDivision<=4) maryWinCount++;
	}

	cout<<"----------------- Mary's Winning Count ------------------"<<endl;
	cout<<"Mary won a total of "<<maryWinCount<< " games"<<endl;

	cout<<"----------------- BONUS TASK ------------------"<<endl;
	generatePermutations(systemTicket);

	int jackWinCount = 0;

	for(int i = 0; i < allPermutations.size(); i++){
		gameMatches = checkWinnings(allPermutations[i], winnings);
		winningDivision = checkDivision(gameMatches);
		gameStatus("Jack", winningDivision, gameMatches, allPermutations[i]);
		if(winningDivision<=4) jackWinCount++;
	}

	cout<<"----------------- Jack's Winning Count ------------------"<<endl;
	cout<<"Jack won a total of "<<jackWinCount<< " games"<<endl;

	return 0;

}
