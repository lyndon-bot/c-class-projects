#include <iostream>
#include <vector>
#include <string>
#include "header.h";

using namespace std;

void checkAnswer(const vector<string> & test, string testCase, string expectedAns);
void printTestCase(const vector<string> & testCase);

string ABoardGame::whoWins(vector<string>board){

int sizeb =  board.size();


region = new string* [sizeb];
value = new int* [sizeb];

for(int i = 0; i < sizeb; i++){
    region[i] = new string[sizeb];
    value[i] = new int[sizeb];
}

for(int i = 0; i < sizeb; i++){
 for(int j = 0; j< sizeb; j++){

    region[i][j] = board[i][j];

    }
}

// give each region a square value

int regnum = sizeb /2;
int step = 0;

while(step <= regnum){

if(step == 0){
    for(int i = 0; i < sizeb; i++){
        for(int j = 0; j< sizeb; j++){

            if(i == 0 || i == sizeb -1 || j == 0 || j == sizeb -1){
            value[i][j] = regnum;
            }
        }
    }
}else{

    for(int i = step; i < sizeb- step; i++){
        for(int j = step; j < sizeb - step; j++){
            if(i == step || i == sizeb - 1 - step || j == step || j == sizeb -1 - step){
                value[i][j] = regnum - step;
            }
        }
    }

}

step++;
}


// ccheck regions for a winner

int stepc = 1;
int acount = 0;
int bcount = 0;

while(stepc <= regnum){
    for(int i = 0; i < sizeb; i++){
        for(int j = 0; j < sizeb; j++){

            if(value[i][j] == stepc){
                if(region[i][j] == "A"){
                    acount++;
                }else if(region[i][j] == "B"){
                    bcount++;
                }

        }
    }



    if(acount > bcount){

        return "Alice";

    }else if(bcount > acount){

        return "Bob";

    }else{

        //return "Draw";

    }

stepc++;



}



if(acount == 0 && bcount == 0){
    return "Draw";
}

if(acount == bcount){
    return "Draw";
}
return "run";
}
}
int main()
{
    string t1[] =  {".....A", "......", "..A...", "...B..", "......", "......"};
	string t2[] = {"AAAA", "A.BA", "A..A", "AAAA"};
	string t3[] = {"..", ".."};
	string t4[] = {"BBB..BAB...B.B", ".AAAAAAAAAAAA.", "AA.AA.AB..A.AB", "..........B.AB", ".A..BBAB.A.BAB", ".AB.B.......A.", ".A..A.AB.A..AB", ".ABAA.BA...BA.", "BAAAB.....ABA.", ".A....B..A..B.", "B...B....B..A.", "BA.B..A.ABA.A.", "BAAAA.AAAAA.A.", "B.B.B.BB.B...."};
	string t5[] = {"..A..AAA..AA", "ABABB..AAAAA", "ABBBBBBBBBA.", "AABBBABABBAA", "...BABABABBA", "B.BA..A.BBA.", "AA.A..B.AB.B", "..BA.B.AABAA", "..ABABBBABA.", ".ABB.BBBBBAA", "ABAAA.AA.A.A", "A..AAA.AAA.A"};
	string t6[] = {"B..ABAABBB", "B.........", "A..A.AA..B", "A.BBBAA..A", "B.AAAAB...", "A..BBBBB.A", "B..ABAABBA", "A......B.B", "B......A.A", "BA.AABBB.A"};

	vector<string> test1(t1, t1 + sizeof(t1)/sizeof(string));
	vector<string> test2(t2, t2 + sizeof(t2)/sizeof(string));
	vector<string> test3(t3, t3 + sizeof(t3)/sizeof(string));
	vector<string> test4(t4, t4 + sizeof(t4)/sizeof(string));
	vector<string> test5(t5, t5 + sizeof(t5)/sizeof(string));
	vector<string> test6(t6, t6 + sizeof(t6)/sizeof(string));

	checkAnswer(test1, "case 1 ", "Alice");
	checkAnswer(test2, "case 2 ", "Bob");
	checkAnswer(test3, "case 3 ", "Draw");
	checkAnswer(test4, "case 4 ", "Alice");
	checkAnswer(test5, "case 5 ", "Bob");
	checkAnswer(test6, "case 6 ", "Draw");

    return 0;
}

void checkAnswer(const vector<string> & test, string testCase, string  expectedAns)
{
	ABoardGame mygame;

	cout << "******************************\n";
	cout << "Testing " << testCase << endl << endl;

	printTestCase(test);

	string winner = mygame.whoWins(test);

	if(winner == "Draw"){
		cout << "\nIt is a tie.\n";
	}else{
		cout << endl << winner << " wins.\n";
	}
	if(winner == expectedAns){
		cout << "Passed " << testCase << endl;
	}else{
		cout << "Failed " << testCase << endl;
	}

	int sizeb = test.size();


    for(int i = 0; i < sizeb; ++i) {
        delete[] mygame.region[i];
    }

    delete[] mygame.region;


    for(int i = 0; i < sizeb; ++i) {

        delete[] mygame.value[i];
    }

    delete[] mygame.value;
}


void printTestCase(const vector<string> & test)
{
	for(int i=0; i<test.size(); i++)
	{
		for(int j=0; j<test[i].length(); j++)
			cout << test[i][j] << " ";
		cout << endl;
	}

}
