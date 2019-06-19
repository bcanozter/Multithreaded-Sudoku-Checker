//
//  main.cpp
//  CSCI 3120 Assignment 2
//
//  Created by Burak Can ÖZTER on 2018-06-25.
//  Copyright © 2018 Burak Can ÖZTER. All rights reserved.
//

/*
 
 CSCI 3120 ASSIGNMENT 2 DESCRIPTION
 
 Date: June 5th, 2018
 
 
 Design a multithreaded Sudoku Solution Checker program that accepts a Sudoku solution from the user as input,
 and determines whether the solution is valid or invalid.
 
 This sudoku solution checker is using 9 threads to check each subgrid and 2 threads to check each row and
 column.
 
 The program is able to determine which row or column has an error and returns number.
 
 
 */

#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string>
#include <cstdlib>
#include <istream>
#include <thread>
#include <unistd.h>

int rowss[9];       //Row array initializer
int columnss[9];    //Column array initializer





char array[9][9];  //Two dimensional array initialization to store our 9x9 sudoku data
//Rows 0 to 8, 9 in total
//Columns 0 to 8, 9 in total

void threadConfirm(int thread,int &check, std::string subgrid){
    /*
     A function to print out the result from a thread.
     
     */
    
    
    if(check==1){
        std::cout << "Thread-> " << thread <<" confirmed " <<  subgrid  << " is valid\n" << std::endl;
    }
    else
    {
        std::cout << "Thread-> " << thread << " confirmed " <<  subgrid  << " is invalid\n" << std::endl;
    }
    
    
}

void rowsColumnsConfirm(int thread, int &check, bool rows){
    /*
     A function to print the result from the two threads that check row and columns seperately.
     
     */
    if(rows){
        for(int i=0; i<9; i++){
            if(rowss[i] !=0){
                
                std::cout << "Thread-> " << thread << " confirmed row " << i << " is invalid\n" << std::endl;
            }
            else{
                std::cout << "Thread-> " << thread << " confirmed row " << i << " is valid\n" << std::endl;
                
            }
        }
    }
    
    else{
        for(int i=0; i<9; i++){
            if(columnss[i] !=0){
                
                std::cout << "Thread-> " << thread << " confirmed column " << i << " is invalid\n" << std::endl;
            }
            else{
                std::cout << "Thread-> " << thread << " confirmed column " << i << " is valid\n" << std::endl;
            }
        }
        
        
    }
}


