#include<iostream>
#include<ctime>
#include<windows.h>
#include<algorithm>
#include<conio.h>
#include <cstdlib>
using namespace std;

/// Declaration of Global Variables
string UserStore[100];
int ScoreStore[100];
int PlayerPlayed = 0;

int main(){
	// Run Admin the Dev C++ to access other settings.
		
	// To rename the EXE
	SetConsoleTitleA("Compare and Conquer");

	// Auto Wide Screen
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
    
	// For Designing the Font
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(consoleHandle, FALSE, &fontInfo);
    fontInfo.dwFontSize.X = 16;//width
    fontInfo.dwFontSize.Y = 50;//height
    SetCurrentConsoleFontEx(consoleHandle, FALSE, &fontInfo);
    
    // For Removing scrollbar area
    HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    GetConsoleScreenBufferInfo(consoleOutput, &screenBufferInfo);
    COORD newBufferSize = {
        screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1,
        screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(consoleOutput, newBufferSize);
    SMALL_RECT newWindowRect = {
        0,
        0,
        newBufferSize.X - 1,
        newBufferSize.Y - 1
    };
    SetConsoleWindowInfo(consoleOutput, TRUE, &newWindowRect);
    
	// Set the console screen buffer size
    COORD bufferSize = { 120, 30 };  // Adjust the values as per your desired width and height
    SetConsoleScreenBufferSize(consoleOutput, bufferSize);
    
    

    // THIS CODE TO MAKE THE TEXT COLOR MORE CLEAR
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);

    // Set the text attributes to include the bold attribute
    SetConsoleTextAttribute(consoleHandle, consoleInfo.wAttributes | FOREGROUND_INTENSITY);

    InputUserArea:
    system("cls");
    
        // Declaration of Local Variables
        string User;
        int playing = 0;
        int score = 0;
        int plnum = 0;
        char CorrectAns, InitialAns, dec2;
        int Levelplaying, Difficulty, Giver;
        int QL, QR;
        bool valid;
        string word, correctword;
		char correctmarks;
		
		// Itro Area
			system("COLOR 04");// 0 Black, 4 Red
				Sleep(1000);
			cout<<"\n\n\n\n\n\t Developed by a Team from BSIT-1 SRCB";
				Sleep(2000);
				 	cout<<"\n\t               Presents";
				Sleep(2000);
			system("cls");




		// For Inputing UserName
		system("cls");
		system("COLOR 8F");// 8 = Gray // F means White Text
		cout<<"\n\n\n\n\n\n\t\t  COMPARE AND CONQUER";
		Sleep(2000);
		system("cls");
		cout<<"\n\n\n\n\n\t\t  COMPARE AND CONQUER";
        cout<<"\n\t      Enter Username: ";
        cin>>User;

        // Locating Player Data
        bool found = false;
        for(int v = 0; v <= PlayerPlayed; v++){
            if(User == UserStore[v]){
            	plnum = v;
                playing = ScoreStore[v];
                found = true;
                break;
            }
        }
		// If No Existing Data Then Make A New One
        if(!found){
            UserStore[PlayerPlayed] = User;
            ScoreStore[PlayerPlayed] = 0;
            plnum = PlayerPlayed;
            PlayerPlayed+=1;
        }

		// Loading Screen function
        cout<<"\n\t\t  Logging-in";
        Sleep(500);
        cout<<". ";
        Sleep(500);
        cout<<". ";
        Sleep(500);
        cout<<". ";
        Sleep(500);


		//Menu System Area
        menu:
    	ScoreStore[plnum] = playing;
        system("cls");
        system("COLOR 1F");
        char dec1;
        cout<<"USER: "<<User<<endl;
        cout<<"SCORE: "<<playing;
      cout<<"\n\n\t        -[COMPARE AND CONQUER]-";
        cout<<"\n\t           (1) PLAY";
        cout<<"\n\t           (2) LEADERBOARD";
        cout<<"\n\t           (3) CHANGE USER";
      cout<<"\n\n\t  Only Use Numbers from the Keyboard.";
        
        while (_kbhit()) { ///Ensure no GetchLoop Happen
      	_getch();	}
  		dec1 = _getch();//
  		
  		if(dec1 == '1' || dec1 == '2' || dec1 == '3'){
		cout<<"\n\t        Processing '"<<dec1<<"'";
        Sleep(500);
        cout<<". ";
        Sleep(500);
        cout<<". ";
        Sleep(500);
        cout<<". ";
        Sleep(500);
		} 
		
		// For Declearation of Decisions
        switch(dec1){
        	
        case '1': // Decision for the PLAY
        system("cls");
        system("COLOR 8F"); /// GRAY
        cout<<" MECHANICS ";
        
          cout<<"\n\n\t   Identify the given numbers if its:";
            cout<<"\n\t(<)Lessthan, (>)GreaterThan, or (=)Equal.";
        
        cout<<"\n\n\t     Keyboard Controls: ";
          cout<<"\n\t       - Num 1 for (<)Lessthan";
          cout<<"\n\t       - Num 2 for (>)GreaterThan";
          cout<<"\n\t       - Num 3 for (=)Equal";
          
        cout<<"\n\n\t       (Press any key to start)";
		while (_kbhit()) { ///Ensure no GetchLoop Happen
      	_getch();	}
       dec1 = _getch();///
      
        system("cls");
        /// Generating the 10 Problems
        Levelplaying = 1;
        score = 0;
        
        while(true){
        	    //To Set Enable the Timer
		    int startg = 1, timerg;
        	// Score given in the level  
        	if(Levelplaying>0){	 Giver = 1; timerg = 20; }    
			if(Levelplaying>10){  Giver = 2; timerg = 17; }  
			if(Levelplaying>25){  Giver = 3; timerg = 15; }  
		    if(Levelplaying>50){  Giver = 4; timerg = 12; }  
			if(Levelplaying>100){  Giver = 7; timerg = 10; }  	
			if(Levelplaying>500){  Giver = 13; timerg = 8; }  
			if(Levelplaying>1000){  Giver = 20; timerg = 5; }  
			
        	system("COLOR 3F");// Aqua color
			Difficulty = Levelplaying + 3;
			// Printing the Decisions and Problem Area
            QL = 1+rand()%Difficulty;
            QR = 1+rand()%Difficulty;
            char questionmark = '?';
            above1:
            Top1:
			system("cls");
            cout<<"Level: "<<Levelplaying<<endl;
            cout<<"Points: "<<score<<endl;
            cout<<"\r\n\t\t    Given: "<<QL<<" "<<questionmark<<" "<<QR<<endl;
            cout<<"\t  __________________________________";
          cout<<"\n\t  |1) '<'    |2)   '>'     |3) '=' |"<<endl;
            cout<<"\t  | LessThan | GreaterThan | Equal |"<<endl;
            cout<<"\t  |__________|_____________|_______|"<<endl;
            if(valid == true) goto Bot1;
		
            if(QL < QR)CorrectAns = '1';
            else if(QL > QR) CorrectAns = '2';
            else if(QL == QR) CorrectAns = '3';
            cout<<endl;      	
            while (timerg > 0) {
        timerg -= startg;

        if (_kbhit()) {
        	while(_kbhit()){
            InitialAns = _getch();}

            break;
		   }

        // Update timer display
        cout << "\r\t      Time remaining: "<<timerg<<" Seconds";
        cout.flush();
        Sleep(1000);
    }
     cout << "\n";

    if (timerg <= 0) {
        	   system("COLOR 4F");
				cout<<"\n\t   TIMES UP! The correct answer is '"<<CorrectAns<<"'";
				Sleep(3000);
		        playing+=score;
				goto menu;
    }
    else {
            if(InitialAns == '1' || InitialAns == '2' || InitialAns == '3'){
            if(InitialAns == '1') {
            	
			word = "LessThan";
			questionmark = '<';
			}
            if(InitialAns == '2'){
            word = "GreaterThan";
            questionmark = '>';
			} 
            if(InitialAns == '3'){
            word = "Equal";
            questionmark = '=';
			}
			
			if(CorrectAns == '1') correctword = "LessThan";
	
            if(CorrectAns == '2') correctword = "GreaterThan";
			 
            if(CorrectAns == '3') correctword = "Equal";
			
            system("cls");
            valid = true;
			goto Top1;
			Bot1:
			valid = false;
			
            if(InitialAns == CorrectAns){
                system("COLOR 2F");
            	cout<<"\n\t You got the Correct Answer!    "<<"+"<<Giver;
            	score+=Giver;
            	Levelplaying++;
            	Sleep(1500);
			}else{
			    system("COLOR 4F");
				cout<<"\n    Wrong, the correct answer is '"<<CorrectAns<<"/"<<correctword<<"'";
				Sleep(3000);
		        playing+=score;
				goto menu;
			}
			}else{
			cout<<"\n\t     '"<<InitialAns<<"' is Not on the Choices.";
			Sleep(1500);
			goto above1;
				}
  			  }
			}

        
    	case '2': // Decision for the LEADERBOARD
		system("cls");
		system("COLOR 6F"); // 6 = yellow bacground // F is white Text
		
    	//To sort each Player score from High to Low
		for(int i = 0; i < PlayerPlayed; i++){
    		for(int j = i+1; j <= PlayerPlayed; j++){
        	if(ScoreStore[i] < ScoreStore[j]){
            swap(ScoreStore[i], ScoreStore[j]);
            swap(UserStore[i], UserStore[j]);
        	}
    	}
	}
	// TO PRINT THE USERS AND THERE SCORES
		cout<<"LEADERBOARD:\n";
		for(int l = 0; l <= PlayerPlayed; l++){
    	if(!UserStore[l].empty()) {
        cout<<"\t    "<<UserStore[l]<<" has the score of "<<ScoreStore[l]<<endl;
		    }
		}
		cout<<"\nPress Any key to go Back.";
		while (_kbhit()) { ///Ensure no GetchLoop Happen
      	_getch();	}
       dec2 = _getch();///
        cout<<"\n\t      Returning to Menu";
        Sleep(500);
        cout<<". ";
        Sleep(500);
        cout<<". ";
        Sleep(500);
        cout<<". ";
        Sleep(500);
        goto menu;
        
    	case '3': // Decision for the CHANGING USERNAME
    		ScoreStore[plnum] = playing;
    		goto InputUserArea;
    		
    	default: // If wrong Inputs then nothing will happen
    	cout<<endl<<"\t      '"<<dec1<<"' Is not on the Choices.";
    	cout<<"\n\t          Please Try Again.";
    	Sleep(1500);
       	goto menu;
    	}
   }///END
