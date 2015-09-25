//================================================================================================================
//================================================================================================================
//
//  main.cpp
//  CUNY_TECH_PREP
//
//  Created by Moustafa ElShaabiny on 9/22/15.
//  Copyright (c) 2015 Moustafa ElShaabiny. All rights reserved.
//
//  Coding Exercise:
//  1. Write a program in C++ or Java that tests whether any given string is a palindrome.
//  2. Write a program in C++ or Java that inputs a string and outputs the semi-palindromic number.
//
//  Algorithm: 1- Take in the input string of size n from user and convert it into a vector array.
//  2- Split this vector array into two smaller vector arrays. If n is even, both vectors are of size (n/2)
//  Otherwise, the first vector's size is (n/2) and the second is (n/2) +1.
//  3- I compare each element of vector 1 to it's corresponding one (in reverse order) in vector 2. If they
//  are different, I increment the global semi-palindromic number K, except for one case: for the middle
//  character for palindromic odd-n-characters strings
//    --     --   --    -- -- -- --             -- -- --  -- --  --  --   --
//  |  a  |  b |  c |       ...... |        | .....          |  c |  b |  a |
//    --     --   --    --   --   --            -- -- -- - --   --   --   --
//     |______|____|__________________compare_a__________________|____|____|
//            |____|__________________compare_b__________________|____|
//                 |__________________compare_c__________________|
//
//================================================================================================================
//================================================================================================================

#include <iostream>
#include <vector>

using namespace std;

int K = 0;

class splitVctr{
    
public:
    vector<char> str1, str2;
    void split(vector<char>);
};
//==========================================================================
//                          Main Auxiliary Function
// takes in a vector containing all input string characters (n)
// and populates two smaller vectors both of size (n/2), where n is even
// or in case n is odd (n/2) and (n/2)+1
//==========================================================================
void splitVctr::split(vector<char> my_vect){
    int j = 0;
    for (int i= 0; i<my_vect.size(); i++){
        if (i<int(my_vect.size()/2)) str1.push_back(my_vect[i]);
        else{
            str2.push_back(my_vect[i]);
            j++;
        }
    }
}

//==========================================================================
//                 Constant Identifier Computation Function
//  takes in two vectors and loops through the elements of the first
//  (from beginning to end) and compares it to that of the second
//  (from end to beginning). If any character in vect1 does not have
//  a parallel (palindromic) character in vect2 the constant identifier k
//  is incremented. Exception: for odd n, the middle may not have one
//  parallel to it, however the string could still be palindromic
//==========================================================================
int calc_k(vector<char> vec1, vector<char> vec2, vector<char> org_vec){
    int j = int(vec2.size()-1);
    // Empty strings and strings of length 1 cases = palindrome
    if (org_vec.size() == 0 || org_vec.size() == 1) {
        return K=0;
    }

    for (int i=0; i<vec2.size(); ++i){
        if (vec1[i] != vec2[j]){
            // Middle character for palindromic odd-n-characters strings
            if(( (org_vec.size() % 2)!= 0 && K==0 && i == vec1.size())){
                continue;
            }
            else K++;
        }
        --j;
    }
    return K;
}
//==========================================================================
//                              Test Function
//  tests the size of the string (not empty), the K identifier to make sure it
//  does not exceed n/2, and finally, based on K, it checks whether a given
//  1string is palindromic or not.
//==========================================================================
void test(const int x, const int y){
    cout<<"***************** Test *******************"<<'\n'
    <<"1- Input string size          = "<<y
    <<'\n'<<"2- Semi-palindromic number K  = "<<K
    <<'\n'<<"3- By definition, a string comprised of n characters can be at most n/2 semi-palindromic";
    if(x>y/2) cout<<"....checking.... Fail"<<endl;
    else cout<<" ....checking.... Good!"<<endl;
    if(x == 0) cout<<"4- Since K = 0, the input string is considered palindromic."<<endl;
    else cout<<"4- Since K!=0, the input string is not considered palindromic."<<endl;
    cout<<'\n'<<"************** End of Test ****************"<<endl;
    
}

vector<char> vect_char_me(string str){
    vector<char> vect_str(str.begin(),str.end());
    return vect_str;
}

int main() {
    string s;
    //=============================USER INTERFACE===============================
    cout<<"Welcome to my program to test whether a give string is a palindrome"
    <<'\n'<<"Please input a string for testing: "<<endl;
    cin>>s;
    
    cout<<"You entered: "<<s<<endl;
    
    cout<<"One moment while I test..."<<'\n'<<endl;
    //==========================================================================
    
    vector<char> vect_str = vect_char_me(s);
    splitVctr spl_vctr;
    spl_vctr.split(vect_str);
    cout<<endl;
    int k = calc_k(spl_vctr.str1, spl_vctr.str2, vect_str);
    
    test(k, int(vect_str.size()));
    return 0;
}
