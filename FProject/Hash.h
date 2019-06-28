#ifndef HASH
#define HASH

#include <iostream>
#include <string>
#include <list>

#include "Info.h"

using namespace std;

class Hash{
	int no_of_buckets;
	list<Info> *table;

	public:
		Hash(){
            table = new list<Info>[26];
        }

        int validateUserName(int index, string name){
            for(auto x: table[index]){
               if(x.getKey() == ""){
                    return 0;
                }

            }

            for(auto x: table[index]){
               if(x.getKey() == name){
                    return 1;
                }
            }
            return 2;
		}

		int validatePass(int index, string name, string pass){
            for(auto x: table[index]){
               if(x.getKey() == ""){
                    return 0;
                }

            }

            for(auto x: table[index]){
               if(x.getKey() == name){
               		if(x.getValue() == pass){
                    	return 1;
                    }
                }
            }
            return 2;
		}

		void insertInfo(Info info, int index){
            table[index].push_back(info);
        }

		void deleteInfo(string account){
		    int position;
            int counter = 0;
		    char first_Letter = account[0];
		    int ascii_firstLetter = (int)first_Letter;
		    int index = hashFunction(ascii_firstLetter);

		    list <Info> :: iterator i;
            for (i = table[index].begin();
            i != table[index].end(); i++) {
            if (i->getKey() == account)
                break;
            }

  // if key is found in hash table, remove it
            if (i != table[index].end())
                table[index].erase(i);
		}

		void displayInfos(){
		    for(int i = 0; i<26; i++){
                cout << "Index " << i << " contains:" << endl;
                for(auto x: table[i]){
                    cout << "Name: " << x.getKey() << endl << "Password: " << x.getValue() << endl;
                }
                cout << endl;
            }
		}

		int hashFunction(int ascii_of_first_letter){
            return ascii_of_first_letter-65;
		}
};

#endif
