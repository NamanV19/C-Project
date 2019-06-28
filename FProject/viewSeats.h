#ifndef VIEWSEATS
#define VIEWSEATS

#include <iostream>
#include <string>

using namespace std;

class viewSeats{
	private:
    struct node {
        char row_name;
        int seat_no;
        string availability;
        node *next, *prev;
    }*head = NULL, *tail = NULL;

    public:


	    void insert(char row_name, int seat_no, string availability) {
	        node *curr = new(node);
	        curr->row_name = row_name;
	        curr->seat_no = seat_no;
	        curr->availability = availability;

	        int ascii_of_row = (int)row_name;

	        if (head == NULL) {
	            head = tail = curr;
	            curr->next = curr->prev = curr;
	        }

           else {
                curr->next = head;
                head->prev = curr;
                head = curr;
                curr->prev = tail;

            }
        }


	    void view() {
	        int count = 0;
	        node *curr = head;
	        if(tail == NULL){
	            cout << "No seats booked yet." << endl;
	        }

	        else{
	            while (curr != tail) {
	                cout << "Seat Row " << curr->row_name << " Number " <<  curr->seat_no+1 << " -- Availability Status: " <<  curr->availability << endl;
	                curr = curr->next;
	                count++;
	            }
	            cout << "Seat Row " << curr->row_name << " Number " <<  curr->seat_no+1 << " -- Availability Status: " <<  curr->availability << endl;
	        }
	    }

	    void clear_list(){
	        if (head != NULL)
	        {
	            node* curr = head->next;
	            while (curr != NULL && curr != head)
	            {
	                cout << "Deleting " << "row: " << curr->row_name << "  " << "Seat no: " <<  curr->seat_no << endl;
	                node* temp = curr;
	                curr = curr->next;
	                delete temp;
	            };
	            cout << "Deleting " << "row: " << head->row_name << "  " << "Seat no: " <<  head->seat_no << endl;
	            delete head;
	            head = NULL;
	        }
	    }
		char alphabet[22] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'};
		const char* board2[22][20];
//		const char separator = ' ';
		int count = 0;

		viewSeats(){
			for(int x = 0; x < 22; x++){
				for(int z = 0; z < 20; z++){
					board2[x][z] = "[ ]";
				}
			}
		}

		void seats(){
			cout << "    ";
			for(int c = 0; c < 20; c++){
				if(c < 10){
					cout << " " << c + 1 << " ";
				}
				else{
					cout << c + 1 << " ";
				}

				if(c != 0){
		    		if(c != 10){
		    			if(c == 13){
		    				cout << "       ";
						}
		    			if(c != 15 && c % 5 == 0){
			        		cout << "       ";
						}
					}
				}
			}
			cout << endl;

			for(int a = 0; a < 22; a++){
				cout << " " << alphabet[a] << "  ";
		        for(int b = 0; b < 20; b++){
		        	cout << board2[a][b];
		        	if(b != 0){
		        		if(b != 10){
		        			if(b == 13){
		        				cout << "       ";
							}
		        			if(b != 15 && b % 5 == 0){
				        		cout << "       ";
							}
						}
					}

		        }
		        cout << endl;
		    }
		    cout << "\n\n";
		    cout << right << setw(44) << setfill(' ') << "SCREEN" << endl;
		}
		void book(){
			char a;
			int b;
			cout << "\nWhich seat would you like to book?\nPlease enter seat row (e.g. A): ";
			cin >> a;
			cout << "Please enter seat number [1 - 20]: ";
			cin >> b;
			if(b < 1 || b > 20){
				cout << "Please enter a correct seat number." << endl;
			}
			for(int i = 0; i < 22; i++){
				if(alphabet[i] == a){
					b = b-1;
					if(board2[i][b] != "[x]"){
						count = 0;
						board2[i][b] = "[x]";
						insert(a, b, "Occupied");
						cout << "You have successfully booked Seat Row " << a << " Number " << b+1 << endl;
						break;

					}
					else if(board2[i][b] = "[x]"){
						cout << "Sorry, as shown on the screen the seat is already booked!\n";
						count = 1;
						break;
					}
				}
				else if(i == 21 && alphabet[i] != a){
					cout << "Seat row doesn't exist." << endl;
				}

			}
		}
};

#endif
