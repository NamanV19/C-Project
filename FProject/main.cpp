#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <list>

#include "viewSeats.h"
#include "Info.h"
#include "Hash.h"

using namespace std;


int main()
{
	const char separator = ' ';

	vector<viewSeats> seatsAvengers; // vector that contains seats for a movie at a certain time. 1 movie = 1 vector
	vector<viewSeats> seatsAladdin;
	vector<viewSeats> seatsJW3;
	vector<viewSeats> seatsG2;

	vector<string> currentMovies;
	vector<string> comingSoon;

	for(int i = 0; i < 3; i++){
		seatsAvengers.push_back(viewSeats()); // creates multiple objects based on how many time slots are available
		seatsAladdin.push_back(viewSeats());
		seatsJW3.push_back(viewSeats());
		seatsG2.push_back(viewSeats());
	}

	map<string, vector<viewSeats> > moviesInfo;
	// initializing movies available
	moviesInfo.insert({"AVENGERS: END GAME", seatsAvengers});
	moviesInfo.insert({"ALADDIN", seatsAladdin});
	moviesInfo.insert({"JOHN WICK: CHAPTER 3 - PARABELLUM", seatsAladdin});
	moviesInfo.insert({"GODZILLA II: KING OF THE MONSTERS", seatsG2});
	comingSoon.push_back("ANNA");
	comingSoon.push_back("CHILDS PLAY");
	comingSoon.push_back("MEN IN BLACK: INTERNATIONAL");
	comingSoon.push_back("TOY STORY 4");
	Hash hash1;
    string input_name, input_password;
    int input_choice, index, check, ascii_firstLetter, checkPass, index1, ascii_firstLetter1;

    while(true){
    	cout << right << setw(30) << setfill(separator) << "TIXXX ONLINE BOOKING" << endl;
        cout << "1. Login" << endl << "2. Register" << endl << "3. View" << endl << "4. Exit" << endl << endl;
        cout << "Please input choice: " << endl;
        cin >> input_choice;

        if(input_choice == 1){
        	string a;
        	string n;
            cout << "Enter username: ";
            cin >> a;
            a[0] = toupper(a[0]);

            char first_Letter = a[0];
            ascii_firstLetter = (int)first_Letter;
            index = hash1.hashFunction(ascii_firstLetter);


            check = hash1.validateUserName(index, a);
            if(check == 1){
        		cout << "Enter password: ";
        		cin >> n;
        		checkPass = hash1.validatePass(index, a, n);
        		if(checkPass == 1){
        			cout << "Welcome " << a << endl;
        			break;
				}
				else if(checkPass == 0 || checkPass == 2){
					cout << "Incorrect user name or password.\n" << endl;
				}
			}
			else if (check == 0 || check == 2) {
                cout << "Incorrect user name or password.\n" << endl;
		    }
        }

        else if(input_choice == 2){
            cout << "Please input user name (No space in user name): " << endl;
            cin >> input_name;

            input_name[0] = toupper(input_name[0]);

            char first_Letter = input_name[0];
            ascii_firstLetter = (int)first_Letter;
            index = hash1.hashFunction(ascii_firstLetter);

            check = hash1.validateUserName(index, input_name);

            if(check == 1) {
                cout << "This user name is already taken. Please choose another user name.\n" << endl;
		    }

		    else if (check == 0 || check == 2) {
                cout << "Please input password [3..20]: " << endl;
				cin.ignore();
				getline(cin, input_password);
				if(input_password.length() < 3 || input_password.length() > 20){
					cout << "Password must be between 3 until 30 characters. \n" << endl;
				}
				else{
					Info info(input_name, input_password);
	                hash1.insertInfo(info, index);
	                cout << "Account registered!\n" << endl;
				}
		    }
        }

        else if(input_choice == 3){
            hash1.displayInfos();
        }

        else if(input_choice == 4){
            break;
        }
    }

	while(true){
		cout << right << setw(30) << setfill(separator) << "TIXXX ONLINE BOOKING" << endl;
		int x;
		cout << "\n1. View Movies Available\n2. Upcoming Movies (Coming Soon)\n3. Exit" << endl;
		cin >> x;
		if(x == 3){
			break;
		}
		switch(x){
			case 1:
				{
				int y;
				int count = 1;
				cout << right << setw(30) << setfill(separator) << "MOVIES AVAILABLE" << endl;
				for(map<string, vector<viewSeats> >::const_iterator itr = moviesInfo.begin(); itr != moviesInfo.end(); ++itr){
			        cout << count << ". " << itr->first << endl;
			        currentMovies.push_back(itr->first);
			        count++;
			    }
			    cout << "\n\n5. GO BACK" << endl;
				cin >> y;
				if(y == 1){
					cout << "Time Available: \n1. 11:00\n2. 13:40\n3. 19:05\n\n4. GO BACK" << endl;

					int a;
					cin >> a;
					if(a == 1){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: " << currentMovies[0] << endl;
						seatsAladdin[0].seats();
						seatsAladdin[0].view();
						for(int i = 0; i < b; i++){
							seatsAladdin[0].book();
							if(seatsAladdin[0].count == 1){
								b++;
							}

						}
						break;
					}
					else if(a == 2){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: " << currentMovies[0] << endl;
						seatsAladdin[1].seats();
						seatsAladdin[1].view();
						for(int i = 0; i < b; i++){
							seatsAladdin[1].book();
							if(seatsAladdin[1].count == 1){
								b++;
							}
						}
						break;
					}
					else if(a == 3){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: " << currentMovies[0] << endl;
						seatsAladdin[2].seats();
						seatsAladdin[2].view();
						for(int i = 0; i < b; i++){
							seatsAladdin[2].book();
							if(seatsAladdin[2].count == 1){
								b++;
							}
						}
						break;
					}
					else{
						break;
					}
				}
				else if(y == 2){
					cout << "Time Available: \n1. 16:20\n2. 21:45\n\n3. GO BACK" << endl;

					int a;
					cin >> a;
					if(a == 1){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: " << currentMovies[1] << endl;
						seatsAvengers[0].seats();
						seatsAvengers[0].view();
						for(int i = 0; i < b; i++){
							seatsAvengers[0].book();
							if(seatsAvengers[0].count == 1){
								b++;
							}
						}
						break;
					}
					else if(a == 2){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: " << currentMovies[1] << endl;
						seatsAvengers[1].seats();
						seatsAvengers[1].view();
						for(int i = 0; i < b; i++){
							seatsAvengers[1].book();
							if(seatsAvengers[1].count == 1){
								b++;
							}
						}
						break;
					}
					else{
						break;
					}
				}
				else if(y == 3){
					cout << "Time Available: \n1. 11:00\n2. 16:20\n3. 21:40\n\n4. GO BACK" << endl;

					int a;
					cin >> a;
					if(a == 1){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: " << currentMovies[2] << endl;
						seatsG2[0].seats();
						seatsG2[0].view();
						for(int i = 0; i < b; i++){
							seatsG2[0].book();
							if(seatsG2[0].count == 1){
								b++;
							}
						}
						break;
					}
					else if(a == 2){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: " << currentMovies[2] << endl;
						seatsG2[1].seats();
						seatsG2[1].view();
						for(int i = 0; i < b; i++){
							seatsG2[1].book();
							if(seatsG2[1].count == 1){
								b++;
							}
						}
						break;
					}
					else if(a == 3){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: " << currentMovies[2] << endl;
						seatsG2[2].seats();
						seatsG2[2].view();
						for(int i = 0; i < b; i++){
							seatsG2[2].book();
							if(seatsG2[2].count == 1){
								b++;
							}
						}
						break;
					}
					else{
						break;
					}

				}
				else if(y == 4){
					cout << "Time Available: \n1. 13:40\n2. 19:00\n\n3. GO BACK" << endl;

					int a;
					cin >> a;
					if(a == 1){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: "<< currentMovies[3] << endl;
						seatsJW3[0].seats();
						seatsJW3[0].view();
						for(int i = 0; i < b; i++){
							seatsJW3[0].book();
							if(seatsJW3[0].count == 1){
								b++;
							}
						}
						break;
					}
					else if(a == 2){
						int b;
						cout << "How many seats would you like to book: " << endl;
						cin >> b;
						cout << "\nMOVIE: " << currentMovies[3] << endl;
						seatsJW3[1].seats();
						seatsJW3[1].view();
						for(int i = 0; i < b; i++){
							seatsJW3[1].book();
							if(seatsJW3[1].count == 1){
								b++;
							}
						}
						break;
					}
					else{
						break;
					}
				}
				else{
					break;
				}
				}

			case 2:
				int count = 1;
				cout << right << setw(30) << setfill(separator) << "UPCOMING MOVIES" << endl;
				for(int i = 0; i < 4; i++){
					cout << count << ". " << comingSoon[i] << endl;
					count++;
				}
				break;
		}
	}

	seatsAladdin[0].clear_list();
	seatsAladdin[1].clear_list();
	seatsAladdin[2].clear_list();

	seatsAvengers[0].clear_list();
	seatsAvengers[1].clear_list();

	seatsG2[0].clear_list();
	seatsG2[1].clear_list();
	seatsG2[2].clear_list();

	seatsJW3[0].clear_list();
	seatsJW3[1].clear_list();

	return 0;
}
