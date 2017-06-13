// FastaSplitter.cpp : Defines the entry point for the console application.
//
// compile using -std=c++11
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include<vector>
#include "FastaSplitter.h"
#include <iterator>
//#include boost::circular_buffer<int> cb 1024;


using namespace std;


//void add_to_fasta();

//vector < string, vector<char>> FastaFile;

void print(int words)
{
	std::cout << words << endl;
}
string noInputMessage = "FastaSplitter <file.fa>";


vector<char> Proteome;


//void 

//checkNewFasta()

int main(int argc, char * argv[])
{
	
	if( argc == 1)
	{
		std::cout << noInputMessage << endl;
	}







	//return 0;
	//string largeFasta = "C:/Users/DDell/Documents/Programming/Bioinformatics/proteome_analysis_c_elegans/bigdata/CElegans/c_elegans.PRJNA13758.WS254.protein.fa";
	string largeFasta = argv[1];
	std::ifstream testFile(largeFasta.c_str(), std::ios::binary);
//std::vector<char> points; for (char p; testFile>>p; ) points.push_back(p);

	//cout << points.size() << endl;
	
//	return 0;	
	std::vector<char> fileContents((std::istreambuf_iterator<char>(testFile)), std::istreambuf_iterator<char>());
	//td::cout << fileContents.size() << " " << std::endl;
	//STD::COUT << fileContents <<std::endl;
	
	//return 0;
	
	
//vector <char> fileContents =points;	
	int i = 0;
	std::cout << "Processing File" <<std::endl;
	while (i<fileContents.size())
	//for (int i = 0; i < 10000; ++i)
	{
		SingleFastaProtein tmp_fasta;
			
	//cout <<"Instantiation"<<endl;	
		if (fileContents[i] == '>')
		{
			++i;
				
			//std::cout << fileContents.getloc() " fileContents Location" << endl;	
			//string tmp_header = "";
			while (fileContents[i] != '\t'&& fileContents[i] != ' ')
			{
				//std::cout << fileContents[i];
				tmp_fasta.peptideName += fileContents[i];
				++i;
								
			}
		}
		
		while (fileContents[i] != '\n' && i < fileContents.size())
		{	
			++i;	
		}
		++i;

		
		while (fileContents[i] != '>' && i< fileContents.size())
		{
			//cout <<"Vector Number"<<i<<"out of " <<fileContents.size()<<endl;
			//std::cout << fileContents[i];	
			tmp_fasta.peptide.push_back (fileContents[i]);
			//cb.pushback(fileContents[i]);
			++i;
		
		}

		ofstream FastaOut;
		string fileopen = tmp_fasta.peptideName+".fasta";


		try {
			FastaOut.open(fileopen.c_str());
		}
		catch (runtime_error err) {
			std::cout << err.what() << std::endl;
		}
		FastaOut << '>' << tmp_fasta.peptideName << '\n';
		////std::cout << tmp_fasta.peptideName << std::endl;

		//std::cout << fileopen <<" has been opened!" << std::endl;
		int counter = 0;
		//std::cout << i << "out of " << fileContents.size()<< endl;
		for (auto j = tmp_fasta.peptide.begin();j != tmp_fasta.peptide.end(); ++j)
		{
			
			++counter;
			//std::cout << j;
			FastaOut << *j;
			//std::cout << tmp_fasta.peptide.size() <<" "<< counter << std::endl;
		}
		//std::cout << "Success"<< std::endl;
		FastaOut.close();
		
	}
   return 0;
}

