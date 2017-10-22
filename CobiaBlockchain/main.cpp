//
//  main.cpp
//  CobiaBlockchain
//
//  Created on 25/09/2017. A journey begins.
//  Copyright © 2017 David Wallace. All rights reserved.
//  Version 0.1 Alpha
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include "Include/rsa.cpp"
using namespace std;

//blocktrail defaults
int height = 1000;
int width = 10;

string** loadTrail(unsigned height, unsigned width)
{
    string** name = 0;
    name = new string*[height];
    
    for (int h = 0; h < height; h++)
    {
        name[h] = new string[width];
        
        for (int w = 0; w < width; w++)
        {
            
            name[h][w] = "0000";
        }
    }
    int counter = 0;
    ifstream ffile("blocktrail.txt");
    while (ffile >> name[counter][0] >> name[counter][1] >> name[counter][2] >> name[counter][3] >> name[counter][4] >> name[counter][5] >> name[counter][6] >> name[counter][7] >> name[counter][8] >> name[counter][9])
    {
        counter++;
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //cout << name[h][w] << " ";
        }
        //cout << "\n";
    }
   // cout << "end";
    
    //commented out output, used for debugging
    return name;
}


void initNewFile() {
    string name[1000][10] = {};
    
    //initialise array
    for (int i =0; i < 10; i++){
        for (int y =0; y < 1000; y++){
            name[i][y]= "0000";
            
        }
        
    }

    ofstream myfile;
    myfile.open ("blocktrail.txt");
    for (int i =0; i < 100; i++){
        for (int y =0; y < 10; y++){
            myfile << name[i][y];
            myfile << " ";
            
        }
        myfile << "\n";
        
    }
    myfile.close();
    
}
int GetRandNumb(){
    int final =0;
    
    for (unsigned i = 0; i < 1000; i += 4) {
        int randTimeCol = time(0) * 17 % 1000;
        //int randTimeRow = time(0) * 17 % 10;
        //cout << randTimeCol <<endl;
        sleep(1);
        final = randTimeCol;
    }
    return final;
}
void blockchainRecordBlock(string block, int privateKeyp, int publicKeyq){
    ofstream file; // out file stream
    string output = enc(block, privateKeyp, publicKeyq);
    file.open("blockchain.txt", ios::app);
    file << "\n" << output;
    file.close();

    
    
}
int getRand () {
    
    return 0;
}
void randInsert(string str, int p, int q) {
    string block = "";

    //initNewFile();

   // string str("0123456789asdf");
    string** name = loadTrail(height, width);

    for (unsigned i = 0; i < str.length(); i += 4) {
        int randTimeCol = time(0) * 17 % 1000;
        int randTimeRow = time(0) * 17 % 10;
        //cout << randTimeCol <<endl;
        sleep(1);
        int check = 0;
        while (check != 1) {
            if (name[randTimeCol][randTimeRow] == "0000") {
                name[randTimeCol][randTimeRow]= str.substr(i, 4);
                check = 1;
            }
            else {
                 randTimeCol = time(0) * 17 % 1000;
                 randTimeRow = time(0) * 17 % 10;
                
            }
        }


        block = block + "-" + to_string(randTimeCol) + "-" + to_string(randTimeRow) + ",";
        //cout << str.substr(i, 4) << endl;
    }
    
    int sysTime = time(0);
    string x;
    
    
    
    
    
    ofstream myfile;
    myfile.open ("blocktrail.txt");
    for (int i =0; i < 1000; i++){
        for (int y =0; y < 10; y++){
            myfile << name[i][y];
            myfile << " ";
            
        }
        myfile << "\n";
        
    }
    myfile.close();
    block = block;
    blockchainRecordBlock(block, p, q);

}

void reAssemble(int p,int q){
    
    ifstream infile("blockchain.txt");
    string a, b, c;
    while (infile >> a >> b)
    {
        //cout << a << endl;
       // cout << b << endl;
        //cout << c << endl;
        
        if (a == to_string(q)){
            cout << "found" << endl;
            
       

           string blch = decp(b,p,q);
            infile.close();
            string** name = loadTrail(height, width);
            string str = blch;
            vector<int> vect;
            
            stringstream ss(str);
            
            int i;
            
            while (ss >> i)
            {
                vect.push_back(i);
                if (ss.peek() == ',')
                    ss.ignore();
            }
            string end = "";
            for (i=0; i< vect.size(); i = i+ 2){
                //cout << abs(vect.at(i))<<endl;
               // cout << abs(vect.at(i + 1))<<endl;
                int yy = abs(vect.at(i));
                int xx = abs(vect.at(i + 1));

                end = end + name[yy][xx];

                
        }
            cout << "The Output For This Block Is:" << endl;
            cout << endl << end << endl;
    }
}
}
int main () {
    

   // This is initial data to initilise blocktrail
    initNewFile(); //You do not have to initialise a new file everytime, it will overwrite previous data if you do
    
    //Test data,
    string testHash = "hello_user";
    cout << "Initial test hash of: " << testHash << endl;
    randInsert(testHash, 103, 109);
    
    // private strings default settings
    string str = "0123456789asdf";
    string privateKey = "xbvc";
    int p = 11;
    int q = 79;
    int finish = -1;
   
    //menu
    while (finish != 3){
        cout << "1. Add To Blockchain" << endl;
        cout << "2. View Message" << endl;
        cout << "3. Exit" << endl;

        cin >> finish;
        switch(finish){
    case (1):
                cout << "Insert p:" << endl;
                cin >> p;
                cout << "Insert q:" << endl;
                cin >> q;
                cout << "Insert Message (without spaces):" << endl;
                cin >> str;
                
                //insert into blockchain
                randInsert(str, p, q);
        break;
    case (2):
                cout << "Insert private key d:" << endl;
                cin >> p;
                cout << "Insert public key n:" << endl;
                cin >> q;
             reAssemble( p, q);
        break;
    }
    }
    
    //Debug Code will output below:
    char * dir = getcwd(NULL, 0); // Platform-dependent
    printf("Current dir: %s", dir);
    return 0;
}