void* checksubgrid(void *arg){
    /*
     Check row 0 to 3
     Check column 0 to 3
     which is 3x3, first subgrid
     TOP LEFT SUBGRID
     */
    unsigned int r, c;
    int a=0;
    unsigned start_row =0;
    unsigned start_col =0;
    
    
    for (r = start_row; r < start_row + 3; r ++) {
        for (c = start_col; c < start_col + 3; c++) {
            
            
            //substracting 48 because ASCII character values.
            
            a =  a + (int)array[r][c] -48; //In order to be a valid column or row, all the numbers added
            //should be equal to 45. Otherwise it is wrong.
            
        }
    }
    
    if(a == 45){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checksubgrid1(void *arg){
    /*
     Thread 1
     MIDDLE RIGHT SUBGRID
     Check row    3 to 6
     Check column 0 to 3
     
     Same checking process for first subgrid
     */
    unsigned int r, c;
    int a=0;
    unsigned start_row =3;
    unsigned start_col =0;
    
    for (r = start_row; r < start_row + 3; r ++) {
        for (c = start_col; c < start_col + 3; c++) {
            
            
            
            
            a =  a + (int)array[r][c] -48;
            // 1+2+3..+9 = 45
            
        }
    }
    
    if(a == 45){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checksubgrid2(void *arg){
    /*
     Thread 2
     BOTTOM LEFT SUBGRID
     Row    6 to 9
     Column 0 to 3*/
    unsigned int r, c;
    int a=0;
    unsigned start_row =6;
    unsigned start_col =0;
    
    for (r = start_row; r < start_row + 3; r ++) {
        for (c = start_col; c < start_col + 3; c++) {
            
            
            //substracting 48 because ASCII characters.
            
            a =  a + (int)array[r][c] -48;
            // 1+2+3..+9 = 45
            
        }
    }
    
    if(a == 45){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checksubgrid3(void *arg){
    /*
     Thread 3
     MIDDLE TOP SUBGRID
     Row    0 to 3
     Column 3 to 6*/
    unsigned int r, c;
    int a=0;
    unsigned start_row =0;
    unsigned start_col =3;
    
    for (r = start_row; r < start_row + 3; r ++) {
        for (c = start_col; c < start_col + 3; c++) {
            
            
            //substracting 48 because ASCII characters.
            
            a =  a + (int)array[r][c] -48;
            // 1+2+3..+9 = 45
            
        }
    }
    
    if(a == 45){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checksubgrid4(void *arg){
    /* Thread 4
     TOP RIGHT SUBGRID
     Row    0 to 3
     Column 6 to 9*/
    unsigned int r, c;
    int a=0;
    unsigned start_row =0;
    unsigned start_col =6;
    
    
    for (r = start_row; r < start_row + 3; r ++) {
        for (c = start_col; c < start_col + 3; c++) {
            
            
            //substracting 48 because ASCII characters.
            
            a =  a + (int)array[r][c] -48;
            // 1+2+3..+9 = 45
            
        }
    }
    
    if(a == 45){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checksubgrid5(void *arg){
    /* Thread 5
     MIDDLE SUBGRID
     Row    3 to 6
     Column 3 to 6*/
    unsigned int r, c;
    int a=0;
    unsigned start_row =3;
    unsigned start_col =3;
    
    for (r = start_row; r < start_row + 3; r ++) {
        for (c = start_col; c < start_col + 3; c++) {
            
            
            //substracting 48 because ASCII characters.
            
            a =  a + (int)array[r][c] -48;
            // 1+2+3..+9 = 45
            
        }
    }
    
    if(a == 45){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checksubgrid6(void *arg){
    /* Thread 6
     MIDDLE RIGHT SUBGRID
     Row    3 to 6
     Column 6 to 9*/
    unsigned int r, c;
    int a=0;
    unsigned start_row =3;
    unsigned start_col =6;
    
    for (r = start_row; r < start_row + 3; r ++) {
        for (c = start_col; c < start_col + 3; c++) {
            
            
            a =  a + (int)array[r][c] -48;
            // 1+2+3..+9 = 45
            
        }
    }
    
    if(a == 45){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checksubgrid7(void *arg){
    /* Thread 7
     MIDDLE BOTTOM SUBGRID
     Row    6 to 9
     Column 3 to 6*/
    unsigned int r, c;
    int a=0;
    unsigned start_row =6;
    unsigned start_col =3;
    
    for (r = start_row; r < start_row + 3; r ++) {
        for (c = start_col; c < start_col + 3; c++) {
            
            
            //substracting 48 because ASCII characters.
            
            a =  a + (int)array[r][c] -48;
            // 1+2+3..+9 = 45
            
        }
    }
    
    if(a == 45){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checksubgrid8(void *arg){
    /* Thread 8
     
     BOTTOM RIGHT SUBGRID
     
     Row    6 to 9
     Column 6 to 9*/
    unsigned int r, c;
    int a=0;
    unsigned start_row =6;
    unsigned start_col =6;
    
    
    for (r = start_row; r < start_row + 3; r ++) {
        for (c = start_col; c < start_col + 3; c++) {
            
            
            //substracting 48 because ASCII characters.
            
            a =  a + (int)array[r][c] -48;
            // 1+2+3..+9 = 45
            
        }
    }
    
    if(a == 45){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checkRows(void *arg){
    /*
     Check each row and flag if a row has an error.
     
     
     */
    unsigned max_col=9;
    int a=0;
    int b=0;
    int j =0;
    while(b<9){
        for(j =0; j<max_col; j++){
            /*
             In order to access every element in the rows, we want to keep row number same
             while column number is increasing and after it reaches max column, gets out of
             for loop. and increase row number by 1 to access next row.
             */
            a = a+ (int)array[b][j] - 48;
            
            
        }
        
        if(a != 45){
            rowss[b] = 1; //if row elements added up less or greater than 45 that row has an error.
        }
        a=0;
        b++;
        
    }
    
    if(a == 405){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
    
}

void* checkColumns(void *arg){
    /*
     
     Similarly to row checking algorithm we keep column number same as we increase row number
     in order to access every element in the column.
     
     */
    unsigned max_col =9;
    int a=0;
    int b=0;
    int j=0;
    
    while(b<9){
        
        for(j =0; j<max_col; j++){
            a = a+ (int)array[j][b] - 48;
            
            
            
        }
        if(a != 45){
            columnss[b] = 1;  //If the column added up less or greater than 45 that column has an error.
        }
        
        a=0;
        b++;
    }
    
    if(a == 405){
        return (void*) 1;
    }
    else{
        return (void*) 0;
    }
}


int main(int argc, const char * argv[]) {
    std::ifstream sudokuSol;
    sudokuSol.open("Sud_Sol.txt");
    std::string sudoku_string((std::istreambuf_iterator<char>(sudokuSol)),(std::istreambuf_iterator<char>()));
    int count=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            array[i][j]=sudoku_string[count];
            count=count+2;
        }count++;
    }
    
    
    /*
     
     This is where we create our threads and then pass our function to execute.
     They all run concurrently.
     
     */
    
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_t t5;
    pthread_t t6;
    pthread_t t7;
    pthread_t t8;
    pthread_t t9;
    pthread_t t10;
    pthread_t t11;
    
    
    //Pass our functions to threads in order to check subgrids seperately.
    pthread_create(&t1,NULL,&checksubgrid,NULL);
    pthread_create(&t2,NULL,&checksubgrid1,NULL);
    pthread_create(&t3,NULL,&checksubgrid2,NULL);
    pthread_create(&t4,NULL,&checksubgrid3,NULL);
    pthread_create(&t5,NULL,&checksubgrid4,NULL);
    pthread_create(&t6,NULL,&checksubgrid5,NULL);
    pthread_create(&t7,NULL,&checksubgrid6,NULL);
    pthread_create(&t8,NULL,&checksubgrid7,NULL);
    pthread_create(&t9,NULL,&checksubgrid8,NULL);
    pthread_create(&t10,NULL,&checkRows,NULL);
    pthread_create(&t11,NULL,&checkColumns,NULL);
    
    
    int check=0; //Return value Result = 1 valid, else invalid
    
    pthread_join(t1,(void**)&check);
    threadConfirm( 1, check, "Top Left Subgrid");
    
    pthread_join(t2,(void**)&check);
    threadConfirm( 2, check, "Middle Right Subgrid");
    
    pthread_join(t3,(void**)&check);
    threadConfirm( 3,check, "Bottom Left Subgrid");
    
    pthread_join(t4,(void**)&check);
    threadConfirm( 4, check, "Middle Top Subgrid");
    
    pthread_join(t5,(void**)&check);
    threadConfirm( 5, check,"Top Right Subgrid");
    
    pthread_join(t6,(void**)&check);
    threadConfirm( 6, check, "Middle Subgrid");
    
    pthread_join(t7,(void**)&check);
    threadConfirm( 7, check, "Middle Left Subgrid");
    
    pthread_join(t8,(void**)&check);
    threadConfirm( 8, check,"Middle Bottom Subgrid");
    
    pthread_join(t9,(void**)&check);
    threadConfirm( 9, check, "Bottom Right Subgrid");
    
    pthread_join(t10,(void**)&check);
    rowsColumnsConfirm(10, check,true);
    
    pthread_join(t11,(void**)&check);
    rowsColumnsConfirm(11,check,false);
    
    
    
    
    
    
    
    sudokuSol.close();
    return 0;
}




