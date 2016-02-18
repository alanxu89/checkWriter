#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string convertToWords(int number)
{
    const string thousands[4] = {"Thousand", "Million", "Billion", "Trillion"};
    const string tens[8]={"Twenty", "Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    const string ones[19]={"One", "Two", "Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
                           "Fifteen","Sixteen","Seventeen", "Eighteen","Nineteen"};

    vector<string> Words;
    string totalWords;

    if (number==0) Words.push_back("Zero");

    else if(number<0)
    {
        Words.push_back("Minus");
        Words.push_back(convertToWords(-number));
    }
    
   
    else if (number>=1000){
        
        vector<int> digit_thousands;
        while (number>0) {
            digit_thousands.push_back(number%1000);
            number/=1000;
        }
        int size=(int)digit_thousands.size();
        for (int i=size-1;i>0; i--) {
            if (digit_thousands[i]!=0) {
                Words.push_back(convertToWords(digit_thousands[i]));
                Words.push_back(thousands[i-1]);
            }
        }
        if (digit_thousands[0]!=0) Words.push_back(convertToWords(digit_thousands[0]));

    }
    
    
    else {
        int digit_hundreds=number/100;
        int reminder=number%100;
        int digit_tens;
        int digit_ones;
    
        if (digit_hundreds!=0){
            Words.push_back(ones[digit_hundreds-1]);
            Words.push_back("Hundred");
        }
    
        if (reminder>=20){
            digit_tens=reminder/10;
            digit_ones=reminder%10;
            Words.push_back(tens[digit_tens-2]);
            if (digit_ones!=0) Words.push_back(ones[digit_ones-1]);
        }
        else {
            digit_tens=0;
            digit_ones=reminder;
            if (digit_ones!=0) Words.push_back(ones[digit_ones-1]);
        }
    }
  

    int i;
    for (i=0;i<Words.size()-1;i++){
        totalWords.append(Words[i]+" ");
    }
    totalWords.append(Words[i]);

    return totalWords;
}


int main() {
    string  result= convertToWords(1000001);
    cout<<result<<endl;
    
    return 0;
}
