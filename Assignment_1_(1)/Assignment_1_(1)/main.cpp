//
//  main.cpp
//
//  学号1352959 姓名冯馨荷 作业号(1) 文件名Assignment_1
//  Created by fengxinhe on 14-3-26.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


void initialize_exclusion_set ( set<string>&, ifstream&);
void process_file ( map<string, int> &, const set<string> &,vector<string> &);
void display_word_dictionary ( const map<string, int>&, ofstream&);
void display_word_frequency ( const map<string, int>&,ofstream&);
void display_word_custom (const vector<string>&,ofstream&);

class word_length_compare {
public:
    bool operator()( const string &s1,const string &s2)
    {return s1.size() < s2.size();}
};


int main()
{
  //  ifstream in_file("C:\1_in_1.txt");                      //open the input file and judge
    //ifstream infile("C:\1_in_2.txt");
    //if (!in_file||!infile) {
       // cerr<<"error:can not open input file"<<endl;
       // return -1;
    //}
    
    
    //ofstream outfile("C:\1_out_1.txt.txt");                 //open the output file and judge
    //ofstream outfile2("C:\1_out_2.txt");
    //ofstream outfile3("C:\1_out_3.txt");
    //if (!outfile||!outfile2||!outfile3) {
       // cerr<<"error:can not open output file"<<endl;
    //}
    
   
    string word;
    
    //vector<string> text;
    vector < string > fileWord;
    
    while( cin>>word ){                                                   //read and store the text
        for(string::size_type i = 0; i < word.length(); ++i)                  //make 'A' to 'a'
            word[i] = tolower(word[i]);
        fileWord.push_back(word);
    }
    //cout<<fileWord[10]<<endl;
   
    
    basic_string <char>::size_type indexCh1a, indexCh1b;
    
    for (int ix=0; ix<=fileWord.size(); ++ix){
        
        indexCh1a = fileWord[ix].find ( "," );
        indexCh1b = fileWord[ix].find ( "." );
        
        if(fileWord[ix]==","||fileWord[ix]==".")                              //remove the ',' or '.'
            fileWord.erase(fileWord.begin()+ix );
        
        else if(indexCh1a != string::npos)
            fileWord[ix]=fileWord[ix].substr(0, fileWord[ix].length()-1);     //remove the ',' next to the word
                                                                              //as 'book,' -> 'book'
        else if(indexCh1b != string::npos)
            fileWord[ix]=fileWord[ix].substr(0,fileWord[ix].length()-1);      //remove the '.' next to the word
        }                                                                     //as 'dog.' -> 'dog'
    
    
    
    set<string> word_exclusion;
    initialize_exclusion_set(word_exclusion,infile);
    
   
    map<string, int> word_count;
    process_file(word_count, word_exclusion,fileWord);
    
    display_word_dictionary ( word_count, outfile);                          //display the words list as dictionary
    display_word_frequency ( word_count, outfile2);                          //display the words list as frequency
    
    int Temp;
    string str;
    vector<string> vstr;
    vector<int> vtemp;
    map<string, int>::const_iterator it = word_count.begin();
    
    for (int a = 0; a<word_count.size(); ++a) {
        str = it->first;
        vstr.push_back(str);
        Temp = it->second;
        vtemp.push_back(Temp);
        it++;
    }
    
    sort(vstr.begin(), vstr.end());
    stable_sort(vstr.begin(), vstr.end(), word_length_compare());
    
    display_word_custom(vstr,outfile3);
    
    
    return 0;
        }


void initialize_exclusion_set(set<string> &exs,ifstream &ifile)              //read the words shall be excluded
{
    static string _excluded_words[50];
    int cnt = 0;
    while (ifile) {
        for (int x=0; x<50; ++x) {
            ifile>>_excluded_words[x];
            ++cnt;
        }
    }
    exs.insert(_excluded_words,_excluded_words+cnt);
}

void process_file(map<string, int> &word_count, const set<string> &excluded_set,vector<string> &vec)
{
    string word;
    
    for (int y=0; y<=vec.size(); ++y) {
        if (excluded_set.count(vec[y]))
                continue;
        else {
                word=vec[y];
                word_count[word]++;
             }
        }
}

void display_word_dictionary ( const map<string, int> &word_map, ofstream &os)   //output words by dictionary order
{
    map<string, int>::const_iterator
                 iter = word_map.begin(),
                 end_it = word_map.end();
    while (iter !=end_it) {
        os<< iter->first  << " " << iter->second  <<endl;
        ++iter;
    }
    os << endl;
}



void display_word_frequency ( const map<string, int>&word_map,ofstream &os)     //output words by occurency times
{
    int iTemp;
    string istr;
    vector<string> vstr;
    vector<int> vtemp;
    map<string, int>::const_iterator it = word_map.begin();
    for (int a = 0; a<word_map.size(); ++a) {
        istr = it->first;
        vstr.push_back(istr);
        iTemp = it->second;
        vtemp.push_back(iTemp);
        it++;
    }
    
    multimap<int, string> newList;
    for (int z = 0; z<vstr.size(); ++z) {
        newList.insert(pair<int, string>(vtemp[z],vstr[z]));
    }
    
    multimap<int, string>::reverse_iterator t;
    for( t = newList.rbegin(); t != newList.rend(); ++t)                 //output the multimap in the reverse order
    {
        os<< t-> second.c_str() << " " << t->first <<endl;
    }
    os<< endl;
}


void display_word_custom(const vector<string>&vs,ofstream&os)            //output the words by custom order
{
    vector<string>::const_iterator H = vs.begin(),endH = vs.end();
    int cnt = 1;
    while (H != endH) {
        os << *H++ << (!(cnt++%5) ? '\n' : ' ');
    }
    os<<endl;
}











