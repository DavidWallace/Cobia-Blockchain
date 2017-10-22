
//  main.cpp
//  RSA
//
//  Created by Sergiy on 06.06.17.

#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


bool isPrime(long int prime);
long int calculateE( long int t );
long int greatestCommonDivisor( long int e, long int t );
long int calculateD( long int e, long int t );
long int encrypt( long int i, long int e, long int n );
long int decrypt(long int i, long int d, long int n );

std::string enc(std::string block, long p, long q )
{
    long int n, t, e, d;

        long int encryptedText[100];
        memset(encryptedText, 0, sizeof(encryptedText));
        
        long int decryptedText[100];
        memset(decryptedText, 0, sizeof(decryptedText));
        
        bool flag;
        
        std::string msg;
        msg = block;
        
    
        n = p * q;
    // May be revelant to some
       // std::cout << "\nResult of computing n = p*q = " << n << std::endl;
        
        t = ( p - 1 ) * ( q - 1 );
       // std::cout << "Result of computing Euler's totient function:\t t = " << t << std::endl;
    
        e = calculateE( t );
        d = calculateD( e, t );
    
        //will be used down the line
       // std::cout << "\nRSA public key is (n = " << n << ", e = " << e << ")" << std::endl;
        
        std::cout << "RSA keys are (n = " << n << ", d = " << d << ")" << std::endl;
    
        
        // encryption
        
        for (long int i = 0; i < msg.length(); i++)
        {
            encryptedText[i] = encrypt( msg[i], e, n);
        }
        
        std::string end = "";
       // std::cout << "\nTHE ENCRYPTED MESSAGE IS:" << std::endl;
        std::string out = "1";
        for ( long int i = 0; i < msg.length(); i++ )
        {
            
            //std::cout << (char)encryptedText[i] << std::endl;
            out = out + "!" + std::to_string(encryptedText[i]);
        }
    
        // Outputs end result of encryption
       // std::cout << out << std::endl;

        
    
        
    return std::to_string(n) + " " + out;
        
    
    
}
std::string decp(std::string out, int d, int n) {
    std::string msg;

    long int encryptedText[100];
    memset(encryptedText, 0, sizeof(encryptedText));
    
    long int decryptedText[100];
    memset(decryptedText, 0, sizeof(decryptedText));
    
    std::stringstream ffc(out);
    std::string s;
    
    int ccounter = 0;
    long int encText[100];
    
    while (getline(ffc, s, '!')) {
        
        //std::cout << s << std::endl;
        encText[ccounter] =  std::stoi(s.c_str());
        ccounter++;
    }
    
    
    
    while (getline(ffc, s, '!')) {
        encText[ccounter] = std::stoi( s.c_str() );
        ccounter++;
        
    }
    
    msg = ccounter;
    for (long int i = 1; i < ccounter + 1; i++)
    {
        //std::cout << i << " " << encText[i] << std::endl;
        
        decryptedText[i] = decrypt(encText[i], d, n);
    }
    
 //   std::cout << "\n\nTHE DECRYPTED MESSAGE IS:" << std::endl;
    std::string end = "";
    for (long int i = 1; i <ccounter; i++)
    {
     //   printf( "%c", (char)decryptedText[i] );
        end = end + (char)decryptedText[i];

    }

    return end;
    
}


bool isPrime( long int prime)
{
    long int i, j;
    
    j = (long int)sqrt((long double)prime);
    
    for ( i = 2; i <= j; i++)
    {
        if ( prime % i == 0 )
        {
            return false;
        }
    }
    
    return true;
}

long int calculateE( long int t )
{
    // Выбирается целое число e ( 1 < e < t ) // взаимно простое со значением функции Эйлера (t)
    
    long int e;
    
    for ( e = 2; e < t; e++ )
    {
        if (greatestCommonDivisor( e, t ) == 1 )
        {
            return e;
        }
    }
    
    return -1;
}

long int greatestCommonDivisor( long int e, long int t )
{
    while ( e > 0 )
    {
        long int myTemp;
        
        myTemp = e;
        e = t % e;
        t = myTemp;
    }
    
    return t;
}

long int calculateD( long int e, long int t)
{
    // Вычисляется число d, мультипликативно обратное к числу e по модулю φ(n), то есть число, удовлетворяющее сравнению:
    //    d ⋅ e ≡ 1 (mod φ(n))
    
    long int d;
    long int k = 1;
    
    while ( 1 )
    {
        k = k + t;
        
        if ( k % e == 0)
        {
            d = (k / e);
            return d;
        }
    }
    
}


long int encrypt( long int i, long int e, long int n )
{
    long int current, result;
    
    current = i - 97;
    result = 1;
    
    for ( long int j = 0; j < e; j++ )
    {
        result = result * current;
        result = result % n;
    }
    
    return result;
}

long int decrypt(long int i, long int d, long int n)
{
    long int current, result;
    
    current = i;
    result = 1;
    
    for ( long int j = 0; j < d; j++ )
    {
        result = result * current;
        result = result % n;
    }
    
    return result + 97;
}

