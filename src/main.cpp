
//
// Created by Amin on 2019-07-31.
//

#include "main.h"

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int map[8][8] = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
};

int counter = 0 ;

void search(int) ;
bool check(int , int);
void get_pos(int , int);
void set_illegal_move(int,int,int,int,int);


struct node {
    int x ;
    int y ;
};

vector <node> pos;

int main() {

    search(0) ;

    cout << "number of possible condition is :" << counter ;

    return 0 ;
}


void search(int x){

    if (x == 8){
        counter++ ;
    } else {
        for (int i = 0; i < 8; i++) {

            if (!check(x,i)) {

                continue ;

            } else {

                node position;
                position.x = x;
                position.y = i;
                pos.push_back(position);

                for (int k = 0; k < pos.size(); ++k) {

                    get_pos(pos.at(k).x, pos.at(k).y);

                }

                cout << "map of every move " << endl ;

                for (int l = 0; l < 8; ++l) {
                    for (int j = 0; j < 8; ++j) {
                        cout << map[l][j] << " ";
                    }
                    cout << endl;
                }

                search(x+1);

                for (int m = 0; m < 8 ; ++m) {
                    for (int j = 0; j < 8; ++j) {
                        map[m][j] = 0 ;
                    }
                }

                pos.pop_back();

                for (int k = 0; k < pos.size(); ++k) {
                    get_pos(pos.at(k).x, pos.at(k).y);
                }

            }
        }
    }
}

void get_pos(int x,int y){

    map[x][y] = 1;

    for (int j = -1 ; j <= 1 ; ++j) {
        for (int k = -1 ; k <=1 ; ++k) {
            if (j==0 && k == 0 ){
                continue ;
            } else {
                set_illegal_move(y,x,j,k,x);
            }

        }
    }



}


void set_illegal_move(int x ,int y ,int i ,int j,int y_hold){

    if (x+j >= 8 || x+j < 0 || y+i < 0 || y+i >= 8 ){
        return ;
    }

    map[y+i][x+j] = 1 ;

    set_illegal_move(x+j,y+i,i,j,y_hold) ;

}

bool check(int x , int y){

    if (map[x][y] == 1){
        return false ;
    } else {
        return true ;
    }

}